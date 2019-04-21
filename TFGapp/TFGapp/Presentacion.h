#pragma once
#include <string>
#include <iostream>
#include <vector>
#include "Profesor.h"

using namespace std;

class Presentacion {

private:

	string ID;
	int hora;
	int dia;
	int aula;
	int slot;
	int convocatoria;
	vector<Profesor *> tribunal; //Lista de profesores que acuden a la presentación

public:
	//getters y setters
	void setTribunal(vector<Profesor*>);
	void setID(string);
	void setHora(int);
	void setDia(int);
	void setAula(int);
	void setSlot(int);
	void setConvocatoria(int);

	string getID();
	int getHora();
	int getDia();
	int getAula();
	int getSlot();
	int getConvocatoria();
	vector<Profesor *> getTribunal();

};