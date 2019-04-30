#include "Grado.h"

Grado::Grado(string nombre)
{
	this->nombre = nombre;
}

Grado::~Grado()
{
}

void Grado::setNombre(string nombre)
{
	this->nombre = nombre;
}

string Grado::getNombre()
{
	return this->nombre;
}

void Grado::printGrado()
{
	std::cout<< "Nombre:" << this->nombre << "\n";
}
