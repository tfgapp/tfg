#pragma once

#include <QWidget>
#include "ui_gradosMain.h"
#include "header.h"

class GradosMain : public QWidget
{
	Q_OBJECT

public:
	GradosMain(QWidget *parent = Q_NULLPTR);
	~GradosMain();
	Controller * getController();
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
