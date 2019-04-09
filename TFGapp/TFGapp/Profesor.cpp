#include "Profesor.h"

Profesor::Profesor(string nombre, string doctor)
{
	this->nombreCompleto = nombre;
	this->doctor = (doctor == "1" ) ? true : false;
}

Profesor::~Profesor()
{
}

void Profesor::printProfesor()
{

	std::cout << "-------------------" << '\n';
	std::cout << "Name: " << this->nombreCompleto << '\n';
	std::cout << "Doctor: " << this->doctor << '\n';
	for (auto dummy : this->grado)
	{
		std::cout << "Grado: " << dummy.first <<"  nMAX: " << dummy.second <<  '\n';
	}
	std::cout << "-------------------" << '\n';
}

string Profesor::getNombre()
{
	return this->nombreCompleto;
}

void Profesor::setNombre(string nombreCompleto)
{
	this->nombreCompleto = nombreCompleto;
}

bool Profesor::getDoctor()
{
	return this->doctor;
}

void Profesor::setDoctor(bool doctor)
{
	this->doctor = doctor;
}