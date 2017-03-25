#pragma once
#include <string>
#include <iostream>
#include "structures\heap_monitor.h"
#include "structures\list\array_list.h"
#include "Kamion.h"
#include "Helper.h"

using namespace std;
using namespace structures;

class Dodavatel
{
public:
	Dodavatel(string paObNazov, string paAdresa);
	~Dodavatel();

	void zaradKamionDoPrevadzky(Kamion *paKamion);
	void zaradKamionyDoPrevadzky(ArrayList<Kamion *> *paKamiony);
	ArrayList<Kamion*> * dodavatelKamiony(); // Vrati smernik ArrayList s firemnymi kamionmi, ktore obsahuju aj datum prichodu do skladu !!!!
	void ohlaseniePrichoduKamionov();

	// GETERY
	const string *getObchodnyNazov();
	const string *getAdresa();
	int getPocetVratPaliet();

	// SETTERY
	void navysOJedenVratPalety();
	void setPocetVratenychPaliet(int pocet);

private:
	string ob_nazov_;
	string adresa_;
	int vratenePalety_;
	ArrayList<Kamion *> *kamiony_; // Volba arraylistu z dovodu, ze moze do buducna dodavatelska firma nabrat viacej kamionov.
};

