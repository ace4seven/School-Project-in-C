#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include "structures\heap_monitor.h"
#include "Firma.h"

using namespace std;

class SuborIO
{
public:
	/// <summary> Destruktor</summary>
	~SuborIO();
	/// <summary> Staticka metoda, ulozi firemne data do suboru</summary>
	/// <param name = "spedFirma"> objekt Firma </param>
	/// <returns> Uspesne ulozenie = True </returns>
	static bool ulozDoSuboru(Firma *spedFirma);
	/// <summary> Staticka metoda, nacita firmu zo suboru</summary>
	/// <param name = "spedFirma"> objekt Firma </param>
	/// <returns> Uspesne nacitanie = True </returns>
	static bool nacitajZoSuboru(Firma *spedFirma, string subor); 
private:
	/// <summary> Privatny konstruktor</summary>
	SuborIO();
	/// <summary> Pomocna metoda, konvertuje string do pola na polozky oddelene oddelovacom</summary>
	/// <param name = "text">String retazec</param>
	/// <param name = "sep"> Oddelovac </param>
	/// <returns> Vector </returns>
	static vector<string> split(const string &text, char sep);
};

