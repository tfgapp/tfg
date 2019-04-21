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
	vector<Profesor *> tribunal; //Lista de profesores que acuden a la presentación
public:
	//getters y setters
	void setID(string ID);
	void setHora(int hora);
	void setDia(int dia);
	void setAula(int aula);
	void setSlot(int slot);
	void setConvocatoria(int convocatoria);
	void setTribunal(vector<Profesor*>);
	string getID();
	int getHora();
	int getDia();
	int getAula();
	int getSlot();
	int getConvocatoria();
	vector<Profesor *>getTribunal();
	//final getters y setters
};
