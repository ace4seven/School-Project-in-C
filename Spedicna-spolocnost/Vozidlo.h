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
	/// <summary> Konstruktor </summary>
	/// <param name = "evidCislo"> Evidencne cislo vozidla </param>
	/// <param name = "datumZaradenia> Datum, kedy bolo vozidlo zaradene do prevadzky </param>
	Vozidlo(string evidCislo, int nosnost, Datum *datumZaradenia);

	/// <summary> Destruktor </summary>
	~Vozidlo();

	/// <summary> Vypise parametre vozidla - SPZ, NOSNOST, OPOTREBENIE </summary>
	void vypisParametre();

	/// <summary> Vrati datum, kedy vozidlo bolo zaradene do prevadzky</summary>
	/// <returns> Datum </returns>
	Datum *getDatumZaradenia();
	/// <summary> Vrati MAXIMALNU nosnost vozidla</summary>
	/// <returns> Celociselnu kladnu hodnotu </returns>
	int getNosnost();
	/// <summary> Vrati nosnost akou je vozidlo prave nalozene</summary>
	/// <returns> Celociselnu kladnu hodnotu </returns>
	int getAktualneNalozenie();
	/// <summary> Vrati celkove opotrebenie vozidla </summary>
	/// <returns> Celociselnu kladnu hodnotu </returns>
	int getOpotrebenie();
	/// <summary> Vrati region, v ktorom sa vozidlo nachadza.</summary>
	/// <returns> Celociselnu kladnu hodnotu, AK JE 0, je v sklade, ak N - tak v region N  </returns>
	int getIdRegionu();
	/// <summary> Vrati zoznam vsetkych nalozenych paliet vozidla</summary>
	/// <returns> Zoznam paliet </returns>
	ArrayList<Paleta *> *getNalozenePalety();
	/// <summary> Vrati evidencne cislo vozidla</summary>
	/// <returns> Retazec - evidencne cislo </returns>
	string getEvidC();
	/// <summary> Vrati true, ak vozidlo je zaradene vo fronte na odpis</summary>
	/// <returns> Boolean </returns>
	bool getCakaNaOdpis();

	/// <summary> Prida paleta do Zoznamu paletyVoVozidle </summary>
	/// <param name = "paPaleta"> Parameter paleta, ktora sa ide ulozit do zoznamu </param>
	void nalozPaletuDoVozidla(Paleta *paPaleta);
	/// <summary> Urci sa, v ktorom regione bude vozidlo roznasat palety </summary>
	/// <param name = "paRegionId"> Region 0 .. N</param>
	void setRegionRoznasania(int paRegionId);
	/// <summary> Opotrebenie vozidla sa navysi o index regionu, v ktorom rozvazalo vozidlo palety </summary>
	/// <param name = "paOpotrebenie"> Opotrebenie ID regionu.</param>
	void setNavysOpotrebenie(int paOpotrebenie);
	/// <summary> Nastavi atribut cakajuciNaOdpis_ na TRUE </summary>
	void setNastavNaOdpis();
	/// <summary> Nastavi aktualne nalozenie vozidla - ZVACSA na 0, po ukonceni roznasky</summary>
	/// <param name = "paNalozenie"> hodnota nalozenia</param>
	void setAktualneNalozenie(int paNalozenie);

private:
	/// <summary> Evidencne cislo vozidla</summary>
	string evidCislo_;
	/// <summary> Nosnost vozidla </summary>
	int nosnost_;
	/// <summary> Aktualne nalozena vaha </summary>
	int aktualneNalozenie_;
	/// <summary> Aktualne opotrebenie</summary>
	int opotrebenie_;
	/// <summary> Region, v ktorom vozidlo rozvaza</summary>
	int regionRoznaska_;
	/// <summary> Ukazovatel, ci je auto schopne rozvazania</summary>
	bool cakajuceNaOdpis_;
	/// <summary> Datum zaradenia vozidla do firmy</summary>
	Datum *datumZaradenia_;
	/// <summary> Zoznam paliet vo vozidle </summary>
	ArrayList<Paleta *> *paletyVoVozidle_;
};

