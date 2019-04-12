#include "TFG.h"

TFG::TFG() {

} //Constructor por defecto

TFG::TFG(string titulo, bool pres) {

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
