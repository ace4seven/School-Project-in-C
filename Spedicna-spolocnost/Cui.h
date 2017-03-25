#pragma once
#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <string>
#include <sstream>
#include "structures\heap_monitor.h"
#include "SuborIO.h"
#include "Testing.h"
#include "Firma.h"

// COOMAND USER INTERFACE - uzivatelsky privetiva konzola na testovanie aplikacie.

using namespace std;
using namespace structures;

class Cui
{
public:
	Cui();
	~Cui();

private:
	// ATRIBUTY
	char vyberMainMenu_;
	Firma * spedFirma_;

	// METODY
	void vypisMenu();
	void vycistiScreenDajMenu();
	void pridajVozidloScreen();
	void pridajDodavatelaScreen();

	// ONLY FOR TEST
	Testing *test;
};

