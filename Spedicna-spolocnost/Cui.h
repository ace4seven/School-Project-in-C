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
	/// <summary> Konstruktor</summary>
	Cui();
	/// <summary> Destruktor</summary>
	~Cui();

private:
	/// <summary> Vypise uzivatelske MENU</summary>
	void vypisMenu();
	/// <summary> Vycisti konzolu a vrati MENU</summary>
	void vycistiScreenDajMenu();
	/// <summary> Screen na pridanie vozidla do firmy</summary>
	void pridajVozidloScreen();
	/// <summary> Screen na pridanie dodavatela do firmy - rovnako aj kamiony a palety</summary>
	void pridajDodavatelaScreen();

	/// <summary> Testovacia trieda (ak nechceme nacitavat zo subora)</summary>
	Testing *test;
	/// <summary> Spedicna firma objekt</summary>
	Firma * spedFirma_;
};

