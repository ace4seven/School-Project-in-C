#pragma once
#include <string>
#include "Datum.h"
#include "structures\heap_monitor.h"
#include "Helper.h"

using namespace std;

/// <summary> PENDING = Zasielka je v kamione, PREVZATA - paleta je prevzata, NEZREALIZOVANA - paleta 1 triedy nebola odoslana, NEPREVZATA - paleta odmietnuta</summary>
enum StavZasielky
{
	PREVZATA, NEZREALIZOVANA, NEPREVZATA, PENDING
};

class Dodavatel; // FORWARD DEKLARACIA

class Paleta
{
public:
	/// <summary> Konstruktor 1</summary>
	/// <param name = "pHmotnost"> Hmotnost palety - CELE CISLO </param>
	/// <param name = "paIdRegion"> ID regionu, do ktoreho sa ma poslat: KLADNE CELE CISLO </param>
	Paleta(int pHmotnost, int paIdRegion);
	/// <summary> Konstruktor 2 - PRIORITNA paleta</summary>
	/// <param name = "pHmotnost"> Hmotnost palety - CELE CISLO </param>
	/// <param name = "paIdRegion"> ID regionu, do ktoreho sa ma poslat: KLADNE CELE CISLO </param>
	/// <param name = "paDen"> Den odovzdania</param>
	/// <param name = "paMesiac"> Mesiac odovzdania </param>
	/// <param name = "paRok"> Rok odovzdania </param>
	Paleta(int pHmotnost, int paIdRegion, int paDen, int paMesiac, int paRok);
	/// <summary> Destruktor </summary>
	~Paleta();

	/// <summary> Vrati ID regionu, do ktoreho ma byt Paleta poslana</summary>
	/// <returns> Region ID </returns>
	int getIdRegion();
	/// <summary> Vrati celkovu hmotnost palety</summary>
	/// <returns> Vaha palety </returns>
	int getHmotnostPalety();
	/// <summary> Vrati objekt Datum, kedy ma byt paleta 1-triedy dorucena</summary>
	/// <returns> Objekt datum </returns>
	Datum * getDatumDorucenia();
	/// <summary> Vrati true, ak je paleta 1.triedy</summary>
	/// <returns> boolean </returns>
	bool getPriorita();
	/// <summary> Vrati celociselnu hodnotu - skonvertovany datum na cislo </summary>
	/// <returns> cele kladne cislo</returns>
	int getPrioritaPrichoduDoSkladu();
	/// <summary> Vrati enumeracny typ zasielky </summary>
	/// <returns> ENUM StavZadielky</returns>
	StavZasielky getStavZasielky();
	/// <summary> Vrati datum, kedy bola paleta dovezena do skladu</summary>
	/// <returns> objekt Datum</returns>
	Datum *getDatumPrichoduDoSkladu();
	/// <summary> Vrati dodavatela, ktory dodal paletu </summary>
	/// <returns> objekt Dodavatel </returns>
	Dodavatel *getDodvatelPalety();

	/// <summary> Posle datum a ten skonvertuje na cislo</summary>
	/// <param name = "paDatum"> Objekt datum </param>
	void setPrioritaPrichoduDoSkladu(Datum * paDatum);
	/// <summary> Nastavi zasielku ako DORUCENU, PENDING, NEZREALIZOVANU, alebo NEPREBRATU</summary>
	/// <param name = "paStav"> Enumeracny typ </param>
	void setStavZasielky(StavZasielky paStav);
	/// <summary>Nastavi datum, kedy paleta prisla do skladu</summary>
	/// <param name = "paDatum"> objekt datum </param>
	void setDatumPrichoduDoSkladu(Datum *paDatum);
	/// <summary>Ak sa jedna o prioritnu paletu, nastavi datum dorucenia</summary>
	/// <param name = "paDatum"> objekt datum </param>
	void setDatumDorucenia(Datum *paDatum);
	/// <summary>Nastavenie dodavatela palety</summary>
	/// <param name = "paDatum"> objekt Dodavatel </param>
	void setDodavatelPalery(Dodavatel * paDodavatel);
	/// <summary>Nastavi paletu ako paletu 1.triedy</summary>
	/// <param name = "paDatum"> objekt Datum</param>
	void setPrioritnaPaleta();

private:
	/// <summary> Hmotnost palety</summary>
	int hmotnost_;
	/// <summary>Region, kde bude paleta poslana</summary>
	int idRegion_;
	/// <summary>Priorita palety</summary>
	bool priorita_;
	/// <summary>Datum prichodu prekonvertovany na cislo</summary>
	int prioritaPrichoduDoSkladu_;
	/// <summary>Aktualny stav palety - DORUCENA, PENDING, NEZREALIZOVANA, alebo NEPREBRATA </summary>
	StavZasielky stav;
	/// <summary>Datum dorucenia palety</summary>
	Datum *datumDorucenia_;
	/// <summary>Datum pichodu do skladu</summary>
	Datum *datumPrichoduDoSkladu_;
	/// <summary>Dodavatel palety</summary>
	Dodavatel *dodavatelPalety_;
};