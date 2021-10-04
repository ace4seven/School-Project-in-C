#pragma once
#include "Helper.h"
#include "structures\list\array_list.h"
#include "Paleta.h"
#include "Datum.h"
#include "structures\heap_monitor.h"

class Kamion
{
public:
	/// <summary> Konstruktor</summary>
	/// <param name = "paKapacita"> Nosnost kamionou v KG</param>
	/// <param name = "paDen"> Den prichodu do skladu</param>
	/// <param name = "paMesiac"> Mesiac prichodu do skladu </param>
	/// <param name = "paRok">Rok prichodu do skladu</param>
	Kamion(int paKapacita, int paDen, int paMesiac, int paRok);
	/// <summary> Destruktor</summary>
	~Kamion();

	/// <summary> Nalozi danu paletu v pripade, ze je volna kapacita</summary>
	/// <param name = "evidCislo"> objekt Paleta</param>
	/// <returns> Vrati true, ak je volna kapacita, v opacnom pripade false </returns>
	bool nalozPaletu(Paleta *paPaleta);
	/// <summary> Odstrani cely obsah kamionu deletne ArrayList, zmaze natrvalo</summary>
	void odstranObsahKamionu();

	/// <summary> Vrati celkovu kapacitu kamionu</summary>
	/// <returns> Celociselna kladna hodnota </returns>
	int getKapacita();
	/// <summary> Aktualny naklad v kg, ktorym kamion disponuje</summary>
	/// <returns> Celociselna kladna hodnota </returns>
	int getAktualNaklad();
	/// <summary> Vrati datum, v ktorom kamion navstivi sklad</summary>
	/// <returns> objekt Datum</returns>
	Datum *getDatumPrichodu();
	/// <summary> Vrati zoznam paliet, ktorym kamion disponuje</summary>
	/// <returns> ArrayList palety </returns>
	structures::ArrayList<Paleta*> *getObsahKamiona();
	/// <summary> Pokial bol kamion v centralnom sklade, upravi sa vylozenie</summary>
	/// <returns> TRUE - ak bol vylozeny, inak FALSE </returns>
	bool getVylozeny();

	/// <summary> Nastavi vylozenie kamioniu na TRUE</summary>
	void setKamionVylozeny();
	/// <summary> Navysi aktualny naklad kamionu</summary>
	/// <param name = "aktnaklad"> Novy naklad v KG</param>
	void setAktNaklad(int aktnaklad);

private:
	/// <summary> Zoznam paliet v kamione</summary>
	structures::ArrayList<Paleta*> *obsahPaliet_;
	/// <summary> Datum prichodu do skladu </summary>
	Datum *prichodDoSkladu_;
	/// <summary> Kapacita kamionu v kilogramoch</summary>
	int kapacita_;
	/// <summary> Aktualne nalozenie kamionu paletami v KG</summary>
	int aktualnyNaklad_;
	/// <summary> Trigger nalozenia, respektive vylozenia</summary>
	bool vylozeny_;
};

