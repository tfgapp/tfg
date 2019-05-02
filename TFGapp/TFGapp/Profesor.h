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
	string nombreCompleto; //ID
	bool doctor;
	vector<Grado *> grados;
	vector<int> nTFG;
	vector<Horario> horarios;


public:
	Profesor() {};
	Profesor(string, string);
	~Profesor();
	void printProfesor();	

	string getNombre();
	void setNombre(string);

	bool getDoctor();
	void setDoctor(bool);

	void addGrado(Grado* grado, int nTFG);
	void delGrado(string id);
	vector<Grado *>* getListaGrados();

	void addHorario(Horario horario);
	Horario * getHorario(int dia);
	vector<Horario>* getListaHorarios();
	void delHorario(int dia);
};

