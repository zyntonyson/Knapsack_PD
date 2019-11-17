#include "PdMData.h"



PdMData::PdMData(string dat)
{
	_file = dat;
	ifstream ifile(dat.c_str(), ios::in);
	if (ifile.fail()) {
		cout << "Error en archivo: " << dat << endl;
		system("pause");
		exit(0);
	}

	ifile >> _nItems;
	ifile >> _Capacity;

	_beneficio = new int[_nItems];
	_costo = new int[_nItems];
	_tareas = new char[_nItems];

	for (int i = 0; i < _nItems; i++) {
		ifile >> _tareas[i];
		ifile >> _costo[i];
		ifile >> _beneficio[i];
	}
	print_data();
	ifile.close();


}


PdMData::~PdMData()
{
}

void PdMData::print_data()
{

	cout << "Archivo: " << _file << endl;
	cout << "Numero de objetos: " << _nItems << endl;
	cout << "Capacidad: " << _Capacity << endl;

	cout << "Tarea \t Beneficio \t Peso \t" << endl;

	for (int i = 0; i < _nItems; i++) {
		cout << _tareas[i] << "\t" << _beneficio[i] << "\t" << _costo[i] << endl;
	}

}
