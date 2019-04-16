#pragma once
#include <string>
#include <iostream>
#include <vector>
#include "Profesor.h"

using namespace std;

class Presentaciom {

private:

	string ID;
	int hora;
	int dia;
	int aula;
	int slot;
	int convocatoria;
	vector<Profesor> tribunal; //Lista de profesores que acuden a la presentación

};