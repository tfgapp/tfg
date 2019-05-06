#include "selectProfesorMain.h"

selectProfesorMain::selectProfesorMain(Controller * manager, QWidget *parent): QWidget(parent)
{
	ui.setupUi(this);
	this->manager = manager;
	ui.listaProfesores->setEditTriggers(QAbstractItemView::NoEditTriggers);
	ui.listaProfesores->setSelectionBehavior(QAbstractItemView::SelectRows);
	ui.listaProfesores->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
	actualizarLista();
}

selectProfesorMain::~selectProfesorMain()
{
}

void selectProfesorMain::actualizarLista()
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

void selectProfesorMain::select()
{
	auto a = ui.listaProfesores->item(ui.listaProfesores->currentRow(), 0);
	if (a != NULL)
	{
		emit cerrar();
	}
}

void selectProfesorMain::cancel()
{
	ui.listaProfesores->clearSelection();
	emit cerrar();
}

Ui::selectProfesorMain * selectProfesorMain::getUi()
{
	return &this->ui;
}
