#include "PdMData.h"
#include "PdSolver.h"


int main()
{
	PdMData *t08;
	t08 = new PdMData("T8.dat");

	PdSolver *ejercicio;
	ejercicio = new PdSolver(t08);
	ejercicio->print_sol();
	ejercicio->items_in();

	system("pause");
	return 0;
}