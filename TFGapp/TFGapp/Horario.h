#pragma once
#include "Header.h"
class Horario
{
	int dia;
	bool sloots[7];
	Profesor *profesor;
public:
	Profesor getProfesor();
	void setProfesor(Profesor *profesor);
	int getDia();
	void setDia(int dia);
	bool* getSloot();
	bool getSloot(int posicion);
	void setSlooot(int posicion, bool valor);
	Horario(int dia, bool *sloots);
	Horario(int dia);
	Horario();
	~Horario() {};
};

