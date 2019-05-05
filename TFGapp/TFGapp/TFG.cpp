#include "TFG.h"

TFG::TFG() 
{
	this->titulo = "  ";
	this->presentado = false;
	this->tutor = NULL;
	this->coTutor = NULL;
}

TFG::TFG(string titulo, bool pres) {

	this->titulo = titulo;
	this->presentado = pres;

} //Constructor con parametros

void TFG::setTitulo(string tit) 
{ 
	this->titulo = tit;
}

string TFG::getTitulo() 
{
	return titulo;
}

void TFG::setPresentado(bool pres) { //Recibe el valor que queremos dar a Presentado (en este obj.TFG)
	this->presentado = pres; //Setea el valor de presentado
}

bool TFG::getPresentado() {
	return presentado;
}

Profesor * TFG::getTutor() {
	return this->tutor;
}

Profesor * TFG::getCotutor() {
	return this->coTutor;
}

void TFG::setTutor(Profesor * prof) {
	this->tutor = prof;
}

void TFG::setCoTutor(Profesor * prof) {
	this->coTutor = prof;
}

void TFG::modificarPresentacion(Presentacion presentacion)
{
	this->presentacion.setHora(presentacion.getHora());
	this->presentacion.setDia(presentacion.getDia());
	this->presentacion.setAula(presentacion.getAula());
	this->presentacion.setSlot(presentacion.getSlot());
	this->presentacion.setConvocatoria(presentacion.getConvocatoria());
	for (auto dummy : *presentacion.getTribunal())	this->presentacion.addTribunal(dummy);
}

void TFG::borrarPresentacion(Presentacion presentacion)
{
	this->presentacion.setHora(NULL);
	this->presentacion.setDia(NULL);
	this->presentacion.setAula(NULL);
	this->presentacion.setSlot(NULL);
	this->presentacion.setConvocatoria(NULL);
}

void TFG::setPresentacion(Presentacion presentation) {
	this->presentacion = presentation;
}

Presentacion *TFG::getPresentacion()
{
	return &this->presentacion;
}