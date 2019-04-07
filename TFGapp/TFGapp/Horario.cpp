#include "Horario.h"


//Los tres constructores
Profesor Horario::getProfesor() {
	return *profesor;
}
void Horario::setProfesor(Profesor *profesor) {
	this->profesor = profesor;
}
Horario::Horario(int dia, bool *sloots) {

	this->dia = dia;
	for (int i = 0; i < 7; i++)this->sloots[i] = 0;
	for (int i = 0; i < 7; i++)this->sloots[i] = sloots[i];
}
Horario::Horario(int dia) {
	this->dia = dia;
}
Horario::Horario() {
	this->dia = 0;
	for (int i = 0; i < 7; i++)this->sloots[i] = 0;
}
//set y get
int Horario::getDia() {
	return dia;
}
void Horario::setDia(int dia) {
	this->dia = dia;
}
bool* Horario::getSloot() {
	return sloots;
}
bool Horario::getSloot(int posicion) {
	if (posicion < 0 || posicion>7) {
		printf("Error en el rango de posicion");
	}
	return sloots[posicion];
}
void Horario::setSlooot(int posicion, bool valor) {
	if (posicion < 0 || posicion>7) {
		printf("Error en el rango de posicion");
	}
	sloots[posicion] = valor;
}