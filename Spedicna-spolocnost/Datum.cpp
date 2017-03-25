#include "Datum.h"



Datum::Datum()
{

}

Datum::Datum(int paDen, int paMes, int paRok):
	den_(paDen), mes_(paMes), rok_(paRok)
{
}


Datum::~Datum()
{

}

void Datum::posunOJedenDen() // Toto mozem este urobit inteligentnejsie, aby vedelo dni v mesiaci a aj priestopny rok ...
{
	if (den_ == 30)
	{
		den_ = 1;
		if (mes_ == 12)
		{
			mes_ = 1;
			rok_++;
		}
		else
			mes_++;
	}
	else
		den_++;
}

std::string Datum::vratRetazec()
{
	return std::to_string(den_) + "." + std::to_string(mes_) + "." + std::to_string(rok_);
}

bool Datum::operator==(const Datum & other) const
{
	return this->den_ == other.den_ && this->mes_ == other.mes_ && this->rok_ == other.rok_;
}

bool Datum::operator<(const Datum & other) const
{
	if (this->rok_ < other.rok_)
		return true;
	if (this->mes_ < other.mes_)
		return true;
	if (this->den_ < other.den_)
		return true;

	return false;
}

bool Datum::operator>(const Datum & other) const
{
	if (this->rok_ > other.rok_)
		return true;
	if (this->mes_ > other.mes_)
		return true;
	if (this->den_ > other.den_)
		return true;

	return false;
}

int Datum::getDen()
{
	return this->den_;
}

int Datum::getMesiac()
{
	return this->mes_;
}

int Datum::getRok()
{
	return this->rok_;
}

void Datum::setUpravDatum(int den, int mesiac, int rok)
{
	den_ = den;
	mes_ = mesiac;
	rok_ = rok;
}
