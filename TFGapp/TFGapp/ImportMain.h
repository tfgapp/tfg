#pragma once

#include <QWidget>
#include "ui_mainImport.h"
#include "header.h"
#include <QFileDialog>

class ImportMain : public QWidget
{
	Q_OBJECT

public:
	ImportMain(QWidget *parent = Q_NULLPTR);
	~ImportMain();
	Controller * getController();
	void setController(Controller * controller);
	void ocultarCasiTodo();
	void mostrarCasiTodo();
private slots:
	void pathAlumnos();
	void pathProfesores();
	void pathDisponibilidad();
	void cerrar();
	void confirmarGrado();
signals:
	void ocultar();
	void aceptarGrado();
private:
	Ui::mainImport ui;
	Controller *manager;

};
