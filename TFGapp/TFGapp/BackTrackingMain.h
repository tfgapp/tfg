#pragma once

#include <QWidget>
#include "ui_BackTrackingMain.h"
#include "Header.h"


class BackTrackingMain : public QWidget
{
	Q_OBJECT

public:
	BackTrackingMain(vector <Alumno> *alumnos, Controller *controller,int ** aulas, int convocatoria,QWidget *parent = Q_NULLPTR);
	~BackTrackingMain();
	vector <Alumno> alumnos;
	Controller *salida;
	int **aulas;
	int convocatoria;
	void iniciarBack();

private:
	Ui::BackTrackingMain ui;
};
