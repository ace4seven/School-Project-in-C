#include "Firma.h"



Firma::Firma():
	pocetRegionov_(5)
{
	initAplikaciu();
	dnesnyDatum_ = new Datum(1, 1, 2017);
}

Firma::Firma(int paDen, int paMesiac, int paRok, int paPocetRegionov):
	pocetRegionov_(paPocetRegionov)
{
	initAplikaciu();
	dnesnyDatum_ = new Datum(paDen, paMesiac, paRok);
}

void Firma::initAplikaciu()
{
	vozidla_ = new ArrayList<Vozidlo *>();
	dodavatelia_ = new ArrayList<Dodavatel *>();
	inicializujSkladPreRegiony();
	vozidlaPripraveneNaStart_ = new Heap<Vozidlo *>;
	neprevzatePalety_ = new LinkedList<Paleta *>;
	vahaNaskladnenychPaliet_ = 0;
	kapacitaVozidiel_ = 0;
	dnesRozvazame_ = false;
	sklad_ = new ArrayList<Paleta *>();
	neroztriedenePalety_ = new ArrayList<Paleta *>();
	frontNaOdpis_ = new ExplicitQueue<Vozidlo *>();

}


Firma::~Firma()
{
	delete dnesnyDatum_;
	Helper::vymazList(sklad_);
	Helper::vymazList(vozidla_);
	Helper::vymazList(dodavatelia_);
	Helper::vymazList(uskladnenePodlaRegionov_);
	Helper::vymazList(neprevzatePalety_);
	Helper::vymazHeap(vozidlaPripraveneNaStart_);
	Helper::vymazList(neroztriedenePalety_);

	while (frontNaOdpis_->size())
		delete frontNaOdpis_->pop();
	delete frontNaOdpis_;
}

void Firma::tik()
{
	cout << endl;
	cout << "Dnes mame: " << getDnesnyDatum()->vratRetazec() << endl;
	vypisVozidlaPodlaDatEv();
	vypisDodavatelov();
	ohlaseniePrichoduKamionov();
	skontrolujPrichodyKamionov();
	if (dnesRozvazame_)
	{
		roztriedUskladnenePaletyDoRegionov();
		nalozVozidlaAPripravNaVyjazd();
		prevzatiePalietZakaznikmi();
	}

	vypisPalietVCentralnomSklade();
	vyhladanieDodavatelaNajviacNepPaliet();
	vypisPaliet1TriedyNezrealizovane();
	
}

void Firma::pridajVozidlo(Vozidlo *paVozidlo)
{
	if (paVozidlo)
	{
		vozidla_->add(paVozidlo);
		kapacitaVozidiel_ += paVozidlo->getNosnost();
	}
}

void Firma::vypisVozidlaPodlaDatEv()
{
	cout << endl << ">> SKLAD EVIDUJE NASLEDUJUCE VOZIDLA SCHOPNE PREVADZKY: " << endl << endl;

	Heap<Vozidlo*> *pFront = new Heap<Vozidlo *>();

	for each (Vozidlo*  vozidlo in *vozidla_)
		pFront->push(Helper::vypocitajPriorituDatumu(vozidlo->getDatumZaradenia()), vozidlo);

	while (pFront->size() > 0)
		pFront->pop()->vypisParametre();

	delete pFront;
}

void Firma::skontrolujPrichodyKamionov() // O(n^2)
{
	cout << endl << ">> DNES EVIDUJEME PRICHODY TYCHTO KAMIONOV: " << endl << endl;
	
	int pocetPrichodov = 0;
	int maxNosnostVozidiel = getMaxHmotnostVozidiel(vozidla_);
	ExplicitStack<Kamion*> *kamionyNaVyradenie = new ExplicitStack<Kamion*>();

	if (sklad_->size() > 0)
		dnesRozvazame_ = true;

	for each (Dodavatel * dodavatel in *dodavatelia_)
	{
		for each (Kamion *kamion in *dodavatel->dodavatelKamiony())
		{
			dnesRozvazame_ = true;
			if (*kamion->getDatumPrichodu() == *dnesnyDatum_ && !kamion->getVylozeny())
			{
				pocetPrichodov++;
				vylozObsahKamionuDoSkladu(kamion, maxNosnostVozidiel, dodavatel);
				cout << "Dnes evidujeme kamion od dodavatela: " << *dodavatel->getObchodnyNazov() << endl;
				kamion->setKamionVylozeny();
			}

			if (*kamion->getDatumPrichodu() < *this->dnesnyDatum_)
			{
				kamionyNaVyradenie->push(kamion);
			}
		}

		while (kamionyNaVyradenie->size())
		{
			int index = dodavatel->dodavatelKamiony()->getIndexOf(kamionyNaVyradenie->pop());
			delete dodavatel->dodavatelKamiony()->removeAt(index);
		}
	}

	delete kamionyNaVyradenie;

	if (pocetPrichodov == 0)
		cout << "Dnes neevidujeme ziaden prichod" << endl;

	cout << endl;
}

