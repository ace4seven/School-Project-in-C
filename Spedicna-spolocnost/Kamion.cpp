#include "Kamion.h"

Kamion::Kamion(int paKapacita, int paDen, int paMesiac, int paRok):
	kapacita_(paKapacita), aktualnyNaklad_(0), vylozeny_(false)
{
	prichodDoSkladu_ = new Datum(paDen, paMesiac, paRok);
	obsahPaliet_ = new structures::ArrayList<Paleta*>; // Velkost nakladneho priestoru na palety je dobrepdu dany
}

Kamion::~Kamion()
{
	Helper::vymazList(obsahPaliet_);
	delete prichodDoSkladu_;
}

structures::ArrayList<Paleta*>* Kamion::getObsahKamiona()
{
	return obsahPaliet_;
}

int Kamion::getKapacita()
{
	return kapacita_;
}

int Kamion::getAktualNaklad()
{
	return aktualnyNaklad_;
}

Datum * Kamion::getDatumPrichodu()
{
	return prichodDoSkladu_;
}

bool Kamion::getVylozeny()
{
	return vylozeny_;
}

void Kamion::setKamionVylozeny()
{
	vylozeny_ = true;
}

void Kamion::setAktNaklad(int aktnaklad)
{
	aktualnyNaklad_ = aktnaklad;
}

bool Kamion::nalozPaletu(Paleta * paPaleta)
{
	if (kapacita_ < aktualnyNaklad_ + paPaleta->getHmotnostPalety())
	{
		delete paPaleta;
		return false;
	}

	obsahPaliet_->add(paPaleta);
	aktualnyNaklad_ += paPaleta->getHmotnostPalety();

	return true;
}

void Kamion::odstranObsahKamionu()
{
	delete obsahPaliet_;
}
