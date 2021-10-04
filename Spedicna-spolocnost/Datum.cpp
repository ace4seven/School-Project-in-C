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

void Datum::posunOJedenDen() 
{
	if (den_ == dniVMesiaci())
	{
		den_ = 1;
		if (mes_ < 12) 
			mes_ += 1;
		else 
		{
			mes_ = 1;
			rok_ += 1;
		}
	}
	else 
		den_ += 1;
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

bool Datum::jePriestupnyRok()
{
	return ((rok_ % 4 == 0) && (rok_ % 100 != 0)) || (rok_ % 400 == 0);
}

int Datum::dniVMesiaci()
{
	int cislo;

	switch (mes_) 
	{
	case 1:
		cislo = 31;
		break;
	case 2:
		if (jePriestupnyRok())
			cislo = 29;
		else 
			cislo = 28;
		break;
	case 3:
		cislo = 31;
		break;
	case 4:
		cislo = 30;
		break;
	case 5:
		cislo = 31;
		break;
	case 6:
		cislo = 30;
		break;
	case 7:
		cislo = 31;
		break;
	case 8:
		cislo = 31;
		break;
	case 9:
		cislo = 30;
		break;
	case 10:
		cislo = 31;
		break;
	case 11:
		cislo = 30;
		break;
	case 12:
		cislo = 31;
		break;
	default:
		cislo = 0;
		break;
	}

	return cislo;
}
