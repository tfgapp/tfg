#pragma once

#include <QWidget>
#include <QMessageBox>
#include "ui_menuAlumno.h"
#include "header.h"
#include "selectProfesorMain.h"

class menuAlumno : public QWidget
{
	Q_OBJECT

private:
	Controller *manager;
	Ui::menuAlumno ui;
	selectProfesorMain * vProfesor;
public:
	menuAlumno(Controller* main, QWidget *parent = Q_NULLPTR);
	~menuAlumno();
	void actualizarLista();
	void setController(Controller * controller);
	vector <Alumno> *alumnos;

private slots:
	void crearAlumno();
	void borrarAlumno();
	void modificarAlumno();
	void asignarTutor();
	void asignarCoTutor();
	void recibirTutor();
	void recibirCoTutor();
	void quitarTutor();
	void quitarCoTutor();

};
