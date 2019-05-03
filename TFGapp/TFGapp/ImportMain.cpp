#include "ImportMain.h"
#include "ui_mainImport.h"
#include "Header.h"
#include "qerrormessage.h"
#include "qcombobox.h"

ImportMain::ImportMain(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

}

ImportMain::~ImportMain()
{
}
void ImportMain::pathAlumnos(){
	
	QStringList filenames = QFileDialog::getOpenFileNames(this, tr("open file"), "/path/to/file/", tr("all (*.csv)"));
	ui.listPathAlumnos->addItems(filenames);
		
	
}
void ImportMain::pathProfesores(){
	ui.direccionProfesores->setText(QFileDialog::getOpenFileName(this, tr("open file"), "/path/to/file/", tr("all (*.csv)")));
}
void ImportMain::pathDisponibilidad(){
	ui.direccionDisponibilidad->setText(QFileDialog::getOpenFileName(this, tr("open file"), "/path/to/file/", tr("all (*.csv)")));
}
void ImportMain::cerrar(){
	if (ui.direccionProfesores->text().contains(".csv")) {
		manager->setListaProfesores(new vector <Profesor>);
		manager->setListaGrados(new vector <Grado>);
		importarProfesores((char*)ui.direccionProfesores->text().toStdString().c_str(), this->manager);
	}
	if (ui.direccionDisponibilidad->text().contains(".csv")) {
		importarHorarios((char*)ui.direccionDisponibilidad->text().toStdString().c_str(), this->manager);
	}
	if (ui.listPathAlumnos->count() != 0) {
		Grado *grado;
		vector <Grado> *grados = manager->getListaGrados();
		for (int i = 0; i < manager->getListaGrados()->size(); i++) {
			grado = &((*grados)[i]);
			ui.selectGrado->addItem(grado->getNombre().c_str());
		}
		grados = manager->getListaGrados();
		for (int i = 0; i < ui.listPathAlumnos->count(); i++) {
			if (ui.listPathAlumnos->takeItem(i)->text().contains(".csv")) {
				ui.selectGrado->show();
				ui.confirmarGrado->show();
				ui.path->show();
				ui.path->setText(ui.listPathAlumnos->takeItem(i)->text());
				
			}
		}
	}
	//if (ui.direccionAlumnos->text().contains(".csv")) {
		//manager->setListaAlumnos(new vector <Alumno>);
		//importarAlumnos((char*)ui.direccionAlumnos->text().toStdString().c_str(), manager);
	//}
	emit ocultar();
	
}
Controller * ImportMain::getController() {
	return this->manager;
}
void ImportMain::setController(Controller * controller) {
	this->manager = controller;
}
void ImportMain::confirmarGrado() {
	importarAlumnos((char*)ui.path->text().toStdString().c_str(), manager, this->manager->getGrado(ui.selectGrado->currentText().toStdString()));
	ui.selectGrado->setDisabled(true);
	ui.confirmarGrado->setDisabled(true);
	ui.path->setDisabled(true);
}