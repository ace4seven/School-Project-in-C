#pragma once
#include <iostream>
#include "structures\heap_monitor.h"
#include "structures\list\array_list.h"
#include "structures\list\linked_list.h"
#include "structures\priority_queue\heap.h"
#include "Vozidlo.h"
#include "Dodavatel.h"
#include "Helper.h"
#include "Region.h"
#include "structures\stack\explicit_stack.h"
#include "structures\queue\explicit_queue.h"

using namespace structures;
using namespace std;

/// <summary> Vrati datum, kedy vozidlo bolo zaradene do prevadzky</summary>
/// <param name = "evidCislo"> Evidencne cislo vozidla </param>
/// <returns> Datum </returns>

// SPEDICNA SPOLOCNOST
class Firma
{
public:
	/// <summary> Konstruktor 1</summary>
	Firma();
	/// <summary> Konstruktor 2</summary>
	/// <param name = "paDen">Dnesny den datumu</param>
	/// <param name = "paMesiac">Dnesny mesiac datumu</param>
	/// <param name = "paRok">Dnesny rok datumu</param>
	/// <param name = "paPocetRegionov">Pocet regionov</param>
	Firma(int paDen, int paMesiac, int paRok, int paPocetRegionov); 
	/// <summary> Destruktor </summary>
	~Firma();

	/// <summary> Vypise uvodnu obrazovku v CLI</summary>
	void vypisPeknuUvodnuObrazovku();
	/// <summary> Posunieme sa na dalsi kalendarny den</summary>
	void posunNaDalsiDen();
	/// <summary> Vycistime pamat od vsetkych poloziek v zoznamoch, frontoch ... </summary>
	void vycistiCeluPamat();
	/// <summary> Inicializuje sa kontainer uskladnenePodla regionov a nastavia sa regiony</summary>
	void inicializujSkladPreRegiony();

	// METODY, KTORE URCUJU VYPRACOVANE ZADANIE
	/// <summary> Vypisanie stavov vozidiel vo firme na konzolu </summary>
	void vypisVozidlaPodlaDatEv(); // ULOHA 2
	/// <summary> Vypisanie registrovanych dodavatelov - ich obchodny nazov a adresa sidla</summary>
	void vypisDodavatelov(); // ULOHA 4
	/// <summary> Vypise zoznam vsetkych dodavatelov a ich kamiony a ich obsah a hlasenia, kedy sa maju dostavit do skladu</summary>
	void ohlaseniePrichoduKamionov(); // ULOHA 5
	/// <summary> Ohlasene kamiony na dnesny den sa spracuju palety a rozdelia bud do skladu, neroztriedenych paliet</summary>
	void skontrolujPrichodyKamionov(); // ULOHA 6 
	/// <summary> Pokial sa ma dnes rozvazat, palety sa rozdelia do skladov regionov podla priorit a rozvezu sa zakaznikom</summary>
	void pripravaARozvoz(); // ULOHA 7, 8, 9
	/// <summary> Vozidla, ktore su zaradene v prioritnom fronte budu zmazane</summary>
	void vyradenieVozidiel(); // ULOHA 10
	/// <summary> Vypise nam detaily vsetkych paliet, ktore nam ostali na sklade.</summary>
	void vypisPalietVCentralnomSklade(); // ULOHA 11
	/// <summary> Vypise dodavatela na konzolu, ktoremu bolo neprevzatych najviac paliet</summary>
	void vyhladanieDodavatelaNajviacNepPaliet(); // ULOHA 12
	/// <summary> Vypise na konzolu vsetky palety 1 triedy, ktore boli nezrealizovane</summary>
	void vypisPaliet1TriedyNezrealizovane(); // ULOHA 13

