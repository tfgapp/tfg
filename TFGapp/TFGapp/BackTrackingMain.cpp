#include "BackTrackingMain.h"


BackTrackingMain::BackTrackingMain(vector <Alumno> *alumnos, Controller *controller,int ** aulas, int convocatoria, QWidget *parent)
	: QWidget(parent)
{
	this->alumnos = *alumnos;
	*this->salida = *controller;
	this->aulas = aulas;
	this->convocatoria = convocatoria;
	ui.setupUi(this);
	iniciarBack();
}

BackTrackingMain::~BackTrackingMain()
{

}
void BackTrackingMain::iniciarBack() {
	vector <Alumno*> *alum = new vector <Alumno*>;
	bool correcto;
	for (int i = 0; i < alumnos.size(); i++) {
		alum->push_back(&(alumnos)[i]);
	}
	correcto = prepareR(salida, convocatoria, alum, aulas);
	if (correcto) {
		for (int i = 0; i < alum->size(); i++) {
			int diaP = (*alum)[i]->getTFG()->getPresentacion()->getDia();
			int slotP = (*alum)[i]->getTFG()->getPresentacion()->getSlot();
			//ui.tableWidget->item();
		}
	}
}