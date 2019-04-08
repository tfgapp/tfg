#include "Header.h"

Horario * UTILITY existeHorario(list<Horario> *lista, string nombre, string dia) {
	for (auto iterator = lista->begin(), end = lista->end(); iterator != end; ++iterator) {
		string nombreCompleto = (*iterator).getProfesor().getNombre();
		if (nombreCompleto == nombre && to_string((*iterator).getDia()) == dia)
			return &(*iterator);
	}
	return NULL;
}

Profesor * UTILITY existeProfesor(list<Profesor> *lista, string ID)
{
	for (auto iterator = lista->begin(), end = lista->end(); iterator != end; ++iterator)
		if ((*iterator).getNombre() == ID)
			return &(*iterator);
	return NULL;
}