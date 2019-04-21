#pragma once
#include <stdio.h>
class Profesor;

class Horario
{
private:
	int dia;
	bool sloots[7];
	Profesor *profesor;

public:

	Profesor * getProfesor();
	void setProfesor(Profesor *profesor);

	int getDia();
	void setDia(int dia);
	bool* getListaSloot();
	bool getSloot(int posicion);
	void setSloot(int posicion, bool valor);
	Horario(int dia, bool *sloots);
	Horario(int dia);
	Horario();
	~Horario() {};
};

