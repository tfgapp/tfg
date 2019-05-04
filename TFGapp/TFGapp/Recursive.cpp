#include "Header.h"

void prepareR(Controller * main, int convocatoria)
{
	//Seleccionar que alumnos van a ir en esta convocatoria
	vector<Alumno *> convocados;
	for (int i = 0; i < main->getListaAlumnos()->size(); i++) //Utilizo la lista completa de manager para test
	{
		convocados.push_back(&(*main->getListaAlumnos())[i]);
	}

}