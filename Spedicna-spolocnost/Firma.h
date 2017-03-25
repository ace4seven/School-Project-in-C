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

// SPEDICNA SPOLOCNOST
class Firma
{
public:
	Firma();
	Firma(int paDen, int paMesiac, int paRok, int paPocetRegionov); // Nastavenie dnesneho datumu
	~Firma();

	void tik(); // Spustac sezony
	void vypisPeknuUvodnuObrazovku();
	void posunNaDalsiDen();
	void vycistiCeluPamat();
	void inicializujSkladPreRegiony();

	// METODY, KTORE URCUJU VYPRACOVANE ZADANIE
	void vypisVozidlaPodlaDatEv(); // ULOHA 2
	void vypisDodavatelov(); // ULOHA 4
	void ohlaseniePrichoduKamionov(); // ULOHA 5
	void skontrolujPrichodyKamionov(); // ULOHA 6 Skontroluje prichody, ak pride kamion v dany den, vyskladni ich nahrubo do skladu
	void pripravaARozvoz(); // ULOHA 7, 8, 9
	void vyradenieVozidiel(); // ULOHA 10
	void vypisPalietVCentralnomSklade(); // ULOHA 11
	void vyhladanieDodavatelaNajviacNepPaliet(); // ULOHA 12
	void vypisPaliet1TriedyNezrealizovane(); // ULOHA 13

	// PRACA S VOZIDLAMI
	void pridajVozidlo(Vozidlo *paVozidlo);

	// DODAVATELIA
	void pridajDodavatela(string paObchodneMeno, string adresa);
	void pridajDodavatela(Dodavatel * paDodavatel);
	void pridajDodavatelov(ArrayList<Dodavatel*> *paDodavatelia);

	// GETERY
	ArrayList<Vozidlo*> *getVozidla();
	int getPocetRegionov();
	int getVahaNaskladnenychPaliet();
	int getKapacitaVozidiel();
	bool getDnesRozvazame();
	ArrayList<Region *> *getSkladPodlaRegionov();

	Datum* getDnesnyDatum();
	ArrayList<Paleta *> *getSklad();
	ExplicitQueue<Vozidlo *> *getFrontVozNaOdpis();
	ArrayList<Dodavatel *> *getDodavatelia();
	ArrayList<Paleta *> *getNeroztriedenePalety();
	LinkedList<Paleta*> *getNeprevzatePalety();
	Dodavatel * getDodavatelByFirma(string nazovFirmy);

	// SETERY
	void setPridajPaletuDoSkladu(Paleta * pal);
	void setPridajNeroztriedPaletu(Paleta *pal);
	void setPridajNeprevzatuPaletu(Paleta *pal);
	void setPocetRegionov(int paPocet);
	void setVahaNaskladnenychPaliet(int paVaha);
	void setKapacitaVozidiel(int paKapacita);
	void setDnesRozvazame(bool paRozvazame);

private:
	// ATRIBUTY:
	int pocetRegionov_;
	int vahaNaskladnenychPaliet_;
	int kapacitaVozidiel_;
	bool dnesRozvazame_;
	ArrayList<Vozidlo *> *vozidla_;
	ArrayList<Dodavatel *> *dodavatelia_;
	Datum *dnesnyDatum_;
	ArrayList<Region *> *uskladnenePodlaRegionov_;
	LinkedList<Paleta*> *neprevzatePalety_;
	ArrayList<Paleta *> *sklad_;
	ArrayList<Paleta *> *neroztriedenePalety_;
	Heap<Vozidlo*> *vozidlaPripraveneNaStart_;
	ExplicitQueue<Vozidlo *> *frontNaOdpis_;

	// POMOCNE METODY
	void initAplikaciu();
	bool unikatnyDodavatel(const string *paAdresa);
	bool pridajDodavatelaAbecedne(Dodavatel &dodavatel);
	void vylozObsahKamionuDoSkladu(Kamion *kamion, int paMaxNosnost, Dodavatel *paDodavatel); // Palety jednoducho vylozi do skladu tak ako su.
	void nastavDatumUskladneniaPaliet(Kamion *paKamion); // Pomocna metoda, po vylozeni paliet v sklade sa opeciatkuju datumom, kedy fyzicky prisli do skladu.
	int getMaxHmotnostVozidiel(ArrayList<Vozidlo*> *paVozidlo);
	void zoradenieVozidielPodlaOpotrebenia();
	//void rozdelPaletyDoSkupin(); // rozdeli palety do prioritnej sekcie a obycajnej sekcie

	// SESSION - sezona jedneho dna, metody, ktore sa vykonaju
	void roztriedUskladnenePaletyDoRegionov();
	void nalozVozidlaAPripravNaVyjazd(); // Uloha 7 - priprava na vyjazd zo stanoviska do vsetkych regionov.
	void prevzatiePalietZakaznikmi(); // ULOHA 8  // ULOHA 9
};
