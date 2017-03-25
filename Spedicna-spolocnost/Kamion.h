#pragma once
#include "Helper.h"
#include "structures\list\array_list.h"
#include "Paleta.h"
#include "Datum.h"
#include "structures\heap_monitor.h"

class Kamion
{
public:
	Kamion(int paKapacita, int paDen, int paMesiac, int paRok);
	~Kamion();

	bool nalozPaletu(Paleta *paPaleta);
	void odstranObsahKamionu();

	// GETERY:
	int getKapacita();
	int getAktualNaklad();
	Datum *getDatumPrichodu();
	structures::ArrayList<Paleta*> *getObsahKamiona();
	bool getVylozeny();

	// SETERY:
	void setKamionVylozeny();
	void setAktNaklad(int aktnaklad);

private:
	structures::ArrayList<Paleta*> *obsahPaliet_;
	Datum *prichodDoSkladu_;
	int kapacita_; //kapacita paliet v KG
	int aktualnyNaklad_;
	bool vylozeny_;
};

