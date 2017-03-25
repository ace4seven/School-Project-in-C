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
	~SuborIO();
	static bool ulozDoSuboru(Firma *spedFirma);
	static bool nacitajZoSuboru(Firma *spedFirma); // Nacita ulozene data zo suboru saveData.txt do FIRMY
private:
	SuborIO();
	static vector<string> split(const string &text, char sep);
};

