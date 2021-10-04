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
	/// <summary> Konstruktor</summary>
	/// <param name = "paIdRegion"> Celociselne kladne ID regionu </param>
	Region(int paIdRegion);
	/// <summary> Destruktor</summary>
	~Region();

	/// <summary> Vrati ID regionu</summary>
	/// <returns> Celociselne kladne ID </returns>
	int getIdRegionu();
	/// <summary> VVrati prioritny front uskladnenych paliet do tohto regionu.</summary>
	/// <returns> Prioritny front paliet </returns>
	Heap<Paleta*> *getUskladnenePalety();

	/// <summary> Prida paletu do Prioritneho frontu</summary>
	/// <param name = "paPaleta"> Paleta </param>
	/// <param name = "paTypPriority"> Typ priority - 0 = Ziadna priorita, 1 = 1.Trieda </param>
	void pridajPaletuNaSklad(Paleta *paPaleta, int paTypPriority);

private:
	/// <summary> Celociselne ID regionu</summary>
	int idRegion_;
	/// <summary> Prioritny FRONT paliet</summary>
	Heap<Paleta*> *uskladnenePalety_;
};

