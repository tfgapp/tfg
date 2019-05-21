#include "crearProfesor.h"
#include <QMessageBox>

crearProfesor::crearProfesor(Controller * main, QWidget *parent)
	: QWidget(parent) {
	this->main = main;
	ui.setupUi(this);

	/*ui.labGradoOculto->setHidden(true);
	ui.numAlumnos->setHidden(true);
	ui.labelAlumnos->setHidden(true);
	ui.nomGrados->setSelectionMode(QListWidget::MultiSelection);
	vector <Grado> * grados;
	grados = main->getListaGrados();
	QStringList lista;

	for (int i = 0; i < grados->size(); i++) {
		QString * nombre = new QString((*grados)[i].getNombre().c_str());
		if (!lista.contains(*nombre)) {
			lista.append(*nombre);	
		}
	}
	ui.nomGrados->clear();
	ui.nomGrados->addItems(lista);*/
}

void crearProfesor::crearClicked() {
	QMessageBox msgBox;
	msgBox.setIcon(QMessageBox::Warning);
	msgBox.setText("Confirma que quieres añadir un nuevo Profesor");
	QPushButton botonAceptar("Aceptar");
	msgBox.addButton(&botonAceptar, QMessageBox::AcceptRole);
	msgBox.setStandardButtons(QMessageBox::Cancel);
	msgBox.setDefaultButton(QMessageBox::Cancel);
	int ret = msgBox.exec();

	if (msgBox.clickedButton() == &botonAceptar) {
		Profesor miProfe;

		if (ui.trueDoc->checkState() == 2) {
			miProfe.setDoctor(true);
		} else {
			miProfe.setDoctor(false);
		}

		miProfe.setNombre(ui.nomProfesor->text().toStdString());
	
		Grado * miGrado = main->getGrado(ui.nomGrado->text().toStdString());

		if (miGrado != NULL) {
			miProfe.addGrado(miGrado, ui.numAlumnos->value());
		}

		main->addProfesor(miProfe);

		/* BUCLE PARA SELECCION MULTIPLE DE GRADOS
		for (int i = 0; i < ui.nomGrados->selectedItems().size(); i++) {
		miProfe.addGrado(main->getGrado(ui.nomGrados->selectedItems()[i]->text().toStdString()), 0);
	}*/
	}
}

crearProfesor::~crearProfesor() {

}