#pragma once
#include <iostream>
#include <string>
#include "Profesor.h"
#include "Presentacion.h"

using namespace std;

class TFG {

private:
	string titulo; //ID
	bool presentado;
	Profesor * tutor;
	Profesor *  coTutor;
	Presentacion presentacion;
public:
	TFG(); //Constructor por defecto
	TFG(string, bool); //Constructor con parametros

	void setTitulo(string);
	string getTitulo();

	void setPresentado(bool);
	bool getPresentado();

	Profesor * getTutor();
	Profesor * getCotutor();

	void setTutor(Profesor * prof);
	void setCoTutor(Profesor * prof);

	void modificarPresentacion(Presentacion presentacion);
	void borrarPresentacion(Presentacion presentacion);
	void setPresentacion(Presentacion presentation);
	Presentacion * getPresentacion();
	

};