#include "Header.h"

Horario * UTILITY existeHorario(vector<Horario> * horarios, string nombre, string dia)
{
	string nombreCompleto;
	for (int i = 0; i < (int)horarios->size(); i++)
	{
		nombreCompleto = (*horarios)[i].getProfesor()->getNombre();
		if (nombreCompleto == nombre && to_string((*horarios)[i].getDia()) == dia)
			return &(*horarios)[i];
	}
	return NULL;
}

Profesor * UTILITY existeProfesor(vector<Profesor> *profesores, string ID)
{
	for (int i = 0; i < (int)profesores->size(); i++)
		if ((*profesores)[i].getNombre() == ID)
			return &(*profesores)[i];
	return NULL;
}

Grado * UTILITY existeGrado(vector<Grado> *grados, string ID)
{
	for (int i = 0; i < (int)grados->size(); i++)
		if ((*grados)[i].getNombre() == ID)
			return &(*grados)[i];
	return NULL;
}
