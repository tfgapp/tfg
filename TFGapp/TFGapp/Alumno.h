#pragma once
#include <string>
#include <iostream>

using namespace std;

class Alumno
{

public:
	string nombre;
	string apellido1;
	string apellido2;
	string correo;
	int grado;

	Alumno(string,string,string,string,string);
	void printAlumno();
	~Alumno() {};
};

