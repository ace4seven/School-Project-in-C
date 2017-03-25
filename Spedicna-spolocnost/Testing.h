#pragma once
#include <iostream>
#include <string>
#include "Firma.h"
#include "Helper.h"
#include "structures\heap_monitor.h"


class Testing
{
public:
	Testing(Firma *paFirma);
	~Testing();

	void pripravTestovacieData();
private:
	Firma *spedicnaFirma;
};

