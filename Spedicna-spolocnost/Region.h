#pragma once
#include "structures\heap_monitor.h"
#include "structures\priority_queue\heap.h"
#include "Paleta.h"
#include "Vozidlo.h"
#include "Helper.h"


using namespace structures;

class Region
{
public:
	Region(int paIdRegion);
	~Region();

	// GETERY
	int getIdRegionu();
	Heap<Paleta*> *getUskladnenePalety();

	// Settery
	void pridajPaletuNaSklad(Paleta *paPaleta, int paTypPriority);

private:
	int idRegion_;
	Heap<Paleta*> *uskladnenePalety_;
};

