#pragma once
#include <string>
#include <iostream>

using namespace std;

class Grado
{
private:
	string nombre; //ID
public:
	Grado(string nombre);
	Grado() {};
	~Grado();

	void setNombre(string nombre); 
	string getNombre();
	void printGrado();
};

