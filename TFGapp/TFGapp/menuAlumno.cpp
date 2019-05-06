#include "menuAlumno.h"

menuAlumno::menuAlumno(Controller* main, QWidget *parent): QWidget(parent)
{
	ui.setupUi(this);
	ui.listaAlumnos->setEditTriggers(QAbstractItemView::NoEditTriggers);
	this->manager = main;
	actualizarLista();
}

menuAlumno::~menuAlumno()
{
}

void menuAlumno::actualizarLista()
{
	vector <Alumno> * alumnos = manager->getListaAlumnos();
	QString nombre;

	ui.listaAlumnos->clear();
	ui.listaAlumnos->setColumnCount(3);
	ui.listaAlumnos->setRowCount(alumnos->size());
	for (int i = 0; i < alumnos->size(); i++) 
	{
		nombre = (*alumnos)[i].getNombre().c_str(); 
		ui.listaAlumnos->setItem(i, 0, new QTableWidgetItem(nombre));
		nombre = (*alumnos)[i].getApellido().c_str();
		ui.listaAlumnos->setItem(i, 1, new QTableWidgetItem(nombre));
		nombre = (*alumnos)[i].getID().c_str();
		ui.listaAlumnos->setItem(i, 2, new QTableWidgetItem(nombre));
	}
}

void menuAlumno::modificarAlumno() 
{

}

void menuAlumno::crearAlummno() 
{

}

void  menuAlumno::borrarAlumno() 
{

}

void menuAlumno::setController(Controller * controller) {
	this->manager = controller;
	actualizarLista();
	
}
