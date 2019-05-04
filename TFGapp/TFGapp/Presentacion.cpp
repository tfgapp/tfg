#include "Presentacion.h"

Presentacion::Presentacion()
{
	this->hora = 0;
	this->dia = 0;
	this->aula = 0;
	this->slot = 0;
	this->convocatoria = 0;
}

void Presentacion::addTribunal(Profesor* tribunal)
{
	this->tribunal.push_back(tribunal);
}

vector<Profesor*> * Presentacion::getTribunal()
{
	return &this->tribunal;
}

void Presentacion::setID(string id) {
	this->ID = id;
}

void Presentacion::setHora(int hor) {
	this->hora = hor;
}

void Presentacion::setDia(int day) {
	this->dia = day;
}

void Presentacion::setAula(int aul) {
	this->aula = aul;
}

void Presentacion::setSlot(int slo) {
	this->slot = slo;
}

void Presentacion::setConvocatoria(int conv) {
	this->convocatoria = conv;
}

string Presentacion::getID() {
	return this->ID;
}

int Presentacion::getHora() {
	return this->hora;
}

int Presentacion::getDia() {
	return this->dia;
}

int Presentacion::getAula() {
	return this->aula;
}

int Presentacion::getSlot() {
	return this->slot;
}

int Presentacion::getConvocatoria() {
	return this->convocatoria;
}

void Presentacion::delTribunal(string idProfesor)
{
	for (int i = 0; i < tribunal.size(); i++)
	{
		if (tribunal[i]->getNombre() == idProfesor)
			tribunal.erase(tribunal.begin() + i);
	}
}
