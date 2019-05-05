#include "ProfesoresMain.h"
#include "ui_ProfesoresMain.h"

ProfesoresMain::ProfesoresMain(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
}

ProfesoresMain::~ProfesoresMain()
{
}

Controller * ProfesoresMain::getController() {
	return this->manager;
}
void ProfesoresMain::setController(Controller * controller) {
	this->manager = controller;
	vector <Profesor> * profesores = new vector <Profesor>;
	profesores = manager->getListaProfesores();
	QStringList lista;
	for (int i = 0; i < profesores->size(); i++) {
		QString * nombre = new QString((*profesores)[i].getNombre().c_str());
		lista.append(*nombre);
	}
	//ui.listaProfesores->clear();
	//ui.listaProfesores->addItems(lista);
}

void ProfesoresMain::crearProfesor() {

}
void ProfesoresMain::borrarProfesor() {

}
void ProfesoresMain::modificarProfesor() {

}
void ProfesoresMain::asignarHorario() {

}
