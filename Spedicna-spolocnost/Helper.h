#pragma once
#include <random>
#include "Datum.h"
#include "structures\list\list.h"
#include "structures\heap_monitor.h"
#include "structures\priority_queue\priority_queue.h"


using namespace structures;

// TRIEDA HELPER SLUZI NA JEDNODUCHE VYPOCTOVE OPERACIE
class Helper
{
public:
	static bool odmietnemZasielku();
	static int vypocitajPriorituDatumu(Datum *paDatum);
	~Helper();

	template<typename T>
	static void vymazList(List<T*>* paList);

	template<typename T>
	static void vycistiList(List<T*>* paList);

	template<typename T>
	static void vymazHeap(PriorityQueue<T*>* paHeap);

	template<typename T>
	static void vycistiHeap(PriorityQueue<T*>* paHeap);

private:
	Helper(); // Prevencia, aby sme predisli instanci a vyuzivali triedu len na STATICKE METODY.
};

template<typename T>
inline void Helper::vymazList(List<T*>* paList)
{
	for each (auto pas in *paList)
	{
		delete pas;
	}

	delete paList;
}

template<typename T>
inline void Helper::vycistiList(List<T*>* paList)
{
	for each (auto pas in *paList)
	{
		delete pas;
	}
	paList->clear();
}

template<typename T>
inline void Helper::vymazHeap(PriorityQueue<T*>* paHeap)
{
	while (paHeap->size())
	{
		delete paHeap->pop();
	}

	delete paHeap;
}

template<typename T>
inline void Helper::vycistiHeap(PriorityQueue<T*>* paHeap)
{
	while (paHeap->size())
	{
		delete paHeap->pop();
	}

	paHeap->clear();
}
