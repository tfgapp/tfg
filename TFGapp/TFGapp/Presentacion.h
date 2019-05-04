#pragma once
#include <string>
#include <iostream>
#include <vector>
#include "Profesor.h"

using namespace std;

class Presentacion {

private:
	int hora;
	int dia;
	int aula;
	int slot;
	int convocatoria;
	vector<Profesor *> tribunal;

public:
	Presentacion();
	void addTribunal(Profesor* tribunal);
	void delTribunal(string idProfesor);

	void setHora(int);
	void setDia(int);
	void setAula(int);
	void setSlot(int);
	void setConvocatoria(int);

	int getHora();
	int getDia();
	int getAula();
	int getSlot();
	int getConvocatoria();
	vector<Profesor*> * getTribunal();

	void setAll(int dia, int slot, int convocatoria);
	void reset();
};
