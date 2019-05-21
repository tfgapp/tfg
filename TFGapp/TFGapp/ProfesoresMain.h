#pragma once

#include <QWidget>
#include <QMessageBox>
#include "ui_ProfesoresMain.h"
#include "header.h"
#include "crearProfesor.h"

class ProfesoresMain : public QWidget
{
	Q_OBJECT

private:
	Controller *manager;
	Ui::ProfesoresMain ui;
	crearProfesor * ventanaCrear;

public:
	ProfesoresMain(Controller* main, QWidget *parent = Q_NULLPTR);
	~ProfesoresMain();
	void actualizarLista();
	void setController(Controller * controller);

private slots:
	void crearProf();
	void borrarProfesor();
	void modificarProfesor();
	void asignarHorario();
};
