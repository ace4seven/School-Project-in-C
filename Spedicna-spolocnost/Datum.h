#pragma once
#include "structures\heap_monitor.h"
#include <string>

class Datum
{
public:
	/// <summary> Konstruktor 1</summary>
	Datum();
	/// <summary> Konstruktor 2</summary>
	/// <param name = "paDen"> Den v datume </param>
	/// <param name = "paMes"> Mesiac v datume </param>
	/// <param name = "paRok"> Rok v datume </param>
	Datum(int paDen, int paMes, int paRok);
	/// <summary> Destruktor </summary>
	~Datum();

	/// <summary> Posunie datum o 1 den dopredu </summary>
	void posunOJedenDen();

	/// <summary> Operator porovnavania 2 datumov</summary>
	/// <returns> Vrati true ak sa 2 datumy rovnaju </returns>
	bool operator==(const Datum &other) const;
	/// <summary> Operator mensi </summary>
	/// <returns> vrati true ak je prvy datum skorsi ako druhy </returns>
	bool operator<(const Datum &other) const;
	/// <summary> Operator vacsi </summary>
	/// <returns> vrati true ak je druhy datum skorsi ako prvy </returns>
	bool operator>(const Datum &other) const;

	/// <summary> Vrati den v datume </summary>
	/// <returns> Cele kladne cislo </returns>
	int getDen();
	/// <summary> Vrati mesiac v datume </summary>
	/// <returns> Cele kladne cislo </returns>
	int getMesiac();
	/// <summary> Vrati rok v datume </summary>
	/// <returns> Cele kladne cislo </returns>
	int getRok();
	/// <summary> Vrati datum vo formate D.M.YYYY </summary>
	/// <returns> retazec datum </returns>
	std::string vratRetazec();

	/// <summary> Upravy dany datum na akykolvek iny datum</summary>
	/// <param name = "den"> Den v datume </param>
	/// <param name = "mesiac"> Mesiac v datume </param>
	/// <param name = "rok"> Rok v datume </param>
	void setUpravDatum(int den, int mesiac, int rok);

private:
	/// <summary> Pomocna metoda, ktora dokaze povedat, ci je zadany rok priestupny, alebo nie</summary>
	/// <returns> vrati True, ak sa jedna o priestupny rok</returns>
	bool jePriestupnyRok();
	/// <summary> Pomocna metoda, ktora podla mesiaca dokaze urcit presny pocet dni v tom danom mesiaci</summary>
	/// <returns> cele kladne cislo v intervale 1-31 </returns>
	int dniVMesiaci();

	/// <summary> Den ako cele cislo</summary>
	int den_;
	/// <summary> Mesiac ako cele cislo</summary>
	int mes_;
	/// <summary> Rok ako cele cislo</summary>
	int rok_;
};

