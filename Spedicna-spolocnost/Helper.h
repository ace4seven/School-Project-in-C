#pragma once
#include <random>
#include "Datum.h"
#include "structures\list\list.h"
#include "structures\heap_monitor.h"
#include "structures\priority_queue\priority_queue.h"


using namespace structures;

/// <summary> Pomocna trieda (STATIC) na pomocne operacie</summary>
class Helper
{
public:
	/// <summary> Desturktor</summary>
	~Helper();

	/// <summary> Generator odmietnutia zasielky. Generuje random od 1 do 100</summary>
	/// <returns> Cisla v rozmedzi 1 - 5 : TRUE, zvysok FALSE </returns>
	static bool odmietnemZasielku();
	/// <summary> Zmeni datum na cele kladne cislo -> prioritu</summary>
	/// <returns> cele kladne cislo</returns>
	static int vypocitajPriorituDatumu(Datum *paDatum);

	/// <summary> Prvok jednostranne zretazeneho zoznamu. </summary>
	/// <typeparam name = "T"> Typ dat ukladanych v prvku. </typepram>
	template<typename T>
	/// <summary> Vymaze zoznam a pamat</summary>
	/// <param name = "paList"> Zoznam </param>
	static void vymazList(List<T*>* paList);
	/// <summary> Prvok jednostranne zretazeneho zoznamu. </summary>
	/// <typeparam name = "T"> Typ dat ukladanych v prvku. </typepram>
	template<typename T>
	/// <summary> Vymaze polozky zoznamu </summary>
	/// <param name = "paList"> Zoznam</param>
	static void vycistiList(List<T*>* paList);
	/// <summary> Prvok jednostranne zretazeneho zoznamu. </summary>
	/// <typeparam name = "T"> Typ dat ukladanych v prvku. </typepram>
	template<typename T>
	/// <summary> Vymaze front a pamat</summary>
	/// <param name = "paHeap"> Zoznam </param>
	static void vymazHeap(PriorityQueue<T*>* paHeap);
	/// <summary> Prvok jednostranne zretazeneho zoznamu. </summary>
	/// <typeparam name = "T"> Typ dat ukladanych v prvku. </typepram>
	template<typename T>
	/// <summary> Vymaze polozky frontu </summary>
	/// <param name = "paList"> Prioritny front</param>
	static void vycistiHeap(PriorityQueue<T*>* paHeap);

private:
	/// <summary> Konstruktur (privatny), nieje mozne inicializovat objekt, nakolko sa budu vyuzivat iba staticke triedy </summary>
	Helper();
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
