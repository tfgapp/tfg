#include "Profesor.h"



Profesor::Profesor(string nombre, string apellido1, string apellido2, string correo, string doctor)
{
	this->nombre = nombre;
	this->apellido1 = apellido1;
	this->apellido2 = apellido2;
	this->correo = correo;
	this->doctor = (doctor == "1" ) ? true : false;
}


Profesor::~Profesor()
{
}

void Profesor::addGrado(string grado, string nTFG)
{
	pair<int, int> dummy;

	dummy.first = stoi(grado);
	dummy.second = stoi(grado);
	this->grado.push_back(dummy);
	this->grado.unique();

}

void Profesor::printProfesor()
{

	std::cout << "-------------------" << '\n';
	std::cout << "Name: " << this->nombre << " " << this->apellido1 << " " << this->apellido2 << '\n';
	std::cout << "E-Mail: " << this->correo << '\n';
	std::cout << "Doctor: " << this->doctor << '\n';
	for (auto dummy : this->grado)
	{
		std::cout << "Grado: " << dummy.first <<"  nMAX: " << dummy.second <<  '\n';
	}
	std::cout << "-------------------" << '\n';
}