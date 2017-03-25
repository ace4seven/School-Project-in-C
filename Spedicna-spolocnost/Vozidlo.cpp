#include "Vozidlo.h"



Vozidlo::Vozidlo(string evidCislo, int nosnost, Datum *datumZaradenia):
	evidCislo_(evidCislo), nosnost_(nosnost), aktualneNalozenie_(0), regionRoznaska_(0), cakajuceNaOdpis_(false), opotrebenie_(0)
{
	datumZaradenia_ = datumZaradenia;
	paletyVoVozidle_ = new ArrayList<Paleta *>();
}


Vozidlo::~Vozidlo()
{
	delete datumZaradenia_;
	Helper::vymazList(paletyVoVozidle_);
}

void Vozidlo::vypisParametre()
{
	cout << "Vozidlo - SPZ: " << evidCislo_ << ". Nosnost: " << nosnost_ << ". Opotrebenie: " << opotrebenie_ << ". " << endl;
}

Datum * Vozidlo::getDatumZaradenia()
{
	return datumZaradenia_;
}

int Vozidlo::getNosnost()
{
	return this->nosnost_;
}

int Vozidlo::getAktualneNalozenie()
{
	return aktualneNalozenie_;
}

int Vozidlo::getOpotrebenie()
{
	return opotrebenie_;
}

int Vozidlo::getIdRegionu()
{
	return regionRoznaska_;
}

ArrayList<Paleta*>* Vozidlo::getNalozenePalety()
{
	return paletyVoVozidle_;
}

string Vozidlo::getEvidC()
{
	return evidCislo_;
}

bool Vozidlo::getCakaNaOdpis()
{
	return cakajuceNaOdpis_;
}

void Vozidlo::nalozPaletuDoVozidla(Paleta * paPaleta)
{
	paletyVoVozidle_->add(paPaleta);
	aktualneNalozenie_ += paPaleta->getHmotnostPalety();
}

void Vozidlo::setRegionRoznasania(int paRegionId)
{
	regionRoznaska_ = paRegionId;
}

void Vozidlo::setNavysOpotrebenie(int paOpotrebenie)
{
	opotrebenie_ += paOpotrebenie;
}

void Vozidlo::setNastavNaOdpis()
{
	cakajuceNaOdpis_ = true;
}

void Vozidlo::setAktualneNalozenie(int paNalozenie)
{
	aktualneNalozenie_ = paNalozenie;
}

