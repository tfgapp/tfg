#pragma once
#include <string>
#include <iostream>
#include "Grado.h"

using namespace std;

class Alumno
{

private:
	string nombre;
	string apellido;
	string ID;
	Grado * grado;
public:
	Alumno(string,string,string,Grado*);
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

