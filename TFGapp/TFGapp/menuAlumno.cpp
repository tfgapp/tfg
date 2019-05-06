#include "menuAlumno.h"

menuAlumno::menuAlumno(Controller* main, QWidget *parent): QWidget(parent)
{
	ui.setupUi(this);
	ui.listaAlumnos->setEditTriggers(QAbstractItemView::NoEditTriggers);
	ui.listaAlumnos->setSelectionBehavior(QAbstractItemView::SelectRows);
	ui.listaAlumnos->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
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
	ui.listaAlumnos->setColumnCount(4);
	ui.listaAlumnos->setRowCount(alumnos->size());
	for (int i = 0; i < alumnos->size(); i++) 
	{
		nombre = (*alumnos)[i].getNombre().c_str(); 
		ui.listaAlumnos->setItem(i, 0, new QTableWidgetItem(nombre));
		nombre = (*alumnos)[i].getApellido().c_str();
		ui.listaAlumnos->setItem(i, 1, new QTableWidgetItem(nombre));
		nombre = (*alumnos)[i].getID().c_str();
		ui.listaAlumnos->setItem(i, 2, new QTableWidgetItem(nombre));
		nombre = (*alumnos)[i].getGrado()->getNombre().c_str();
		ui.listaAlumnos->setItem(i, 3, new QTableWidgetItem(nombre));
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
	auto a = ui.listaAlumnos->item(ui.listaAlumnos->currentRow(), 2);
	if (a != NULL)
	{

		QMessageBox msgBox;
		msgBox.setIcon(QMessageBox::Warning);
		msgBox.setText("Seguro que quieres borrar este alumno?");
		QPushButton botonAceptar("Aceptar");
		msgBox.addButton(&botonAceptar, QMessageBox::AcceptRole);
		msgBox.setStandardButtons(QMessageBox::Cancel);
		msgBox.setDefaultButton(QMessageBox::Cancel);
		int ret = msgBox.exec();
		if (msgBox.clickedButton() == &botonAceptar)
		{
			//this->manager->eliminarAlumno(a->text().toStdString());
			actualizarLista();
		}
	}
}

void menuAlumno::setController(Controller * controller) {
	this->manager = controller;
	actualizarLista();
	
}
