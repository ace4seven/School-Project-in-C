#include "Region.h"



Region::Region(int paIdRegion):
	idRegion_(paIdRegion)
{
	uskladnenePalety_ = new Heap<Paleta*>();
}

Region::~Region()
{
	Helper::vymazHeap(uskladnenePalety_);
}

int Region::getIdRegionu()
{
	return idRegion_;
}

Heap<Paleta*> * Region::getUskladnenePalety()
{
	return uskladnenePalety_;
}

void Region::pridajPaletuNaSklad(Paleta * paPaleta, int paTypPriority)
{
	int priorita;
	if (paTypPriority == 1)
		priorita = paPaleta->getPriorita() == true ? Helper::vypocitajPriorituDatumu(paPaleta->getDatumDorucenia()) / 100 : paPaleta->getPrioritaPrichoduDoSkladu(); // Vypocita priority podla datumu, prioritne datumy este vydeli 100, aby sa zarucilo, ze budu vo fronte PRVE !!!
	if (paTypPriority == 2)
		priorita = paPaleta->getHmotnostPalety();
	else
		priorita = 0;
	uskladnenePalety_->push(priorita, paPaleta);
}
