#pragma once
#include <iostream>
#include <fstream>
#include <string>

using namespace std;


class PdMData
{
	int _Capacity;
	int _nItems;
	int *_beneficio;
	int *_costo;
	char *_tareas;
	string _file;

public:
	PdMData(string dat);
	~PdMData();
	void print_data();
	int get_capacity() { return _Capacity; };
	int get_nItems() { return _nItems; };
	int get_costo(int item) { return _costo[item]; };
	int get_beneficio(int item) { return _beneficio[item]; };
	char get_tarea(int item) { return _tareas[item]; };
};