	/// <summary> Vrati nam vsetky firemne vozidla</summary>
	/// <returns> smernik na zoznam vozidiel </returns>
	ArrayList<Vozidlo*> *getVozidla();
	/// <summary> Vrati celkovy pocet evidovanych regionov</summary>
	/// <returns> Pocet regionov </returns>
	int getPocetRegionov();
	/// <summary> Vrati celkovu vahu naskladnenych paliet</summary>
	/// <returns> Mnozstvo v KG uskladnenych paliet </returns>
	int getVahaNaskladnenychPaliet();
	/// <summary> Vrati celkovu nosnu kapacitu evidovanych vozidiel</summary>
	/// <returns> Nosnost vozidiel v KG </returns>
	int getKapacitaVozidiel();
	/// <summary> Pokial mozeme dnes nieco rozvadzat zistujeme v tejto metode</summary>
	/// <returns> Ak je co rozvazat - vrati TRUE </returns>
	bool getDnesRozvazame();
	/// <summary> Vrati Zoznam regionov v ktorom uskladnujeme palety urcene na vyvoz do regionov</summary>
	/// <returns> smernik na zoznam regionov </returns>
	ArrayList<Region *> *getSkladPodlaRegionov();
	/// <summary> Vrati nam dnesny datum</summary>
	/// <returns> smernik na Datum </returns>
	Datum* getDnesnyDatum();
	/// <summary> Vrati smernik na atribut sklad_</summary>
	/// <returns> smernik na Zoznam paliet </returns>
	ArrayList<Paleta *> *getSklad();
	/// <summary> Vrati FRONT, v ktorom su vozidla urcene na odpis</summary>
	/// <returns> smernik na Front vozidel </returns>
	ExplicitQueue<Vozidlo *> *getFrontVozNaOdpis();
	/// <summary> Vrati nam Zoznam evidovanych dodavatelov</summary>
	/// <returns> smernik na  Zoznam dodavatelov </returns>
	ArrayList<Dodavatel *> *getDodavatelia();
	/// <summary> Vrati zoznam paliet, ktore sa nestihli, alebo niesu urcene na rozvoz v dany den</summary>
	/// <returns> smernik na Zoznam paliet</returns>
	ArrayList<Paleta *> *getNeroztriedenePalety();
	/// <summary> Explicitny zoznam neprevzatych paliet </summary>
	/// <returns> smernik na Zoznam paliet</returns>
	LinkedList<Paleta*> *getNeprevzatePalety();
	/// <summary> Vrati smernik na objekt Dodavael po zadani retazca nazov firmy, pokial sa taky najde, inak nullptr</summary>
	/// <param name = "nazovFirmy"> Retazec nazov hladaneho dodavatela </param>
	/// <returns>smernik na Dodavatel </returns>
	Dodavatel * getDodavatelByFirma(string nazovFirmy);

	/// <summary> Pridanie dodavatela do firmy</summary>
	/// <param name = "paObchodneMeno"> Retazec nazov firmy dodavatela </param>
	/// <param name = "adresa"> Retazec adresa firmy dodavatela </param>
	void pridajDodavatela(string paObchodneMeno, string adresa);
	/// <summary> Pridanie dodavatela vlozenym objektu Dodavatel</summary>
	/// <param name = "paDodavatel"> objekt Dodavatel </param>
	void pridajDodavatela(Dodavatel * paDodavatel);
	/// <summary> Pridanie Zoznamu dodavatelov, povodny zoznam dodavatelov sa vymaze</summary>
	/// <param name = "paDodavatelia"> zoznam Dodavatelia </param>
	void pridajDodavatelov(ArrayList<Dodavatel*> *paDodavatelia);
	/// <summary> Pridanie vozidla do vozoveho parku spedicnej firmy</summary>
	/// <param name = "paVozidlo"> smernik na objekt Vozidlo </param>
	void pridajVozidlo(Vozidlo *paVozidlo);
	/// <summary> Pridanie smernika na Paletu do centralneho skladu </summary>
	/// <param name = "pal"> smernik na objekt Paleta </param>
	void setPridajPaletuDoSkladu(Paleta * pal);
	/// <summary> Pridanie smernika na Paletu do neroztriedeneho zoznamu paliet</summary>
	/// <param name = "pal"> smernik na objekt Paleta </param>
	void setPridajNeroztriedPaletu(Paleta *pal);
	/// <summary> Pridanie smernika na Paletu do neprevzateho zoznamu paliet</summary>
	/// <param name = "pal"> smernik na objekt Paleta </param>
	void setPridajNeprevzatuPaletu(Paleta *pal);
	/// <summary> Nastavenie poctu regionov, v ktorych sa bude roznasat.</summary>
	/// <param name = "paPocet"> celociselny kladny pocet v KG </param>
	void setPocetRegionov(int paPocet);
	/// <summary> Nastavenie hmotnosti vsetkych naskladnenych paliet</summary>
	/// <param name = "paPocet"> celociselny kladny pocet v KG</param>
	void setVahaNaskladnenychPaliet(int paVaha);
	/// <summary> Nastavenie celkovej kapacity evidovanych vozidiel</summary>
	/// <param name = "paPocet"> celociselny nenulovy pocet urceny v KG </param>
	void setKapacitaVozidiel(int paKapacita);
	/// <summary> Trigger, ktorym chceme povedat ci rozvazame dnes palety, alebo nie</summary>
	/// <param name = "paPocet"> bool rozhodnutie TRUE- ano, FALSE - nie </param>
	void setDnesRozvazame(bool paRozvazame);

private:
	/// <summary> Inicializacia aplikacie, naplnenie atributov zaciatocnymi datami, vytvorenie dynamickych objektov </summary>
	void initAplikaciu();
	/// <summary> Pomocna trieda urcena na kompletnu simulaciu dna bez nutnosti nastavovat manualne vsetky body </summary>
	void tik();
	/// <summary> Pomocna metoda, ktora kontroluje v zozname duplicity dodavatelov na zaklade adresy </summary>
	/// <param name = "paAdresa"> smernik na Retazec - adresa dodavatela</param>
	/// <returns> True - unikatna adresa </returns>
	bool unikatnyDodavatel(const string *paAdresa);
	/// <summary> Ulozi dodavatela v abecednom poradi do Zoznamu, ak moze</summary>
	/// <param name = "dodavatel"> adresa dodavatela</param>
	/// <returns> True, pokial je mozne zaradit dodavatela pred ineho dodavatela</returns>
	bool pridajDodavatelaAbecedne(Dodavatel &dodavatel);
	/// <summary> Pomocna metoda, ktora skontroluje obsah kamionu a roztriedi jeho palety</summary>
	/// <param name = "kamion"> Smernik na kamion, ktory vykladame</param>
	/// <param name = "paMaxNosnost"> MAX nosnost vsetkych vozidiel</param>
	/// <param name = "paDodavatel">Dodavatel kamionu</param>
	void vylozObsahKamionuDoSkladu(Kamion *kamion, int paMaxNosnost, Dodavatel *paDodavatel);
	/// <summary> Pomocna metoda, ktora zistuje MAX nosnot prechadzanim vsetkymi vozidlami</summary>
	/// <param name = "paVozidlo"> smernik na Zoznam vozidiel</param>
	/// <returns> MAX </returns>
	int getMaxHmotnostVozidiel(ArrayList<Vozidlo*> *paVozidlo);
	/// <summary> Vozidla, ktore su schopne prepravy sa zoradia podla opotrebenia</summary>
	void zoradenieVozidielPodlaOpotrebenia();

