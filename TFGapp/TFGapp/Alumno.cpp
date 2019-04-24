#include "Alumno.h"

Alumno::Alumno(string nombre, string apellido, string ID, Grado * grado)
{
	this->nombre = nombre;
	this->apellido = apellido;
	this->ID = ID;
	this->grado = grado;
}

void Alumno::printAlumno()
{

	std::cout << "-------------------" << '\n';
	std::cout << "Name: " << this->nombre << " " << this->apellido << '\n';
	std::cout << "E-Mail: " << this->ID << '\n';
	std::cout << "Grado: " << this->grado->getNombre() << '\n';
	std::cout << "-------------------" << '\n';
}

void Alumno::setNombre(string nombre)
{
	this->nombre = nombre;
}

void Alumno::setApellido(string apellido)
{
	this->apellido = apellido;
}

void Alumno::setID(string ID)
{
	this->ID = ID;
}

void Alumno::setGrado(Grado * grado)
{
	this->grado = grado;
}

string Alumno::getNombre()
{
	return this->nombre;
}

string Alumno::getApellido()
{
	return this->apellido;
}

string Alumno::getID()
{
	return this->ID;
}

Grado * Alumno::getGrado()
{
	return this->grado;
}
