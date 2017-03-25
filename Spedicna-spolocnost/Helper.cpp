#include "Helper.h"



Helper::Helper()
{
}


bool Helper::odmietnemZasielku() // POKIAL nahodne vygenerujem cislo od 1 do 5, zakaznik zasielku odmietne.
{
	return (std::rand() % 100 + 1) > 5 ? false : true;
}

int Helper::vypocitajPriorituDatumu(Datum * paDatum) // Nastavi prioritu kazdeho datumu, cim vyssia priorita, tym skorsi datum.
{
	return paDatum->getRok() * 700 + paDatum->getMesiac() * 50 + paDatum->getDen();
}

Helper::~Helper()
{
}