	/// <summary> Palety v sklade roztriedy do jednotlivych regionov </summary>
	void roztriedUskladnenePaletyDoRegionov();
	/// <summary> Roztriedene palety sa rozdelia do vozidiel a simuluje sa vyjazd </summary>
	void nalozVozidlaAPripravNaVyjazd(); // Uloha 7 - priprava na vyjazd zo stanoviska do vsetkych regionov.
	/// <summary> Simulacia prevzatia paliet zakaznikmi.</summary>
	void prevzatiePalietZakaznikmi(); // ULOHA 8  // ULOHA 9

	/// <summary> pocet regionov</summary>
	int pocetRegionov_;
	/// <summary> vaha naskladnenych paliet</summary>
	int vahaNaskladnenychPaliet_;
	/// <summary> celkova kapacita vozidiel</summary>
	int kapacitaVozidiel_;
	/// <summary> atribut rozhodujuci o tom, ci dnes sa bude, alebo nebude rozvazat</summary>
	bool dnesRozvazame_;
	/// <summary> smernik na zoznam vozidiel firmy</summary>
	ArrayList<Vozidlo *> *vozidla_;
	/// <summary> smernik na zoznam dodavatelov</summary>
	ArrayList<Dodavatel *> *dodavatelia_;
	/// <summary> smernik na dnesny Datum</summary>
	Datum *dnesnyDatum_;
	/// <summary> smernik na zoznam regionov, v ktorom su uskladnene palety urcene na vyjazd</summary>
	ArrayList<Region *> *uskladnenePodlaRegionov_;
	/// <summary> psmernik na explicitny zoznam paliet, ktore neboli prevzate</summary>
	LinkedList<Paleta*> *neprevzatePalety_;
	/// <summary> smernik na zoznam paliet</summary>
	ArrayList<Paleta *> *sklad_;
	/// <summary> smernik na zoznam neroztriedenych paliet</summary>
	ArrayList<Paleta *> *neroztriedenePalety_;
	/// <summary> smernik na Prioritny front vozidiel urcenych na dnesnu roznasku zoradene podla opotrebenia</summary>
	Heap<Vozidlo*> *vozidlaPripraveneNaStart_;
	/// <summary> smernik na front vozidiel urcenych na odpis</summary>
	ExplicitQueue<Vozidlo *> *frontNaOdpis_;
};
