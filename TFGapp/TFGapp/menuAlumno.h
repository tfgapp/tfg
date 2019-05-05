#pragma once

#include <QWidget>
#include "ui_menuAlumno.h"
#include "header.h"

class menuAlumno : public QWidget
{
	Q_OBJECT

public:
	menuAlumno(QWidget *parent = Q_NULLPTR);
	~menuAlumno();
	Controller * getController();
	void setController(Controller * controller);
	vector <Alumno> *alumnos;

private slots:
	void crearAlummno();
	void borrarAlumno();
	void modificarAlumno();

private:
	Controller *manager;
	Ui::menuAlumno ui;
};
