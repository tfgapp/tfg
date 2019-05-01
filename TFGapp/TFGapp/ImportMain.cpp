#include "ImportMain.h"
#include "ui_mainImport.h"
#include "Header.h"
#include "qerrormessage.h"
ImportMain::ImportMain(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

}

ImportMain::~ImportMain()
{
}
void ImportMain::pathAlumnos(){
	ui.direccionAlumnos->setText(QFileDialog::getOpenFileName(this, tr("open file"), "/path/to/file/", tr("all (*.csv)")));
	
}
void ImportMain::pathProfesores(){
	ui.direccionProfesores->setText(QFileDialog::getOpenFileName(this, tr("open file"), "/path/to/file/", tr("all (*.csv)")));
}
void ImportMain::pathDisponibilidad(){
	ui.direccionDisponibilidad->setText(QFileDialog::getOpenFileName(this, tr("open file"), "/path/to/file/", tr("all (*.csv)")));
}
void ImportMain::cerrar(){
	importarProfesores((char*)ui.pathProf->text().toStdString().c_str(), manager);
	//importarAlumnos((char*)ui.pathAlum->text().toStdString().c_str(), manager);
	importarHorarios((char*)ui.pathDisp->text().toStdString().c_str(),manager);
	emit ocultar();
	
}
Controller * ImportMain::getController() {
	return this->manager;
}
void ImportMain::setController(Controller * controller) {
	this->manager = controller;
}