#include "Testing.h"



Testing::Testing(Firma *paFirma)
{
	spedicnaFirma = paFirma;
}


Testing::~Testing()
{
	//delete spedicnaFirma;
}

void Testing::pripravTestovacieData()
{
	//PALETY
	//Paleta *paleta1 = new Paleta(4, 1);

	// DODAVATELIA
	Dodavatel *dod1 = new Dodavatel("Paramere s.r.o.", "Sasinkova 23, 03232, Bratislava");
	Dodavatel *dod2 = new Dodavatel("Harmerstap s.r.o.", "Nutrinska 13, 03232, Kosice");
	//Dodavatel *dod3 = new Dodavatel("Adeco s.r.o.", "Nitrianska 513, 01001, Zilina");
	//Dodavatel *dod4 = new Dodavatel("Zapotocie s.r.o.", "Malenskejo 5213, 01001, Zilina");
	//Dodavatel *dod5 = new Dodavatel("Xenofobic s.r.o.", "Muranska 53, 02404, Kysucke Nove Mesto");

	// KAMIONY:
	Kamion *D1Kamion1 = new Kamion(130, 10, 5, 2017);
	Kamion *D1Kamion2 = new Kamion(130, 22, 5, 2017);
	Kamion *D1Kamion3 = new Kamion(2400, 1, 3, 2017);
	Kamion *D1Kamion4 = new Kamion(150, 16, 5, 2017);
	Kamion *D1Kamion5 = new Kamion(160, 21, 5, 2017);
	Kamion *D2Kamion1 = new Kamion(130, 10, 3, 2017);
	Kamion *D2Kamion2 = new Kamion(130, 1, 5, 2017);
	Kamion *D2Kamion3 = new Kamion(140, 2, 5, 2017);
	Kamion *D2Kamion4 = new Kamion(150, 3, 5, 2017);
	Kamion *D2Kamion5 = new Kamion(160, 4, 5, 2017);

	// NALOZENIE PALIET
	D1Kamion3->nalozPaletu(new Paleta(6,3));
	D1Kamion3->nalozPaletu(new Paleta(12, 2));
	D1Kamion3->nalozPaletu(new Paleta(14, 2));
	D1Kamion3->nalozPaletu(new Paleta(14, 3));
	D1Kamion3->nalozPaletu(new Paleta(14, 3));
	D1Kamion3->nalozPaletu(new Paleta(14, 4));
	D1Kamion3->nalozPaletu(new Paleta(14, 5));
	D1Kamion3->nalozPaletu(new Paleta(14, 3));
	D1Kamion3->nalozPaletu(new Paleta(14, 2));
	D1Kamion3->nalozPaletu(new Paleta(14, 4));
	D1Kamion3->nalozPaletu(new Paleta(14, 5));
	D1Kamion3->nalozPaletu(new Paleta(14, 1, 2, 3, 2017));
	D1Kamion3->nalozPaletu(new Paleta(14, 1, 2, 3, 2017));
	D1Kamion3->nalozPaletu(new Paleta(14, 1, 2, 3, 2017));
	D1Kamion3->nalozPaletu(new Paleta(14, 1, 2, 3, 2017));
	D1Kamion3->nalozPaletu(new Paleta(14, 1, 2, 3, 2017));
	D1Kamion3->nalozPaletu(new Paleta(14, 1, 2, 3, 2017));
	D1Kamion3->nalozPaletu(new Paleta(14, 1, 2, 3, 2017));
	D1Kamion3->nalozPaletu(new Paleta(14, 1, 2, 3, 2017));
	D1Kamion3->nalozPaletu(new Paleta(14, 1, 2, 3, 2017));
	D1Kamion3->nalozPaletu(new Paleta(14, 1));
	D1Kamion4->nalozPaletu(new Paleta(5, 5));
	D1Kamion5->nalozPaletu(new Paleta(1, 4));
	D1Kamion5->nalozPaletu(new Paleta(2, 3));
	D1Kamion5->nalozPaletu(new Paleta(3, 2));
	D2Kamion1->nalozPaletu(new Paleta(4, 1));
	D2Kamion1->nalozPaletu(new Paleta(5, 5));
	D2Kamion2->nalozPaletu(new Paleta(1, 4));
	D2Kamion2->nalozPaletu(new Paleta(2, 3));
	D2Kamion3->nalozPaletu(new Paleta(3, 2));
	D2Kamion4->nalozPaletu(new Paleta(4, 1));

	dod1->zaradKamionDoPrevadzky(D1Kamion1);
	dod1->zaradKamionDoPrevadzky(D1Kamion2);
	dod1->zaradKamionDoPrevadzky(D1Kamion3);
	dod1->zaradKamionDoPrevadzky(D1Kamion4);
	dod1->zaradKamionDoPrevadzky(D1Kamion5);
	dod2->zaradKamionDoPrevadzky(D2Kamion1);
	dod2->zaradKamionDoPrevadzky(D2Kamion2);
	dod2->zaradKamionDoPrevadzky(D2Kamion3);
	dod2->zaradKamionDoPrevadzky(D2Kamion4);
	dod2->zaradKamionDoPrevadzky(D2Kamion5);


	spedicnaFirma->pridajDodavatela(dod1);
	spedicnaFirma->pridajDodavatela(dod2);
	//spedicnaFirma->pridajDodavatela(dod3);
	//spedicnaFirma->pridajDodavatela(dod4);
	//spedicnaFirma->pridajDodavatela(dod5);

	// VOZIDLA
	spedicnaFirma->pridajVozidlo(new Vozidlo("SPKAVA", 90, new Datum(31, 3, 2012)));
	spedicnaFirma->pridajVozidlo(new Vozidlo("SPCAJ", 90, new Datum(1, 10, 1989)));
	spedicnaFirma->pridajVozidlo(new Vozidlo("SPMACKA", 90, new Datum(31, 3, 2012)));
	spedicnaFirma->pridajVozidlo(new Vozidlo("SPSOJKA", 900, new Datum(26, 3, 2017)));
	spedicnaFirma->pridajVozidlo(new Vozidlo("SPPYTHON", 100, new Datum(31, 3, 2012)));
}
