#pragma once
#include <string>
#include <iostream>

using namespace std;

class Alumno
{

private:
	string nombre;
	string apellido;
	string ID;
	string grado;
public:
	Alumno(string,string,string, string);
	void printAlumno();
	~Alumno() {};

	void setNombre(string nombre);
	void setApellido(string apellido);
	void setID(string ID);
	void setGrado(string grado);

	string getNombre();
	string getApellido();
	string getID();
	string getGrado();
};

