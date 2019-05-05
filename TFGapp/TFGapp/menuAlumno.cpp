#include "menuAlumno.h"

menuAlumno::menuAlumno(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
}

menuAlumno::~menuAlumno()
{
}

void menuAlumno::CrearAlummno() {

}

void  menuAlumno::borrarAlumno() {

}

Controller * menuAlumno::getController() {
	return this->manager;
}

void menuAlumno::setController(Controller * controller) {
	this->manager = controller;
	vector <Alumno> * alumnos = new vector <Alumno>;
	alumnos = manager->getListaAlumnos();
	QStringList listaAlumnos1;
	for (int i = 0; i < alumnos->size(); i++) {
		QString * nombre = new QString((*alumnos)[i].getNombre().c_str()); //+ (*alumnos)[i].getApellido().c_str);
		if (!listaAlumnos1.contains(*nombre)) {
			listaAlumnos1.append(*nombre);
		}
	}

	//ui.listaAlumnos->clear();
	//ui.listaAlumnos->addItems(listaAlumnos1);
}
