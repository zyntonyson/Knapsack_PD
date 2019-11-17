#pragma once
#include "PdMData.h"
#include <algorithm>

class PdSolver
{
	PdMData *_data;
	int **_summary;

public:
	PdSolver(PdMData *data);
	~PdSolver();
	void print_sol();
	void items_in();
};

