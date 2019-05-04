#include "Presentacion.h"

Presentacion::Presentacion()
{
	this->hora = -1;
	this->dia = -1;
	this->aula = -1;
	this->slot = -1;
	this->convocatoria = -1;
}

void Presentacion::addTribunal(Profesor* tribunal)
{
	this->tribunal.push_back(tribunal);
}

vector<Profesor*> * Presentacion::getTribunal()
{
	return &this->tribunal;
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

void Presentacion::setAll(int dia, int slot, int convocatoria)
{
	this->dia = dia;
	this->aula = aula;
	this->slot = slot;
	this->convocatoria = convocatoria;
}

void Presentacion::reset()
{
	dia = -1;
	aula = -1;
	slot = -1;
	convocatoria = -1;
}