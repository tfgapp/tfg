#pragma once
#include <string>

using namespace std;

class Grado
{
private:
	string nombre;
public:
	Grado(string nombre);
	~Grado();

	void setNombre(string nombre); 
	string getNombre();
};