void Firma::pripravaARozvoz()
{
	if (dnesRozvazame_)
	{
		roztriedUskladnenePaletyDoRegionov();
		nalozVozidlaAPripravNaVyjazd();
		prevzatiePalietZakaznikmi();
	}
	else
		cout << "Dnes NIEJE co rozvazat";

	dnesRozvazame_ = false;
}

void Firma::pridajDodavatela(string paObchodneMeno, string adresa)
{
	Dodavatel *dodavatel = new Dodavatel(paObchodneMeno, adresa);

	if (unikatnyDodavatel(dodavatel->getObchodnyNazov()))
		if (dodavatelia_->size() == 0)
			dodavatelia_->add(dodavatel);
		else
			pridajDodavatelaAbecedne(*dodavatel);
	else
	{
		cout << "Dodavatel: " << *dodavatel->getObchodnyNazov() << " je uz v systeme evidovany, nieje mozne ho evidovat znova !" << endl;
		delete dodavatel;
	}
}

void Firma::pridajDodavatela(Dodavatel * paDodavatel)
{
	if (unikatnyDodavatel(paDodavatel->getObchodnyNazov()))
		if (dodavatelia_->size() == 0)
			dodavatelia_->add(paDodavatel);
		else
			pridajDodavatelaAbecedne(*paDodavatel);
	else
	{
		cout << "Dodavatel: " << *paDodavatel->getObchodnyNazov() << " je uz v systeme evidovany, nieje mozne ho evidovat znova !" << endl;
	}
}

void Firma::pridajDodavatelov(ArrayList<Dodavatel*> *paDodavatelia)
{
	for each (Dodavatel *dod in *paDodavatelia)
		dodavatelia_->add(dod);
}

void Firma::vypisDodavatelov()
{
	cout << endl << ">> NASI DODAVATELIA: " << endl << endl;

	int index = 1;
	int pocetD = 0;
	for each (Dodavatel *tempD in *dodavatelia_)
	{
		cout << index << ". " << "Obcnodny nazov: " << *tempD->getObchodnyNazov() << ". Sidlo: " << *tempD->getAdresa() << endl;
		index++;
		pocetD++;
	}

	if (pocetD == 0)
		cout << "System neeviduje ziadnych dodavatelov" << endl;
}

void Firma::ohlaseniePrichoduKamionov() // O(n)
{
	cout << endl << ">> OHLASENIE PRICHODU KAMIONOV: " << endl << endl;

	for each ( Dodavatel *dod in *dodavatelia_)
		dod->ohlaseniePrichoduKamionov();
}

void Firma::posunNaDalsiDen()
{
	dnesnyDatum_->posunOJedenDen();

	ExplicitStack<Paleta *> *paletyVon = new ExplicitStack<Paleta*>();

	for each (Paleta *pal in *neroztriedenePalety_)
	{
		if (pal->getPriorita() && *pal->getDatumDorucenia() == *dnesnyDatum_)
		{
			sklad_->add(pal);
			vahaNaskladnenychPaliet_ += pal->getHmotnostPalety();
			paletyVon->push(pal);
		}
	}

	while (paletyVon->size())
	{
		int index = neroztriedenePalety_->getIndexOf(paletyVon->pop());
		neroztriedenePalety_->removeAt(index);
	}

	delete paletyVon;
}

void Firma::vycistiCeluPamat()
{
	Helper::vycistiList(sklad_);
	Helper::vycistiList(vozidla_);
	Helper::vycistiList(dodavatelia_);
	Helper::vycistiList(neprevzatePalety_);
	Helper::vycistiHeap(vozidlaPripraveneNaStart_);
	Helper::vycistiList(uskladnenePodlaRegionov_);

	for each (Paleta * pal in *neroztriedenePalety_)
		delete pal;
	neroztriedenePalety_->clear();

	while (frontNaOdpis_->size())
		delete frontNaOdpis_->pop();
	frontNaOdpis_->clear();
}

Datum * Firma::getDnesnyDatum()
{
	return this->dnesnyDatum_;
}

ArrayList<Paleta*>* Firma::getSklad()
{
	return sklad_;
}

