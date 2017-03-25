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
	/// <summary> Konstruktor</summary>
	/// <param name = "paObNazov"> Obchodnz nazov dodavatela </param>
	/// <param name = "paAdresa"> Adresa firmy dodavatela</param>
	Dodavatel(string paObNazov, string paAdresa);
	/// <summary> Destruktor </summary>
	~Dodavatel();

	/// <summary> Vrati datum, kedy vozidlo bolo zaradene do prevadzky</summary>
	void ohlaseniePrichoduKamionov();

	/// <summary> Vrati nazov firmy </summary>
	/// <returns> Smernik string firma </returns>
	const string *getObchodnyNazov();
	/// <summary> Vrati adresu dodavatela </summary>
	/// <returns> Smernik string </returns>
	const string *getAdresa();
	/// <summary> Vrati pocet vratenych paliet dodavatelovi</summary>
	/// <returns> Cele kladne cislo </returns>
	int getPocetVratPaliet();
	/// <summary> Vrati vsetky kamiony dodavatela </summary>
	/// <returns> Zoznam kamionov </returns>
	ArrayList<Kamion*> * dodavatelKamiony(); // Vrati smernik ArrayList s firemnymi kamionmi, ktore obsahuju aj datum prichodu do skladu !!!!

	/// <summary> Vratene palety navysi o 1 </summary>
	void navysOJedenVratPalety();
	/// <summary> Nastavy pocet vratenych paliet o konkretne cislo</summary>
	/// <param name = "pocet"> Cele kladne cislo </param>
	void setPocetVratenychPaliet(int pocet);
	/// <summary> Zaradi kamion do prevadzky, navysi zoznam o 1 kamion</summary>
	/// <param name = "paKamion"> objekt Kamion  </param>
	void zaradKamionDoPrevadzky(Kamion *paKamion);
	/// <summary> Zaradi kamiony ku dodavatelovi, stare kamiony vyradi </summary>
	/// <param name = "paKamiony"> Zoznam Kamiony  </param>
	void zaradKamionyDoPrevadzky(ArrayList<Kamion *> *paKamiony);

private:
	/// <summary> Dodavatel - nazov firmy</summary>
	string ob_nazov_;
	/// <summary> Adresa dodavatelovej firmy </summary>
	string adresa_;
	/// <summary> Mnozstvo vratenych paliet</summary>
	int vratenePalety_;
	/// <summary> Zoznam kamionov dodavatela</summary>
	ArrayList<Kamion *> *kamiony_; // Volba arraylistu z dovodu, ze moze do buducna dodavatelska firma nabrat viacej kamionov.
};

