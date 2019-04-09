#pragma once
#include <string>
#include <vector>
#include <iostream>
#include "Grado.h"

using namespace std;

class Profesor
{
private:
	string nombreCompleto;
	bool doctor;
	vector<Grado *> grados;
	vector<int> nTFG;

public:
	Profesor(string, string);
	~Profesor();
	void printProfesor();

	string getNombre();
	void setNombre(string);

	bool getDoctor();
	void setDoctor(bool);

	void addGrado(Grado* grado, int nTFG);
	void delGrado(string id);

};