ExplicitQueue<Vozidlo*> *Firma::getFrontVozNaOdpis()
{
	return frontNaOdpis_;
}

ArrayList<Dodavatel*>* Firma::getDodavatelia()
{
	return dodavatelia_;
}

ArrayList<Paleta*>* Firma::getNeroztriedenePalety()
{
	return neroztriedenePalety_;
}

LinkedList<Paleta*>* Firma::getNeprevzatePalety()
{
	return neprevzatePalety_;
}

Dodavatel * Firma::getDodavatelByFirma(string nazovFirmy)
{
	for each (Dodavatel *dodavatel in *dodavatelia_)
		if (nazovFirmy == *dodavatel->getObchodnyNazov())
			return dodavatel;

	return nullptr;
}

void Firma::setPridajPaletuDoSkladu(Paleta * pal)
{
	sklad_->add(pal);
}

void Firma::setPridajNeroztriedPaletu(Paleta * pal)
{
	neroztriedenePalety_->add(pal);
}

void Firma::setPridajNeprevzatuPaletu(Paleta * pal)
{
	neprevzatePalety_->add(pal);
}

void Firma::setPocetRegionov(int paPocet)
{
	pocetRegionov_ = paPocet;
}

void Firma::setVahaNaskladnenychPaliet(int paVaha)
{
	vahaNaskladnenychPaliet_ = paVaha;
}

void Firma::setKapacitaVozidiel(int paKapacita)
{
	kapacitaVozidiel_ = paKapacita;
}

void Firma::setDnesRozvazame(bool paRozvazame)
{
	dnesRozvazame_ = paRozvazame;
}

ArrayList<Vozidlo*>* Firma::getVozidla()
{
	return vozidla_;
}

int Firma::getPocetRegionov()
{
	return this->pocetRegionov_;
}

int Firma::getVahaNaskladnenychPaliet()
{
	return vahaNaskladnenychPaliet_;
}

int Firma::getKapacitaVozidiel()
{
	return kapacitaVozidiel_;
}

bool Firma::getDnesRozvazame()
{
	return dnesRozvazame_;
}

ArrayList<Region*>* Firma::getSkladPodlaRegionov()
{
	return uskladnenePodlaRegionov_;
}

bool Firma::unikatnyDodavatel(const string * paAdresa)
{
	if (dodavatelia_->size() == 0)
		return true;

	for each (Dodavatel *tempD in *dodavatelia_)
		if (*tempD->getObchodnyNazov() == *paAdresa)
			return false;

	return true;
}

bool Firma::pridajDodavatelaAbecedne(Dodavatel & dodavatel)
{
	int index = 0;
	string novyDodavatel = *dodavatel.getObchodnyNazov();
	char novePismeno = novyDodavatel[0];
	bool nasiel = false;

	for each (Dodavatel *dod in *dodavatelia_)
	{
		string aktuDodavatel = *dod->getObchodnyNazov();
		char aktPismeno = aktuDodavatel[0];
		if (novePismeno < aktPismeno)
		{
			dodavatelia_->insert(&dodavatel, index);
			nasiel = true;
			break;
		}
		index++;
	}

	if (!nasiel)
		dodavatelia_->insert(&dodavatel, index);

	return nasiel;
}

void Firma::vylozObsahKamionuDoSkladu(Kamion * kamion, int paMaxNosnost, Dodavatel *paDodavatel)
{
	if (kamion)
	{
		for each (Paleta * paleta in *kamion->getObsahKamiona())
		{
			if (paleta->getHmotnostPalety() > paMaxNosnost) // Pokial bude nosnost palety vacsia ako maximalna nosnost vozidla, tak ju nevylozi.
			{
				delete paleta;
				continue;
			}

			// Datum dorucenia v tomto pripade sa tyka len prioritnych paliet.
			if (paleta->getPriorita() && (*paleta->getDatumDorucenia() < *dnesnyDatum_ || *paleta->getDatumDorucenia() == *dnesnyDatum_) ) // POKIAL DATUM DORUCENIA NIEJE NULL // ak tam je datum, jedna sa o prioritnu zasielku
			{
				delete paleta;
				continue;
			}

			paleta->setPrioritaPrichoduDoSkladu(dnesnyDatum_);
			paleta->setDodavatelPalery(paDodavatel);
			paleta->setDatumPrichoduDoSkladu(new Datum(dnesnyDatum_->getDen(), dnesnyDatum_->getMesiac(), dnesnyDatum_->getRok()));

			if (paleta->getPriorita() && *paleta->getDatumDorucenia() > *dnesnyDatum_)
				neroztriedenePalety_->add(paleta);
			else
			{
				sklad_->add(paleta);
				vahaNaskladnenychPaliet_ += paleta->getHmotnostPalety();
			}
		}

		kamion->getObsahKamiona()->clear();
	}
}

