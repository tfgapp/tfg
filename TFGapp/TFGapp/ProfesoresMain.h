#pragma once

#include <QWidget>
#include "ui_ProfesoresMain.h"
#include "header.h"

class ProfesoresMain : public QWidget
{
	Q_OBJECT

private:
	Controller *manager;
	Ui::ProfesoresMain ui;

public:
	ProfesoresMain(Controller* main, QWidget *parent = Q_NULLPTR);
	~ProfesoresMain();
	void actualizarLista();
	void setController(Controller * controller);

private slots:
	void crearProfesor();
	void borrarProfesor();
	void modificarProfesor();
	void asignarHorario();
};
