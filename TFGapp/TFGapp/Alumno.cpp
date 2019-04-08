#include "Alumno.h"

Alumno::Alumno(string nombre, string apellido1, string apellido2, string correo, string grado)
{
	this->nombre = nombre;
	this->apellido1 = apellido1;
	this->apellido2 = apellido2;
	this->correo = correo;
	this->grado = stoi(grado);
}

void Alumno::printAlumno()
{

	std::cout << "-------------------" << '\n';
	std::cout << "Name: " << this->nombre << " " << this->apellido1 << " " << this->apellido2 << '\n';
	std::cout << "E-Mail: " << this->correo << '\n';
	std::cout << "Grado: " << this->grado << '\n';
	std::cout << "-------------------" << '\n';
}