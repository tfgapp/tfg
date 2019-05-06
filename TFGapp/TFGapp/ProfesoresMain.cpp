#include "ProfesoresMain.h"

ProfesoresMain::ProfesoresMain(Controller* main, QWidget *parent): QWidget(parent)
{
	this->manager = main;
	ui.setupUi(this);
	ui.listaProfesores->setEditTriggers(QAbstractItemView::NoEditTriggers);
	ui.listaProfesores->setSelectionBehavior(QAbstractItemView::SelectRows);
	ui.listaProfesores->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
	actualizarLista();
}

ProfesoresMain::~ProfesoresMain()
{
}

void ProfesoresMain::actualizarLista()
{
	vector <Profesor> * profesores = manager->getListaProfesores();
	QString nombre;
	ui.listaProfesores->clear();
	ui.listaProfesores->setColumnCount(2);
	ui.listaProfesores->setRowCount(profesores->size());
	for (int i = 0; i < profesores->size(); i++) 
	{
		nombre = (*profesores)[i].getNombre().c_str();
		ui.listaProfesores->setItem(i, 0, new QTableWidgetItem(nombre));
		nombre = ((*profesores)[i].getDoctor()) ? "Es doctor" : "No es doctor";
		ui.listaProfesores->setItem(i, 1, new QTableWidgetItem(nombre));
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
