#include "PreBack.h"
#include "qstringlist"

PreBack::PreBack(QWidget *parent)
	: QWidget(parent)
{

	ui.setupUi(this);
	ui.listaAlumnos->setHidden(true);
	ui.aceptarAlumnos->setHidden(true);
}

PreBack::~PreBack()
{
}
Controller * PreBack::getController() {
	return this->manager;
}
void PreBack::setController(Controller * controller) {
	this->manager = controller;
	dias = manager->getDiaMax();
	slotsPorDia = 7;
	setTam();
}
void PreBack::setTam() {
	ui.tablaDias->setRowCount(slotsPorDia);
	ui.tablaDias->setColumnCount(dias);
	QStringList diasLab;
	QStringList slotsLab;
	for (int x = 0; x <= ui.tablaDias->columnCount(); x++) {
		for (int y = 0; y <= ui.tablaDias->rowCount(); y++) {
			if(x ==  0)
			slotsLab << QString("S") + QString::number(y + 1);
			ui.tablaDias->setItem(y, x, new QTableWidgetItem(*(new QString)));
		}
		diasLab << QString("D")+QString::number(x + 1);
	}
	ui.tablaDias->setHorizontalHeaderLabels(diasLab);
	ui.tablaDias->setVerticalHeaderLabels(slotsLab);
	for (int x = 0; x <= ui.tablaDias->columnCount(); x++)
		ui.tablaDias->setColumnWidth(x, (ui.tablaDias->width() - ui.tablaDias->verticalHeader()->width()) /( ui.tablaDias->columnCount()+1));
	for (int x = 0; x <= ui.tablaDias->rowCount(); x++)
		ui.tablaDias->setRowHeight(x, (ui.tablaDias->height() - ui.tablaDias->horizontalHeader()->height()) /( ui.tablaDias->rowCount()+1));
}
void PreBack::enviarAlumnos() {
	vector <Alumno> alumnos;
	int numSelect = ui.listaAlumnos->selectedItems().size();
	for (int i = 0; i < numSelect; i++) {
		QString nombre = ui.listaAlumnos->selectedItems()[i]->text();
		alumnos.push_back(*manager->getAlumno(nombre.toStdString()));
	}
	BackTrackingMain *vBack = new BackTrackingMain(&alumnos, this->manager, aulas, ui.convocatorias->text().toInt());
	vBack->show();
	vBack->setWindowModality(Qt::WindowModal);
}
void PreBack::enviarAulas() {
	ui.convocatorias->setHidden(false);
	ui.listaAlumnos->setHidden(false);
	ui.aceptarAlumnos->setHidden(false);
	aulas = new int*[dias];
	for (int i = 0; i < dias; i++) {
		aulas[i] = new int[slotsPorDia];
		for (int j = 0; j < slotsPorDia; j++) {
			aulas[i][j] = ui.tablaDias->item(j,i)->text().toInt();
		}
	}
	if (!(ui.convocatorias->text().isEmpty())) {
		ui.aceptarAulas->setHidden(true);
		ui.tablaDias->setHidden(true);
		ui.label->setHidden(true);
		vector <Alumno> * alumnos;
		alumnos = manager->getListaAlumnos();
		QStringList lista;
		for (int i = 0; i < alumnos->size(); i++) {
			QString * nombre = new QString((*alumnos)[i].getID().c_str());
			if (!lista.contains(*nombre)) {
				lista.append(*nombre);
			}
		}
		ui.listaAlumnos->clear();
		ui.listaAlumnos->addItems(lista);
		ui.listaAlumnos->setSelectionMode(QListWidget::MultiSelection);
	}
}
void PreBack::cambiarTodos() {
	for (int i = 0; i < dias; i++) {
		for (int j = 0; j < slotsPorDia; j++) {
			 ui.tablaDias->item(j,i)->setText(ui.valor->text());
		}
	}
}