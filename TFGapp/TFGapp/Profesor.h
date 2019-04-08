#pragma once
#include <string>
#include <list>
#include <iostream>

using namespace std;

class Profesor
{
private:
	string nombreCompleto;
	bool doctor;
	list<pair<int, int>> grado;
public:
	Profesor(string, string);
	~Profesor();
	void printProfesor();
	void addGrado(string grado, string nTFG);

	string getNombre();
	void setNombre(string);

	bool getDoctor();
	void setDoctor(bool);
};

