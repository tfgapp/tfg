#pragma once
#include <string>
#include <iostream>
#include "Grado.h"
#include "TFG.h"
#include "Profesor.h"

using namespace std;

class Alumno
{

private:
	string nombre;
	string apellido;
	string ID;
	Grado * grado;
	Profesor * tutor;
	Profesor * coTutor;
	TFG * tfg;

public:
	Alumno(string,string,string,Grado*);
	void printAlumno();
	Alumno() {};
	~Alumno() {};

	void setNombre(string nombre);
	void setApellido(string apellido);
	void setID(string ID);
	void setGrado(Grado * grado);
	void asignarTutor(Profesor *profesor);
	void asignarCoTutor(Profesor *profesor);
	void setTFG(TFG *);

	string getNombre();
	string getApellido();
	string getID();
	Grado * getGrado();
	Profesor * getTutor();
	Profesor * getCoTutor();
	TFG * getTFG();
};

