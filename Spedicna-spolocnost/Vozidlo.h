#pragma once
#include <string>
#include <iostream>
#include "structures\heap_monitor.h"
#include "structures\list\array_list.h"
#include "Paleta.h"
#include "Datum.h"

using namespace std;
using namespace structures;

class Vozidlo
{
public:
	Vozidlo(string evidCislo, int nosnost, Datum *datumZaradenia);
	~Vozidlo();

	void vypisParametre();

	// GETERY
	Datum *getDatumZaradenia();
	int getNosnost();
	int getAktualneNalozenie();
	int getOpotrebenie();
	int getIdRegionu();
	ArrayList<Paleta *> *getNalozenePalety();
	string getEvidC();
	bool getCakaNaOdpis();

	// SET
	void nalozPaletuDoVozidla(Paleta *paPaleta);
	void setRegionRoznasania(int paRegionId);
	void setNavysOpotrebenie(int paOpotrebenie);
	void setNastavNaOdpis();
	void setAktualneNalozenie(int paNalozenie);

private:
	string evidCislo_;
	int nosnost_;
	int aktualneNalozenie_;
	int opotrebenie_;
	int regionRoznaska_;
	bool cakajuceNaOdpis_;
	Datum *datumZaradenia_;
	ArrayList<Paleta *> *paletyVoVozidle_;
};

