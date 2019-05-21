#pragma once
#ifdef ProfesoresMain.h
#include "ProfesoresMain.h"
#endif

#include <QWidget>
#include "ui_crearProfesor.h"
#include "header.h"


class crearProfesor : public QWidget {
	Q_OBJECT

public:
	crearProfesor(Controller * main, QWidget *parent = Q_NULLPTR);
	~crearProfesor();

private slots:
	void crearClicked();

private:
	Ui::crearProfesor ui;
	Controller * main;
};
