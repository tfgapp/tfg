#include "TFG.h"

TFG::TFG() {

	this->titulo = "  ";
	this->presentado = false;
} //Constructor por defecto

TFG::TFG(string titulo, bool pres) {

	this->titulo = titulo;
	this->presentado = pres;

} //Constructor con parametros

void TFG::setString(string tit) { //Recibe el valor que queremos dar a Titulo (en este obj.TFG)
	this->titulo = tit; //Setea el valor de presentado
}

string TFG::getString() {
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
	this->presentacion->setID(presentacion.getID());
	this->presentacion->setHora(presentacion.getHora());
	this->presentacion->setDia(presentacion.getDia());
	this->presentacion->setAula(presentacion.getAula());
	this->presentacion->setSlot(presentacion.getSlot());
	this->presentacion->setConvocatoria(presentacion.getConvocatoria());
	this->presentacion->setTribunal(presentacion.getTribunal());
}

//he creado el metodo mencionado en la actividad modificar presentcaion, lo que hace es coger una presentacion y copiar sus parametros a la presentacion a la ue pertenece el tfg modificando asi sus parametros
//sino es eso lo que pide la actividad enviadme un wa diciendo lo que pide pls
//tambien he agregado un metodo que faltaba en la actividad anterior que es getDia() y setDia(), que se me olvido ponerlo.

void TFG::borrarPresentacion(Presentacion presentacion)
{
	
	this->presentacion->setID(NULL);
	this->presentacion->setHora(NULL);
	this->presentacion->setDia(NULL);
	this->presentacion->setAula(NULL);
	this->presentacion->setSlot(NULL);
	this->presentacion->setConvocatoria(NULL);
	

}
void TFG::setPresentacion(Presentacion *presentation) {
	this->presentacion = presentation;
}

Presentacion *TFG::getPresentacion()
{
	
	return this->presentacion
}

