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
}
void PreBack::setTam() {
	ui.tablaDias->setRowCount(slotsPorDia);
	ui.tablaDias->setColumnCount(dias);
	QStringList diasLab;
	QStringList slotsLab;
	for (int x = 0; x <= ui.tablaDias->columnCount(); x++) {
		for (int y = 0; y <= ui.tablaDias->rowCount(); y++) {
			ui.tablaDias->setCellWidget(y, x, new QTextEdit());
			slotsLab << QString("S") + QString::number(y + 1);
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
	
}
void PreBack::enviarAulas() {

}