#include "PdSolver.h"




PdSolver::PdSolver(PdMData *data)
{
	_data = data;

	// Cargar datos
	int aux,aux1,aux2;
	int nItems = _data->get_nItems();
	int Capacidad = _data->get_capacity();
	
	
	// Iniciar matriz de resultados
	_summary = new int *[nItems + 1];
	for( int i=0;i< nItems + 1;i++)
	{
		_summary[i] = new int[Capacidad + 1];
		for (int j=0;j< Capacidad + 1;j++)
		{
			_summary[i][j] = 0;
		}// fin j
	}// fin i

	// Comienza algoritmo//


	for (int item = 1; item < nItems + 1; item++)
	{
		
		for (int Wb = 1; Wb < Capacidad + 1; Wb++)
		{
			if(_data->get_costo(item-1)>Wb)
			{
				_summary[item][Wb] = _summary[item - 1][Wb];
			} else
			{
				aux = _summary[item - 1][Wb - _data->get_costo(item - 1)] + _data->get_beneficio(item - 1);
				_summary[item][Wb] = max(_summary[item - 1][Wb], aux);
			}


		}// fin j
	}// fin i

	
}


PdSolver::~PdSolver()
{
	
}

void PdSolver::print_sol()
{
	cout << endl << endl;
	cout << "Tabla resumen" << endl;
	for (int i =0; i< _data->get_nItems()+1;i++)
	{
		for (int j = 0; j < _data->get_capacity() + 1; j++)
		{
			cout << _summary[i][j] <<" ";
		}
		 cout << endl;
	}
}

void PdSolver::items_in()
{
	cout << endl << "Tareas a realizar" << endl;
	int W = _data->get_capacity();
	for(int items = _data->get_nItems();items>0;items--)
	{
	
		if (_summary[items][W]!= _summary[items-1][W])
		{
			cout << _data->get_tarea(items - 1) << " ";
			W -= _data->get_costo(items - 1);
		}
	}
	cout << endl << endl;
}
