#include "Presentacion.h"

void Presentacion::setTribunal(vector<Profesor*> tribunal)
{
	this->tribunal = tribunal;
}

vector<Profesor*> Presentacion::getTribunal()
{
	return this->tribunal;
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
