#include "SuborIO.h"
#include "Firma.h"


SuborIO::SuborIO()
{
}


SuborIO::~SuborIO()
{
}

bool SuborIO::ulozDoSuboru(Firma *spedFirma)
{
	std::ofstream file;
	file.open("save.txt", ios::out | ios::trunc);
	file.clear();

	// ULOZENIE DATUMU -- DEN, MESIAC, ROK
	file << "DAT|" << spedFirma->getDnesnyDatum()->getDen() << "|" << spedFirma->getDnesnyDatum()->getMesiac() << "|" << spedFirma->getDnesnyDatum()->getRok() << "\n";

	// ULOZENIE FIREMNE UDAJE // POCET REG, VAHAPALIET, ROZVAZAME DNES
	file << "CMP" << "|" << spedFirma->getPocetRegionov() << "|" << spedFirma->getVahaNaskladnenychPaliet() << "|";
	int indexRozvazania = spedFirma->getDnesRozvazame() ? 1 : 0;
	file << indexRozvazania << "\n";

	// ULOZENIE VOZIDIEL -- EVC, NOSNOST, OPOTREB, DEN, MESIAC, ROK
	for each (Vozidlo *voz in *spedFirma->getVozidla())
	{
		file << "VOZ" << "|" << voz->getEvidC() << "|" << voz->getNosnost() << "|" << voz->getOpotrebenie() << "|" << voz->getDatumZaradenia()->getDen() << "|" << voz->getDatumZaradenia()->getMesiac() << "|" << voz->getDatumZaradenia()->getDen() << "\n";
	}

	while (spedFirma->getFrontVozNaOdpis()->size()) // SICE SA ZBAVIM FRONTU, ALE KED SA SUBOR ULOZI TAK HO ZNOVA KVOLI OTESTOVANIU NACITAM, TAKZE BUDE FRONT SPAT
	{
		file << "VOZ" << "|" << spedFirma->getFrontVozNaOdpis()->pop()->getEvidC() << "|" << spedFirma->getFrontVozNaOdpis()->pop()->getNosnost() << "|" << spedFirma->getFrontVozNaOdpis()->pop()->getOpotrebenie() << "|" << spedFirma->getFrontVozNaOdpis()->pop()->getDatumZaradenia()->getDen() << "|" << spedFirma->getFrontVozNaOdpis()->pop()->getDatumZaradenia()->getMesiac() << "|" << spedFirma->getFrontVozNaOdpis()->pop()->getDatumZaradenia()->getDen() << "\n";
	}

	// ULOZENIE DODAVATELOV, KAMIONOV A PALIET V KAMIONE
	for each (Dodavatel * dod in *spedFirma->getDodavatelia()) // DODAVATEL - NAZOV FIRMY, ADRESA, POCET VRAT PALIET
	{
		file << "DOD" << "|" << *dod->getObchodnyNazov() << "|" << *dod->getAdresa() << "|" << dod->getPocetVratPaliet() << "\n";

		for each (Kamion *kam in *dod->dodavatelKamiony()) // KAMION -> KAPACITA, VYLOZENY, DEN, MESIAC, ROK
		{
			int vylozeny = kam->getVylozeny() ? 1 : 0;
			file << "KAM" << "|" << kam->getKapacita() << "|" << vylozeny << "|" << kam->getDatumPrichodu()->getDen() << "|" << kam->getDatumPrichodu()->getMesiac() << "|" << kam->getDatumPrichodu()->getRok() << "\n";

			for each (Paleta *pal in *kam->getObsahKamiona()) // PALETA - HMOTNOST, REGION, PRIORITA, DATUM DORUCENIA
			{
				int priorita = pal->getPriorita() ? 1 : 0;
				file << "PAL" << "|" << pal->getHmotnostPalety() << "|" << pal->getIdRegion() << "|" << priorita;
				if (priorita == 1)
					file << "|" << pal->getDatumDorucenia()->getDen() << "|" << pal->getDatumDorucenia()->getMesiac() << "|" << pal->getDatumDorucenia()->getRok() << "\n";
				else
					file << "|" << "0|0|0 \n";
			}
		}
	}

	// PALETY SKLAD
	for each (Paleta *pal in *spedFirma->getSklad()) // DODAVATEL HMOTNOST, REGION, PRIORITA, (DEN, MESIAC, ROK)->sklad, (DEN,MESIAC,ROK)->dorucenie
	{
		int priorita = pal->getPriorita() ? 1 : 0;
		file << "SKLAD" << "|" << *pal->getDodvatelPalety()->getObchodnyNazov() << "|" << pal->getHmotnostPalety() << "|" << pal->getIdRegion() << "|" << priorita << "|" << pal->getDatumPrichoduDoSkladu()->getDen()
			<< "|" << pal->getDatumPrichoduDoSkladu()->getMesiac() << "|" << pal->getDatumPrichoduDoSkladu()->getRok();
		if (priorita == 1)
			file << "|" << pal->getDatumDorucenia()->getDen() << "|" << pal->getDatumDorucenia()->getMesiac() << "|" << pal->getDatumDorucenia()->getRok() << "\n";
		else
			file << "|" << "0|0|0 \n";
	}

	// PALETY NEROZTRIEDENE (1 TRIEDA) // NER - DODAVATEL NAZOV, HMOTNOST, REGION, PRIORITA,  (DEN, MESIAC, ROK)->sklad, (DEN,MESIAC,ROK)->dorucenie
	for each (Paleta *pal in *spedFirma->getNeroztriedenePalety())
	{
		int priorita = pal->getPriorita() ? 1 : 0;
		file << "NER" << "|" << *pal->getDodvatelPalety()->getObchodnyNazov() << "|" << pal->getHmotnostPalety() << "|" << pal->getIdRegion() << "|" << priorita << "|" << pal->getDatumPrichoduDoSkladu()->getDen()
			<< "|" << pal->getDatumPrichoduDoSkladu()->getMesiac() << "|" << pal->getDatumPrichoduDoSkladu()->getRok();
		if (priorita == 1)
			file << "|" << pal->getDatumDorucenia()->getDen() << "|" << pal->getDatumDorucenia()->getMesiac() << "|" << pal->getDatumDorucenia()->getRok() << "\n";
		else
			file << "|" << "0|0|0 \n";
	}

	// PALETY NEPREVZATE (1 TRIEDA AJ OSTATNE) // NEP - DODAVATEL, STAV NAZOV, HMOTNOST, REGION, PRIORITA, DATUM DORUCENIA DO SKLADU, DATUM DORUCENIA
	for each (Paleta *pal in *spedFirma->getNeroztriedenePalety())
	{
		int priorita = pal->getPriorita() ? 1 : 0;
		file << "NEP" << "|" << *pal->getDodvatelPalety()->getObchodnyNazov() << "|" << pal->getStavZasielky() << "|" << pal->getHmotnostPalety() << "|" << pal->getIdRegion() << "|" << priorita << "|" << pal->getDatumPrichoduDoSkladu()->getDen()
			<< "|" << pal->getDatumPrichoduDoSkladu()->getMesiac() << "|" << pal->getDatumPrichoduDoSkladu()->getRok();
		if (priorita == 1)
			file << "|" << pal->getDatumDorucenia()->getDen() << "|" << pal->getDatumDorucenia()->getMesiac() << "|" << pal->getDatumDorucenia()->getRok() << "\n";
		else
			file << "|" << "0|0|0 \n";
	}
	
	file.close();

	return true;
}

