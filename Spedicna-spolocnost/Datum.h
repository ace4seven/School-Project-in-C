#pragma once
#include "structures\heap_monitor.h"
#include <string>



class Datum
{
public:
	Datum();
	Datum(int paDen, int paMes, int paRok);
	~Datum();

	void posunOJedenDen();
	std::string vratRetazec();

	bool operator==(const Datum &other) const;
	bool operator<(const Datum &other) const;
	bool operator>(const Datum &other) const;

	// GETERY
	int getDen();
	int getMesiac();
	int getRok();

	// SETERY
	void setUpravDatum(int den, int mesiac, int rok);

private:
	int den_;
	int mes_;
	int rok_;
};

