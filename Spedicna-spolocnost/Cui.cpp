#include "Cui.h"



Cui::Cui()
{
	system("cls");
	spedFirma_ = new Firma(1, 1, 2017, 10);
	test = new Testing(spedFirma_);
	vypisMenu();
}


Cui::~Cui()
{
	delete spedFirma_;
	delete test;
}

void Cui::vypisMenu()
{
	int vyberMenuMoznosti;
	spedFirma_->vypisPeknuUvodnuObrazovku();
	cout << " -------------------------------------------------- " << endl;
	cout << "  1 > POSUN na dalsi DEN " << endl;
	cout << "  2 > Vypis zoznam vozidiel zaradenych do EVIDENIE " << endl; // ULOHA 2
	cout << "  3 > Vypisanie zoznamu dodavatelov " << endl; // ULOHA 4
	cout << "  4 > Vypisanie paliet ulozene v centralnom sklade " << endl; // ULOHA 11
	cout << "  5 > Dodavatel s naj. mnozstvom neprev. paliet " << endl; // ULOHA 12
	cout << "  6 > Nezrealizovane palety 1. triedy " << endl; // ULOHA 13
	cout << "  7 > OHLASENIE kamionov s paletami " << endl; // ULOHA 5
	cout << "  8 > EVIDENCIA prichodu kamionov " << endl; // ULOHA 6
	cout << "  9 > Zahajit transport paliet k ZAKAZNIKOM " << endl << endl; // ULOHA 7, 8, 9
	cout << " <><><><><><><><><><><><><><><><><><><><><><><><><>" << endl << endl;
	cout << " 10 > Pridanie VOZIDLA do FIRMY " << endl; // ULOHA 1
	cout << " 11 > Pridaj DODAVATELA " << endl; // ULOHA 3
	cout << " 12 > Vyradenie vozidiel z FRONTU na odpis " << endl; // ULOHA 10
	cout << " 13 > NACITAT ULOZENE DATA " << endl;
	cout << " 14 > ULOZIT NOVE DATA " << endl;
	cout << " 15 > NACITAJ DEMO DATA " << endl;
	cout << " 16 > UKONCIT aplikaciu " << endl;
	cout << " -------------------------------------------------- " << endl << endl;
	cout << " >>> ";

	for (;;) {
		if (cin >> vyberMenuMoznosti) {
			break;
		}
		else {
			cout << "Prosim Vas, vyberte jednu z moznosti !" << endl;
			cout << " >>> ";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
	}

	switch (vyberMenuMoznosti)
	{
	case 10:
		system("cls");
		pridajVozidloScreen();
		break;
	case 2:
		system("cls");
		spedFirma_->vypisVozidlaPodlaDatEv();
		vycistiScreenDajMenu();
		break;
	case 11:
		system("cls");
		pridajDodavatelaScreen();
		break;
	case 3:
		system("cls");
		spedFirma_->vypisDodavatelov();
		vycistiScreenDajMenu();
		break;
	case 7:
		system("cls");
		spedFirma_->ohlaseniePrichoduKamionov();
		vycistiScreenDajMenu();
		break;
	case 8:
		system("cls");
		spedFirma_->skontrolujPrichodyKamionov();
		vycistiScreenDajMenu();
		break;
	case 9:
		system("cls");
		spedFirma_->pripravaARozvoz();
		vycistiScreenDajMenu();
		break;
	case 12:
		system("cls");
		spedFirma_->vyradenieVozidiel();
		vycistiScreenDajMenu();
		break;
	case 4:
		system("cls");
		spedFirma_->vypisPalietVCentralnomSklade();
		vycistiScreenDajMenu();
		break;
	case 5:
		system("cls");
		spedFirma_->vyhladanieDodavatelaNajviacNepPaliet();
		vycistiScreenDajMenu();
		break;
	case 6:
		system("cls");
		spedFirma_->vypisPaliet1TriedyNezrealizovane();
		vycistiScreenDajMenu();
		break;
	case 13:
		system("cls");
		//test->pripravTestovacieData();
		if (SuborIO::nacitajZoSuboru(spedFirma_, "save.txt"))
			cout << "Systemove data boli uspesne nacitane" << endl;
		else
			cout << "Systemove data neboli nacitane" << endl;


		vycistiScreenDajMenu();
		break;
	case 14:
		system("cls");
		if (SuborIO::ulozDoSuboru(spedFirma_))
			cout << "Systemove data boli uspesne ulozene" << endl;
		else
			cout << "Systemove data neboli ulozene kvoli neznamej chybe" << endl;

		vycistiScreenDajMenu();
		break;
	case 15:
		system("cls");
		//test->pripravTestovacieData();
		if (SuborIO::nacitajZoSuboru(spedFirma_, "demo.txt"))
			cout << "DEMO data boli uspesne nacitane" << endl;
		else
			cout << "DEMO data neboli nacitane" << endl;

		vycistiScreenDajMenu();
		break;
	case 1:
		system("cls");
		spedFirma_->posunNaDalsiDen();
		system("cls");
		vypisMenu();
		break;
	case 16:
		system("cls");
		cout << endl << ">>>>> DAKUJEM VAM ZA UZIVANIE TOHTO SOFTWARU A ZELAM PEKNY DEN <<<<<" << endl << endl;
		system("pause");
		break;
	default:
		system("cls");
		vypisMenu();
		break;
	}
}

void Cui::vycistiScreenDajMenu()
{
	system("pause");
	system("cls");
	vypisMenu();
}

void Cui::pridajVozidloScreen()
{

	// TODO VYTVORIT OVEROVACU FUNKCIONALITU NA INTEGRE, DATUM
	string spzVozidla;
	int nosnost;
	int den;
	int mesiac;
	int rok;
	int volbaUlozenie;

	system("cls");
	cout << " -------------------------------------------------- " << endl;
	cout << " Pridanie VOZIDLA do firmy <<<<<<<<<<<<<<<<<<<<<<<<" << endl << endl;
	cout << " 1 - Zadajte SPZ vozidla: " << endl << endl;
	cout << " >>> ";
	cin.ignore();
	getline(cin,spzVozidla); // CELY RIADOK, CELY STRING MOTHER FUCKER BUG
	cout << endl;
	cout << " > Zadali ste SPZ: " << spzVozidla << endl << endl;
	cout << " 2 - Zadajte nostnost vozidla: " << endl << endl;
	cout << " >>> ";

	for (;;) {
		if (cin >> nosnost && nosnost > 0) {
			break;
		}
		else {
			cout << endl << "Zadajte skutocnu hmotnost, ktora je vacsia ako 0!" << endl << endl;
			cout << " >>> ";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
	}

	cout << endl;
	cout << " > Zadali ste nosnot: " << nosnost << endl << endl;
	cout << " 3 - Zadajte datum evidencie vozidla " << endl;
	cout << " ---- DEN: ";
	for (;;) {
		if (cin >> den && den > 0 && den < 31) {
			break;
		}
		else {
			cout << endl << "Zadajte den v rozmedzi 1-30" << endl << endl;
			cout << " >>> ";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
	}
	cout << " ---- MES: ";
	for (;;) {
		if (cin >> mesiac && den > 0 && mesiac < 13) {
			break;
		}
		else {
			cout << endl << "Zadajte mesiac v rozmedzi 1-12" << endl << endl;
			cout << " >>> ";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
	}
	cout << " ---- ROK: ";
	for (;;) {
		if (cin >> rok && rok > 0) {
			break;
		}
		else {
			cout << endl << "Zadajte skutnocny rok" << endl << endl;
			cout << " >>> ";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
	}
	cout << endl << endl;
	cout << " Zadali ste nasledujuci datum: " << den << "." << mesiac << "." << rok << endl << endl;
	cout << endl << endl;
	cout << " PRAJETE SI ULOZIT VOZIDLO ----> 1. ANO | 2. NIE " << endl;
	cout << " >>> ";
	for (;;) {
		if (cin >> volbaUlozenie) {
			break;
		}
		else {
			cout << endl << "Prosim, vyberte spravnu volbu" << endl << endl;
			cout << " >>> ";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
	}

	switch (volbaUlozenie)
	{
	case 1:
		spedFirma_->pridajVozidlo(new Vozidlo(spzVozidla, nosnost, new Datum(den, mesiac, rok)));
		cout << " Vozidlo bolo uspesne ulozene do systemu " << endl << endl;
		system("pause");
		system("cls");
		vypisMenu();
		break;
	case 2:
		system("cls");
		cout << " Vozidlo nebolo ulozene " << endl << endl;
		system("pause");
		system("cls");
		vypisMenu();
		break;
	default:
		break;
	}

}

void Cui::pridajDodavatelaScreen()
{
	string nazov;
	string adresa;
	int pocetK;

	system("cls");
	cout << " -------------------------------------------------- " << endl;
	cout << " Pridanie DODAVATELA do firmy <<<<<<<<<<<<<<<<<<<<<" << endl << endl;
	cout << " 1 - Zadajte Obchodne MENO " << endl << endl;
	cout << " >>> ";
	cin.ignore();
	getline(cin, nazov); // CELY RIADOK, CELY STRING MOTHER FUCKER BUG
	cout << endl << endl;
	cout << " 2 - Zadajte adresu: " << endl << endl;
	cout << " >>> ";
	cin.ignore();
	getline(cin, adresa); // CELY RIADOK, CELY STRING MOTHER FUCKER BUG
	cout << endl << endl;
	cout << " 3 - Pocet kamionov: " << endl << endl;
	cout << " >>> ";
	Dodavatel * dodavatel = new Dodavatel(nazov, adresa);

	for (;;) {
		if (cin >> pocetK) {
			for (int i = 0; i < pocetK; i++)
			{
				Kamion *kam;
				int nosnost;
				int paDen;
				int paMes;
				int paRok;
				int pocetPaliet;

				cout << "  - Kamion " << i + 1 << " nosnost: " << endl << endl;
				cout << "  >>> ";
				for (;;) {
					if (cin >> nosnost) {
						break;
					}
					else {
						cout << endl << "Zadajte realnu hmotnost" << endl << endl;
						cout << " >>> ";
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
					}
				}
				cout << "  Prichod do skladu: " << endl << endl;
				cout << " ---- DEN: ";
				for (;;) {
					if (cin >> paDen && paDen > 0 && paDen < 31) {
						break;
					}
					else {
						cout << endl << "Zadajte den v rozmedzi 1-30" << endl << endl;
						cout << " >>> ";
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
					}
				}
				cout << " ---- MES: ";
				for (;;) {
					if (cin >> paMes && paMes > 0 && paMes < 13) {
						break;
					}
					else {
						cout << endl << "Zadajte mesiac v rozmedzi 1-12" << endl << endl;
						cout << " >>> ";
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
					}
				}
				cout << " ---- ROK: ";
				for (;;) {
					if (cin >> paRok && paRok > 0) {
						break;
					}
					else {
						cout << endl << "Zadajte skutnocny rok" << endl << endl;
						cout << " >>> ";
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
					}
				}

				cout << "  Pocet paliet: " << endl << endl;
				cout << "  >>> ";

				for (;;) {
					if (cin >> pocetPaliet && pocetPaliet > 0) {
						kam = new Kamion(nosnost, paDen, paMes, paRok);

						for (int j = 0; j < pocetPaliet; j++)
						{
							int palHmotnost;
							int palDen;
							int palMes;
							int palRok;
							int palReg;
							int palPriorita;

							cout << "   Paleta " << j + 1 << " ID region: " << endl << endl;
							cout << "   >>> ";

							for (;;) {
								if (cin >> palReg && palReg > 0 && palReg <= spedFirma_->getPocetRegionov()) {
									break;
								}
								else {
									cout << endl << "Zadajte ID regionu palety od 1 po N" << endl << endl;
									cout << " >>> ";
									cin.clear();
									cin.ignore(numeric_limits<streamsize>::max(), '\n');
								}
							}

							cout << "   Paleta " << j + 1 << " hmotnost: " << endl << endl;
							cout << "   >>> ";

							for (;;) {
								if (cin >> palHmotnost && palHmotnost > 0) {
									break;
								}
								else {
									cout << endl << "Zadajte existujucu hmotnost !" << endl << endl;
									cout << " >>> ";
									cin.clear();
									cin.ignore(numeric_limits<streamsize>::max(), '\n');
								}
							}

							cout << "   Paleta " << j + 1 << " priorita (1-ano | 0-nie): " << endl << endl;
							cout << "   >>> ";

							for (;;) {
								if (cin >> palPriorita && (palPriorita == 0 || palPriorita == 1)) {
									break;
								}
								else {
									cout << endl << "Zadajte bud 0 alebo 1" << endl << endl;
									cout << " >>> ";
									cin.clear();
									cin.ignore(numeric_limits<streamsize>::max(), '\n');
								}
							}

							if (palPriorita == 0)
							{
								if (!kam->nalozPaletu(new Paleta(palHmotnost, palReg)))
									break;
							}
							else 
							{
								cout << "   Paleta 1.trieda prichod " << endl << endl;
								cout << "    ---- DEN: ";
								for (;;) {
									if (cin >> palDen && palDen > 0 && palDen < 31) {
										break;
									}
									else {
										cout << endl << "Zadajte den v rozmedzi 1-30" << endl << endl;
										cout << " >>> ";
										cin.clear();
										cin.ignore(numeric_limits<streamsize>::max(), '\n');
									}
								}
								cout << "    ---- MES: ";
								for (;;) {
									if (cin >> palMes && palMes > 0 && palMes < 13) {
										break;
									}
									else {
										cout << endl << "Zadajte mesiac v rozmedzi 1-12" << endl << endl;
										cout << " >>> ";
										cin.clear();
										cin.ignore(numeric_limits<streamsize>::max(), '\n');
									}
								}
								cout << "    ---- ROK: ";
								for (;;) {
									if (cin >> palRok && palRok > 0) {
										break;
									}
									else {
										cout << endl << "Zadajte skutnocny rok" << endl << endl;
										cout << " >>> ";
										cin.clear();
										cin.ignore(numeric_limits<streamsize>::max(), '\n');
									}
								}

								if (!kam->nalozPaletu(new Paleta(palHmotnost, palReg, palDen, palMes, palRok)))
									break;
							}
						}
						break;
					}
					else {
						cout << endl << "Prosim, zadajte spravny pocet paliet ktore kamion moze odviest" << endl << endl;
						cout << " >>> ";
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
					}
				}

				dodavatel->zaradKamionDoPrevadzky(kam);
			}
			break;
		}
		else {
			cout << endl << "Zadajte realny pocet kamionov" << endl << endl;
			cout << " >>> ";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
	}

	int moznost;
	cout << endl << endl;
	cout << " ULOZIT DODAVATELA? 1-ANO, 0-NIE" << endl << endl;
	cout << " >>> ";
	for (;;) {
		if (cin >> moznost && (moznost == 0 || moznost == 1)) {
			break;
		}
		else {
			cout << endl << "Moznost moze by 1, alebo 0" << endl << endl;
			cout << " >>> ";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
	}

	if (moznost == 0)
	{
		cout << "DODAVATEL nebol ulozeny";
		delete dodavatel;
		system("pause");
		system("cls");
		vypisMenu();
	}
	else
	{
		spedFirma_->pridajDodavatela(dodavatel);
		cout << "DODAVATEL bol ulozeny";
		system("pause");
		system("cls");
		vypisMenu();
	}
}
