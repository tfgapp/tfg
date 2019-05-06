#include "ui_gradosMain.h"
#include "GradosMain.h"

GradosMain::GradosMain(QWidget *parent): QWidget(parent)
{
	ui.setupUi(this);
	ui.botonAceptar->setVisible(false);
	ui.introducirTexto->setVisible(false);
	
}

GradosMain::~GradosMain()
{
}

void GradosMain::borrarGrado()
{
	auto a = ui.listaGrados->currentItem();
	if (a != NULL) 
	{
		this->manager->eliminarGrado(a->text().toStdString());
		actualizarLista();
	}
}

void GradosMain::crearGrado() 
{
	QEventLoop loop;
	Grado grado;
	connect(this, SIGNAL(aceptar()), &loop, SLOT(quit()));
	ocultarCasiTodo();
	ui.botonAceptar->setVisible(true);
	ui.introducirTexto->setVisible(true);
	loop.exec();
	grado.setNombre(ui.introducirTexto->text().toStdString());
	this->manager->addGrado(grado);
	actualizarLista();
	ui.botonAceptar->setVisible(false);
	ui.introducirTexto->setVisible(false);
	mostrarCasiTodo();
}

void GradosMain::ocultarCasiTodo()
{
	ui.botonBorrar->setVisible(false);
	ui.botonCrear->setVisible(false);
	ui.botonModificar->setVisible(false);
	ui.listaGrados->setVisible(false);
}

void GradosMain::mostrarCasiTodo()
{
	ui.botonBorrar->setVisible(true);
	ui.botonCrear->setVisible(true);
	ui.botonModificar->setVisible(true);
	ui.listaGrados->setVisible(true);
}

void  GradosMain::modificarGrado() 
{
	
}

Controller * GradosMain::getController() 
{
	return this->manager;
}

void GradosMain::setController(Controller * controller) 
{
	this->manager = controller;
	this->actualizarLista();
}

void GradosMain::aceptarCambio() {
	if (!ui.introducirTexto->text().isEmpty() && this->manager->getGrado(ui.introducirTexto->text().toStdString()) == NULL && ui.introducirTexto->text() != QString("Grado no valido"))
		emit aceptar();
	else 
		QString a("Grado no valido");
}

void GradosMain::actualizarLista() {
	vector <Grado> * grados;
	grados = manager->getListaGrados();
	QStringList lista;
	for (int i = 0; i < grados->size(); i++) {
		QString * nombre = new QString((*grados)[i].getNombre().c_str());
		if (!lista.contains(*nombre)) {
			lista.append(*nombre);
		}
	}
	ui.listaGrados->clear();
	ui.listaGrados->addItems(lista);

}