#include "Paleta.h"


Paleta::Paleta(int pHmotnost, int paIdRegion):
	hmotnost_(pHmotnost), idRegion_(paIdRegion), stav(PENDING), priorita_(false)
{
	datumDorucenia_ = new Datum();
	datumPrichoduDoSkladu_ = nullptr;
}

Paleta::Paleta(int pHmotnost, int paIdRegion, int paDen, int paMesiac, int paRok):
	hmotnost_(pHmotnost), idRegion_(paIdRegion), stav(PENDING), priorita_(true)
{
	datumDorucenia_ = new Datum(paDen, paMesiac, paRok);
	datumPrichoduDoSkladu_ = nullptr;
}

Paleta::~Paleta()
{
	delete datumDorucenia_;
	delete datumPrichoduDoSkladu_;
	dodavatelPalety_ = nullptr;
}

int Paleta::getIdRegion()
{
	return idRegion_;
}

int Paleta::getHmotnostPalety()
{
	return this->hmotnost_;
}

Datum * Paleta::getDatumDorucenia()
{
	return datumDorucenia_;
}

bool Paleta::getPriorita()
{
	return priorita_;
}

int Paleta::getPrioritaPrichoduDoSkladu()
{
	return prioritaPrichoduDoSkladu_;
}

StavZasielky Paleta::getStavZasielky()
{
	return stav;
}

Datum * Paleta::getDatumPrichoduDoSkladu()
{
	return datumPrichoduDoSkladu_;
}

Dodavatel * Paleta::getDodvatelPalety()
{
	return dodavatelPalety_;
}

void Paleta::setPrioritaPrichoduDoSkladu(Datum * paDatum)
{
	prioritaPrichoduDoSkladu_ = Helper::vypocitajPriorituDatumu(paDatum);
}

void Paleta::setStavZasielky(StavZasielky paStav)
{
	stav = paStav;
}

void Paleta::setDatumPrichoduDoSkladu(Datum * paDatum)
{
	delete datumPrichoduDoSkladu_;
	datumPrichoduDoSkladu_ = paDatum;
}

void Paleta::setDatumDorucenia(Datum * paDatum)
{
	delete datumDorucenia_;
	datumDorucenia_ = paDatum;
}

void Paleta::setDodavatelPalery(Dodavatel * paDodavatel)
{
	dodavatelPalety_ = paDodavatel;
}

void Paleta::setPrioritnaPaleta()
{
	priorita_ = true;
}