void Firma::roztriedUskladnenePaletyDoRegionov()
{
	if (kapacitaVozidiel_ > vahaNaskladnenychPaliet_)
	{
		for each (Paleta *pal in *sklad_)
			(*uskladnenePodlaRegionov_)[pal->getIdRegion() - 1]->pridajPaletuNaSklad(pal,2);

		sklad_->clear();
	}
	else
	{
		for each (Paleta *pal in *sklad_)
			(*uskladnenePodlaRegionov_)[pal->getIdRegion() - 1]->pridajPaletuNaSklad(pal, 1);

		sklad_->clear();
	}
}

void Firma::nalozVozidlaAPripravNaVyjazd()
{
	cout << endl << ">> PRAVE PREBIEHA NAKLAD PALIET DO VOZIDIEL: " << endl << endl;

	// 1. Umiestnit vozidla do prioritneho frontu podla opotrebovania.
	zoradenieVozidielPodlaOpotrebenia();

	bool mamVozidlaKDispo = true;
	Vozidlo *voz = nullptr;

	for each (Region * reg in *uskladnenePodlaRegionov_)
	{
		while (reg->getUskladnenePalety()->size())
		{
			if (vozidlaPripraveneNaStart_->size())
			{
				if (voz == nullptr || voz->getIdRegionu() != reg->getIdRegionu())
					voz = vozidlaPripraveneNaStart_->pop();

				if (voz->getIdRegionu() == 0)
					voz->setRegionRoznasania(reg->getIdRegionu());

				if (voz->getNosnost() >= voz->getAktualneNalozenie() + reg->getUskladnenePalety()->peek()->getHmotnostPalety())
				{
					cout << "Vozidlo: " << voz->getEvidC() << " naklada PALETU - ";
					if (reg->getUskladnenePalety()->peek()->getPriorita())
						cout << "1-TRIEDY ";
					cout << reg->getUskladnenePalety()->peek()->getHmotnostPalety() << " kg -> REGION: " << reg->getIdRegionu() << endl;
					voz->nalozPaletuDoVozidla(reg->getUskladnenePalety()->pop());
				}
				else
				{
					if (vozidlaPripraveneNaStart_->size())
						voz = nullptr;
					else
						mamVozidlaKDispo = false;
				}
			}
			else
				mamVozidlaKDispo = false;

			if (!mamVozidlaKDispo)
			{
				if (reg->getUskladnenePalety()->peek()->getPriorita())
				{
					Paleta * paleta = reg->getUskladnenePalety()->pop();
					cout << "!! PALETA " << paleta->getHmotnostPalety() << " JE NEZREALIZOVANA Z DOVODU KAPACIT !" << endl;
					paleta->setStavZasielky(NEZREALIZOVANA);
					paleta->getDodvatelPalety()->navysOJedenVratPalety();
					neprevzatePalety_->add(paleta);
				}
				else
					sklad_->add(reg->getUskladnenePalety()->pop());
			}
		}

		reg->getUskladnenePalety()->clear();
	}
	vozidlaPripraveneNaStart_->clear();
}

void Firma::prevzatiePalietZakaznikmi()
{
	cout << endl << ">> VYSLEDKY ROZNASKY " << endl;

	for each (Vozidlo * voz in *vozidla_)
	{
		if (voz->getIdRegionu() == 0)
			continue;

		cout << endl << "Vozidlo: " << voz->getEvidC() << " - " << endl;
		if (voz->getIdRegionu() != 0)
		{

			for each (Paleta *pal in *voz->getNalozenePalety())
			{
				cout << "Paleta " << pal->getHmotnostPalety() << " kg ";

				if (Helper::odmietnemZasielku())
				{
					pal->setStavZasielky(NEPREVZATA);
					pal->getDodvatelPalety()->navysOJedenVratPalety();
					neprevzatePalety_->add(pal);
					cout << "NEPREVZATA!" << endl;
					vahaNaskladnenychPaliet_ -= pal->getHmotnostPalety();
				}
				else
				{
					pal->setStavZasielky(PREVZATA);
					cout << "PREVZATA!" << endl;
					vahaNaskladnenychPaliet_ -= pal->getHmotnostPalety();
					delete pal;
				}
			}
		}
		voz->setNavysOpotrebenie(voz->getIdRegionu());
		voz->setAktualneNalozenie(0);

		if (voz->getOpotrebenie() > 90)
		{
			kapacitaVozidiel_ -= voz->getNosnost();
			voz->setNastavNaOdpis();
			frontNaOdpis_->push(voz);
		}

		voz->setRegionRoznasania(0);
		voz->getNalozenePalety()->clear();
	}
}

