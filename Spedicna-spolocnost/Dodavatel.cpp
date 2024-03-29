#include "Dodavatel.h"



Dodavatel::Dodavatel(string paObNazov, string paAdresa):
	ob_nazov_(paObNazov), adresa_(paAdresa), vratenePalety_(0)
{
	kamiony_ = new ArrayList<Kamion *>();
}


Dodavatel::~Dodavatel()
{
	Helper::vymazList(kamiony_);
}

void Dodavatel::zaradKamionDoPrevadzky(Kamion * paKamion)
{
	kamiony_->add(paKamion);
}

void Dodavatel::zaradKamionyDoPrevadzky(ArrayList<Kamion*>* paKamiony)
{
	if (kamiony_ != NULL)
		Helper::vymazList(kamiony_);

	kamiony_ = paKamiony;
}

ArrayList<Kamion *> * Dodavatel::dodavatelKamiony()
{
	return kamiony_;
}

void Dodavatel::ohlaseniePrichoduKamionov()
{
	cout << "Dodavatel: " << ob_nazov_ << endl << endl;

	int index = 1;
	for each (Kamion *kamion in *kamiony_)
	{
		cout << " >> kamion: " << index << " : " << kamion->getDatumPrichodu()->vratRetazec() << endl;
		index++;

		for each (Paleta *pal in *kamion->getObsahKamiona())
		{
			if (pal->getPriorita())
				cout << "   -> Paleta 1-trieda: " << pal->getHmotnostPalety() << " kg | Region: " << pal->getIdRegion() << " | Datum dorucenia: " << pal->getDatumDorucenia()->vratRetazec() << endl;
			else
				cout << "   -> Paleta: " << pal->getHmotnostPalety() << " kg | Region: " << pal->getIdRegion() << endl;
		}

	}

	cout << endl;
}

const string * Dodavatel::getObchodnyNazov()
{
	return &ob_nazov_;
}

const string * Dodavatel::getAdresa()
{
	return &adresa_;
}

int Dodavatel::getPocetVratPaliet()
{
	return vratenePalety_;
}

void Dodavatel::navysOJedenVratPalety()
{
	vratenePalety_ += 1;
}

void Dodavatel::setPocetVratenychPaliet(int pocet)
{
	vratenePalety_ = pocet;
}
