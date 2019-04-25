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
	for (int i = 0; i < this->grados.size(); i++)
	{
		std::cout << "Grado: " << this->grados[i]->getNombre() <<"  nMAX: " << this->nTFG[i] <<  '\n';
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

void Profesor::addGrado(Grado* grado, int nTFG)
{
	this->grados.push_back(grado);
	this->nTFG.push_back(nTFG);
}

void Profesor::delGrado(string id)
{
	for (int i = 0; i < (int)this->grados.size(); i++)
	{
		if (this->grados[i]->getNombre() == id)
		{
			this->grados.erase(this->grados.begin() + i);
			this->nTFG.erase(this->nTFG.begin() + i);
		}
	}
}

void Profesor::setID(int id) {
	this->ID = id;
}