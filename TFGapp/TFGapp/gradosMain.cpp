#include "ui_gradosMain.h"
#include "GradosMain.h"

GradosMain::GradosMain(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	
}

GradosMain::~GradosMain()
{
}

void GradosMain::borrarGrado(){
	//ui.listaGrados.add
}
void GradosMain::crearGrado() {
	
}
Controller * GradosMain::getController() {
	return this->manager;
}
void GradosMain::setController(Controller * controller) {
	this->manager = controller;
	vector <Grado> * grados = new vector <Grado>;
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