void Firma::vyradenieVozidiel()
{
	while (frontNaOdpis_->size())
		if (vozidla_->tryRemove(frontNaOdpis_->peek()))
			delete frontNaOdpis_->pop();
}

void Firma::vypisPalietVCentralnomSklade()
{
	cout << endl << ">> PALETY KTORE ZOSTALI V SKLADE: " << endl << endl;

	for each (Paleta *pal in *neroztriedenePalety_)
	{
		cout << "Paleta 1.trieda | Uskladnena: " << pal->getDatumPrichoduDoSkladu()->vratRetazec();
		cout << " | Datum odovzdania: " << pal->getDatumDorucenia()->vratRetazec();
		cout << " | Vaha: " << pal->getHmotnostPalety() << " kg" << " | Dodavatel: " << *pal->getDodvatelPalety()->getObchodnyNazov() << endl;
	}

	for each (Paleta * pal in *sklad_)
	{
		if (pal->getStavZasielky() == PENDING)
		{
			cout << "Paleta uskladnena: " << pal->getDatumPrichoduDoSkladu()->vratRetazec();
			if (pal->getPriorita())
				cout << " | 1. trieda | Datum odovzdania: " << pal->getDatumDorucenia()->vratRetazec();
			cout << " | Vaha: " << pal->getHmotnostPalety() << " kg" << " | Dodavatel: " << *pal->getDodvatelPalety()->getObchodnyNazov() << endl;
		}
	}
}

void Firma::vyhladanieDodavatelaNajviacNepPaliet()
{
	cout << endl << ">> DODAVATEL S NAJVACSIM POCTOM VRATENYCH PALIET:  " << endl << endl;
	Heap<Dodavatel *> *dod = new Heap<Dodavatel *>();

	for each (Dodavatel *d in *dodavatelia_)
	{
		if (d->getPocetVratPaliet() > 0)
			dod->push(d->getPocetVratPaliet(), d);
	}

	if (dod->size())
	{
		cout << *dod->peek()->getObchodnyNazov() << ". VRATENE: " << dod->peek()->getPocetVratPaliet() << endl;
		dod->clear();
	}
	else
		cout << "Momentalne system neeviduje ziadne vratene zasielky" << endl;

	delete dod;




}

void Firma::vypisPaliet1TriedyNezrealizovane()
{
	cout << endl << ">> TIETO PALETY 1 TRIEDY NEBOLI ZREALIZOVANE:  " << endl << endl;

	for each (Paleta *pal in *neprevzatePalety_)
		if (pal->getPriorita())
			cout << "PALETA s prichodom do CS: " << pal->getDatumPrichoduDoSkladu()->vratRetazec() << " | datum dorucenia: " << pal->getDatumDorucenia()->vratRetazec() << " | hmotnost: " << pal->getHmotnostPalety() << " | dodavatel: " << *pal->getDodvatelPalety()->getObchodnyNazov() << endl;
}

void Firma::inicializujSkladPreRegiony()
{
	uskladnenePodlaRegionov_ = new ArrayList<Region *>;
	for (int i = 0; i < pocetRegionov_; i++)
	{
		int index = i + 1;
		uskladnenePodlaRegionov_->add(new Region(index));
	}
}

void Firma::vypisPeknuUvodnuObrazovku()
{
	cout << " <><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>" << endl;
	cout << " ========================================================================" << endl;
	cout << " |  FRI SPEDICNA FIRMA - rozvoz do vasich regionov, spolahlivo a rychlo |" << endl;
	cout << " ========================================================================" << endl;
	cout << " ************************************************************************" << endl;
	cout << " ----------> DATUM: " << getDnesnyDatum()->vratRetazec() << endl << endl;
}

int Firma::getMaxHmotnostVozidiel(ArrayList<Vozidlo*> * paVozidlo)
{
	int max = 0;
	if (paVozidlo)
	{
		for each (Vozidlo *voz in *paVozidlo)
			if (voz->getNosnost() > max)
				max = voz->getNosnost();
	}

	return max;
}

void Firma::zoradenieVozidielPodlaOpotrebenia()
{
	for each (Vozidlo * voz in * vozidla_)
		if (!voz->getCakaNaOdpis())
			vozidlaPripraveneNaStart_->push(voz->getOpotrebenie(), voz);
}