#pragma once

#include <QWidget>
#include "ui_ProfesoresMain.h"
#include "header.h"

class ProfesoresMain : public QWidget
{
	Q_OBJECT

public:
	ProfesoresMain(QWidget *parent = Q_NULLPTR);
	~ProfesoresMain();
	Controller * getController();
	void setController(Controller * controller);
	vector  <Profesor>  *profesores;
private slots:
	void crearProfesor();
	void borrarProfesor();
	void modificarProfesor();
	void asignarHorario();
private:
	Controller *manager;
	Ui::ProfesoresMain ui;
};
