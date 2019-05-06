#include "ProfesoresMain.h"

ProfesoresMain::ProfesoresMain(Controller* main, QWidget *parent): QWidget(parent)
{
	this->manager = main;
	ui.setupUi(this);
	actualizarLista();
}

ProfesoresMain::~ProfesoresMain()
{
}

void ProfesoresMain::actualizarLista()
{
	ui.listaProfesores->clear();
	vector <Profesor> * profesores = manager->getListaProfesores();
	QString nombre;
	for (int i = 0; i < profesores->size(); i++) 
	{
		nombre = (*profesores)[i].getNombre().c_str();
		ui.listaProfesores->addItem(nombre);
	}
}

void ProfesoresMain::setController(Controller * controller) 
{
	this->manager = controller;
	actualizarLista();
}

void ProfesoresMain::crearProfesor()
{

}
void ProfesoresMain::borrarProfesor() 
{

}
void ProfesoresMain::modificarProfesor() 
{

}
void ProfesoresMain::asignarHorario() 
{

}
