#pragma once
#include <string>
#include <vector>
#include <iostream>
#include "Grado.h"
#include "Horario.h"

using namespace std;

class Profesor
{
private:
	string nombreCompleto;
	bool doctor;
	vector<Grado *> grados;
	vector<int> nTFG;
	int ID;
	vector<Horario> horarios; //Faltan las funciones


public:
	Profesor() {};
	Profesor(string, string);
	~Profesor();
	void printProfesor();
	void setID(int);
	

	string getNombre();
	void setNombre(string);

	bool getDoctor();
	void setDoctor(bool);

	void addGrado(Grado* grado, int nTFG);
	void delGrado(string id);
};

