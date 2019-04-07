#pragma once
#include <string>
#include <list>
#include <iostream>

using namespace std;

class Profesor
{
public:
	string nombre;
	string apellido1;
	string apellido2;
	string correo;
	list<pair<int,int>> grado;
	bool doctor;

	Profesor(string, string, string, string, string);
	~Profesor();
	void printProfesor();
	void addGrado(string grado, string nTFG);
};

