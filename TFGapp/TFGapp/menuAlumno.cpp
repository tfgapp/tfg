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

void menuAlumno::crearAlumno() 
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
			this->manager->eliminarAlumno(a->text().toStdString());
			actualizarLista();
		}
	}
}

void menuAlumno::setController(Controller * controller) 
{
	this->manager = controller;
	actualizarLista();
}

void menuAlumno::asignarTutor()
{
	auto a = ui.listaAlumnos->item(ui.listaAlumnos->currentRow(), 2);
	if (a != NULL)
	{
		vProfesor = new selectProfesorMain(manager);
		vProfesor->show();
		vProfesor->setWindowModality(Qt::WindowModal);
		connect(vProfesor, &selectProfesorMain::cerrar, this, &menuAlumno::recibirTutor);
	}
}

void menuAlumno::asignarCoTutor()
{
	auto a = ui.listaAlumnos->item(ui.listaAlumnos->currentRow(), 2);
	if (a != NULL)
	{
		vProfesor = new selectProfesorMain(manager);
		vProfesor->show();
		vProfesor->setWindowModality(Qt::WindowModal);
		connect(vProfesor, &selectProfesorMain::cerrar, this, &menuAlumno::recibirCoTutor);
	}
}

void menuAlumno::recibirTutor()
{
	vProfesor->hide();
	auto a = ui.listaAlumnos->item(ui.listaAlumnos->currentRow(), 2);
	auto profesor = vProfesor->getUi()->listaProfesores->item(vProfesor->getUi()->listaProfesores->currentRow(), 0);
	if (profesor != NULL)
	{
		Alumno * alumno = this->manager->getAlumno(a->text().toStdString());
		this->manager->enlazarTutor(alumno, this->manager->getProfesor(profesor->text().toStdString()));
	}
}

void menuAlumno::recibirCoTutor()
{
	vProfesor->hide();
	auto a = ui.listaAlumnos->item(ui.listaAlumnos->currentRow(), 2);
	auto profesor = vProfesor->getUi()->listaProfesores->item(vProfesor->getUi()->listaProfesores->currentRow(), 0);
	if (profesor != NULL)
	{
		Alumno * alumno = this->manager->getAlumno(a->text().toStdString());
		this->manager->enlazarCoTutor(alumno, this->manager->getProfesor(profesor->text().toStdString()));
	}
}

void menuAlumno::quitarTutor()
{
	auto a = ui.listaAlumnos->item(ui.listaAlumnos->currentRow(), 2);
	if (a != NULL)
	{
		Alumno * alumno = manager->getAlumno(a->text().toStdString());
		string sql = "UPDATE TFG SET tutor = '";
		sql += "null"; sql += "' WHERE alumno='";
		sql += alumno->getID(); sql += "';";

		char * error = NULL;
		int resultado = sqlite3_exec(manager->getDB(), sql.c_str(), 0, this, &error);
		checkError(resultado, error);

		alumno->getTFG()->setTutor(NULL);
	}
}

void menuAlumno::quitarCoTutor()
{
	auto a = ui.listaAlumnos->item(ui.listaAlumnos->currentRow(), 2);
	if (a != NULL)
	{
		Alumno * alumno = manager->getAlumno(a->text().toStdString());
		string sql = "UPDATE TFG SET cotutor = '";
		sql += "null"; sql += "' WHERE alumno='";
		sql += alumno->getID(); sql += "';";

		char * error = NULL;
		int resultado = sqlite3_exec(manager->getDB(), sql.c_str(), 0, this, &error);
		checkError(resultado, error);

		alumno->getTFG()->setCoTutor(NULL);
	}
}