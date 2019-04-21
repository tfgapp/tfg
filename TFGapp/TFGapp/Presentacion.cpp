#include "Presentacion.h"

void Presentaciom::setID(string ID)
{
	this->ID = ID;
}

void Presentaciom::setHora(int hora)
{
	this->hora = hora;
}

void Presentaciom::setAula(int aula)
{
	this->aula = aula;
}

void Presentaciom::setSlot(int slot)
{
	this->slot = slot;
}

void Presentaciom::setConvocatoria(int convocatoria)
{
	this->convocatoria = convocatoria;
}

void Presentaciom::setTribunal(vector<Profesor*> tribunal)
{
	this->tribunal = tribunal;
}

string Presentaciom::getID()
{
	return this->ID;
}

int Presentaciom::getHora()
{
	return this->hora;
}

int Presentaciom::getAula()
{
	return this->aula;
}

int Presentaciom::getSlot()
{
	return this->slot;
}

int Presentaciom::getConvocatoria()
{
	return this->convocatoria;
}

vector<Profesor*> Presentaciom::getTribunal()
{
	return this->tribunal;
}
//Rodrigo: He creado todos los getters y setters de presentacion