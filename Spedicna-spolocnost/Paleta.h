#pragma once
#include <string>
#include "Datum.h"
#include "structures\heap_monitor.h"
#include "Helper.h"

using namespace std;

enum StavZasielky
{
	PREVZATA, NEZREALIZOVANA, NEPREVZATA, PENDING
};

class Dodavatel; // FORWARD DEKLARACIA

class Paleta
{
public:
	Paleta(int pHmotnost, int paIdRegion);
	Paleta(int pHmotnost, int paIdRegion, int paDen, int paMesiac, int paRok);
	~Paleta();

	// GETERY
	int getIdRegion();
	int getHmotnostPalety();
	Datum * getDatumDorucenia();
	bool getPriorita();
	int getPrioritaPrichoduDoSkladu();
	StavZasielky getStavZasielky();
	Datum *getDatumPrichoduDoSkladu();
	Dodavatel *getDodvatelPalety();

	// SETTER
	void setPrioritaPrichoduDoSkladu(Datum * paDatum);
	void setStavZasielky(StavZasielky paStav);
	void setDatumPrichoduDoSkladu(Datum *paDatum);
	void setDatumDorucenia(Datum *paDatum);
	void setDodavatelPalery(Dodavatel * paDodavatel);
	void setPrioritnaPaleta();

private:
	int hmotnost_;
	int idRegion_;
	bool priorita_;
	int prioritaPrichoduDoSkladu_; // Ked paleta pride do skladu, zabezpeci sa, aby vznikla priorita prichodu
	StavZasielky stav;
	Datum *datumDorucenia_; // V pripade, ze je null, nejedna sa o prioritnu palitu.
	Datum *datumPrichoduDoSkladu_;
	Dodavatel *dodavatelPalety_;
};