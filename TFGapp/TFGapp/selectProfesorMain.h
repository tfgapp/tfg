#pragma once

#include <QWidget>
#include "ui_selectProfesorMain.h"
#include "Header.h"

class selectProfesorMain : public QWidget
{
	Q_OBJECT

private:
	Controller * manager;
	Ui::selectProfesorMain ui;
public:
	selectProfesorMain(Controller * manager, QWidget *parent = Q_NULLPTR);
	~selectProfesorMain();
	void actualizarLista();
	Ui::selectProfesorMain * getUi();

private slots:
	void cancel();
	void select();
signals:
	void cerrar();
};
