
#include <iostream>
#include <string>
#include "Profesor.h"

using namespace std;

class TFG {

private:

	string titulo;
	bool presentado;
	Profesor * tutor;
	Profesor *  coTutor;

public:
	TFG(); //Constructor por defecto
	TFG(string, bool); //Constructor con parametros
	void setString(string);
	string getString();
	void setPresentado(bool);
	bool getPresentado();
	Profesor * getTutor();
	Profesor * getCotutor();
	void setTutor(Profesor * prof);
	void setCoTutor(Profesor * prof);
	
};