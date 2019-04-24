#pragma once
#include <string>
#include <iostream>
#include "Grado.h"
#include "TFG.h"

using namespace std;

class Alumno
{
private:
	string nombre;
	string apellido;
	string ID;
	Grado * grado;
	TFG * tfg; //TODO

public:
	Alumno(string,string,string,Grado*);
	Alumno() {};
	void printAlumno();
	~Alumno() {};

	void setNombre(string nombre);
	void setApellido(string apellido);
	void setID(string ID);
	void setGrado(Grado * grado);

	string getNombre();
	string getApellido();
	string getID();
	Grado * getGrado();
};

