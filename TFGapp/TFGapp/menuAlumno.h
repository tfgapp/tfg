#pragma once

#include <QWidget>
#include <QMessageBox>
#include "ui_menuAlumno.h"
#include "header.h"

class menuAlumno : public QWidget
{
	Q_OBJECT

private:
	Controller *manager;
	Ui::menuAlumno ui;

public:
	menuAlumno(Controller* main, QWidget *parent = Q_NULLPTR);
	~menuAlumno();
	void actualizarLista();
	void setController(Controller * controller);
	vector <Alumno> *alumnos;

private slots:
	void crearAlummno();
	void borrarAlumno();
	void modificarAlumno();
};
