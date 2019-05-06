#pragma once

#include <QWidget>
#include <QMessageBox>
#include "ui_gradosMain.h"
#include "header.h"

class GradosMain : public QWidget
{
	Q_OBJECT

public:
	GradosMain(Controller * main, QWidget *parent = Q_NULLPTR);
	~GradosMain();
	void setController(Controller * controller);
	vector  <Grado>  *grados;
	void ocultarCasiTodo();
	void mostrarCasiTodo();
	void actualizarLista();
private slots:
	void crearGrado();
	void borrarGrado();
	void modificarGrado();
	void aceptarCambio();
signals:
	void aceptar();
private:
	Controller *manager;
	Ui::gradosMain ui;
};