bool SuborIO::nacitajZoSuboru(Firma * spedFirma)
{
	string line;
	ifstream myfile("demo.txt");

	if (myfile.is_open())
	{
		spedFirma->vycistiCeluPamat();
		while (getline(myfile, line))
		{
			vector<string> x = split(line, '|');

			if (x[0] == "DAT")
				spedFirma->getDnesnyDatum()->setUpravDatum(atoi(x[1].c_str()), atoi(x[2].c_str()), atoi(x[3].c_str()));

			if (x[0] == "CMP") //POCET REG, VAHAPALIET, ROZVAZAME DNES
			{
				spedFirma->setPocetRegionov(atoi(x[1].c_str()));
				Helper::vymazList(spedFirma->getSkladPodlaRegionov());
				spedFirma->inicializujSkladPreRegiony();

				spedFirma->setVahaNaskladnenychPaliet(atoi(x[2].c_str()));
				if (atoi(x[3].c_str()) == 1)
					spedFirma->setDnesRozvazame(true);
			}

			if (x[0] == "VOZ") //--EVC, NOSNOST, OPOTREB, DEN, MESIAC, ROK
			{
				Vozidlo* voz = new Vozidlo(x[1], atoi(x[2].c_str()), new Datum(atoi(x[4].c_str()), atoi(x[5].c_str()), atoi(x[6].c_str())));
				voz->setNavysOpotrebenie(atoi(x[3].c_str()));
				spedFirma->pridajVozidlo(voz);
			}

			while (x[0] == "DOD") // - NAZOV FIRMY, ADRESA, POCET VRAT PALIET
			{
				Dodavatel *dod = new Dodavatel(x[1], x[2]);
				dod->setPocetVratenychPaliet(atoi(x[3].c_str()));
				getline(myfile, line);
				x = split(line, '|');

				while (x[0] == "KAM") // KAMION -> KAPACITA, VYLOZENY, DEN, MESIAC, ROK
				{
					Kamion *kam = new Kamion(atoi(x[1].c_str()), atoi(x[3].c_str()), atoi(x[4].c_str()), atoi(x[5].c_str()));
					if (atoi(x[2].c_str()) == 1)
						kam->setKamionVylozeny();

					getline(myfile, line);
					x = split(line, '|');

					while (x[0] == "PAL") //  PALETA - HMOTNOST, REGION, PRIORITA, DEN, MESIAC, ROK
					{
						Paleta *pal = new Paleta(atoi(x[1].c_str()), atoi(x[2].c_str()));
						if (atoi(x[3].c_str()) == 1)
						{
							pal->setPrioritnaPaleta();
							pal->setDatumDorucenia(new Datum(atoi(x[4].c_str()), atoi(x[5].c_str()), atoi(x[6].c_str())));
						}
						
						kam->nalozPaletu(pal);

						getline(myfile, line);
						x = split(line, '|');
					}
					dod->zaradKamionDoPrevadzky(kam);
				}
				spedFirma->pridajDodavatela(dod);
			}

			while (x[0] == "SKLAD" || x[0] == "NER" || x[0] == "NEP") // DODAVATEL HMOTNOST, REGION, PRIORITA, (DEN, MESIAC, ROK)->sklad, (DEN,MESIAC,ROK)->dorucenie
			{
				Paleta *pal = new Paleta(atoi(x[2].c_str()), atoi(x[3].c_str()));
				Dodavatel *dod = spedFirma->getDodavatelByFirma(x[1]);
				if (dod != nullptr)
				{
					pal->setDodavatelPalery(dod);

					if (atoi(x[4].c_str()) == 1)
						pal->setPrioritnaPaleta();

					pal->setDatumPrichoduDoSkladu(new Datum(atoi(x[5].c_str()), atoi(x[6].c_str()), atoi(x[7].c_str())));
					pal->setDatumDorucenia(new Datum(atoi(x[8].c_str()), atoi(x[9].c_str()), atoi(x[10].c_str())));
					if (x[0] == "SKLAD")
						spedFirma->setPridajPaletuDoSkladu(pal);
					else if (x[0] == "NER")
						spedFirma->setPridajNeroztriedPaletu(pal);
					else
						spedFirma->setPridajNeprevzatuPaletu(pal);

					getline(myfile, line);
					x = split(line, '|');
				}
				else
				{
					delete pal;
					delete dod;
					getline(myfile, line);
					x = split(line, '|');
				}
			}
		}
		myfile.close();
		return true;
	}

	return false;
}

vector<string> SuborIO::split(const string & text, char sep)
{
	vector<string> tokens;
	size_t start = 0, end = 0;
	while ((end = text.find(sep, start)) != string::npos) {
		tokens.push_back(text.substr(start, end - start));
		start = end + 1;
	}
	tokens.push_back(text.substr(start));
	return tokens;
}
