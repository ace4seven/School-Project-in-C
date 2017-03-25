#include <iostream>
#include "structures\heap_monitor.h"
#include "Testing.h"
#include "Cui.h"

using namespace std;
int main()
{
	initHeapMonitor();
	Cui *program = new Cui();
	delete program;

	return 0;
}