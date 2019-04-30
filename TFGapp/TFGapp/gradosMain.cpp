#include "ui_gradosMain.h"
#include "gradosMain.h"

gradosMain::gradosMain(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	vector  <Alumno>  alumnos;
	alumnos = *(manager->getListaAlumnos());
	QStringList lista;
	for (int i = 0; alumnos.size(); i++) {
		QString * nombre = new QString((alumnos)[i].getNombre().c_str());
		lista.append(*nombre);
		
	}
	ui.listaGrados->addItems(lista);
}

gradosMain::~gradosMain()
{
}

void gradosMain::borrarGrado(){
	//ui.listaGrados.add
}
void gradosMain::crearGrado() {
	
}
Controller * gradosMain::getController() {
	return this->manager;
}
void gradosMain::setController(Controller * controller) {
	this->manager = controller;
}