#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(Controller * main, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{	
    ui->setupUi(this);
	grados = new GradosMain();
	profesores = new ProfesoresMain();
	vImport = new ImportMain();
	this->manager = main;
	sqlite3 *db = openBBDD("test.db");

	Grado gradoIng;
	gradoIng.setNombre(string("Ingenieria"));
	manager->addGrado(gradoIng);
	connect(this, &MainWindow::enviarController, grados, &GradosMain::setController);
	connect(this, &MainWindow::enviarController, vImport, &ImportMain::setController);
	connect(vImport, &ImportMain::ocultar, this, &MainWindow::ocultarImportar);
	emit enviarController(this->getController());
	
}

MainWindow::~MainWindow()
{
	sqlite3_close(manager->getDB());
	delete ui;
}
Controller * MainWindow::getController() {
	return this->manager;
}
void MainWindow::setController(Controller * controller) {
	this->manager = controller;
}
void MainWindow::botonGrados() {
	emit enviarController(this->getController());
	grados->show();
	grados->setWindowModality(Qt::WindowModal);
	
}

void MainWindow::botonProfesores() {
	emit enviarController(this->getController());
	profesores->show();
	profesores->setWindowModality(Qt::WindowModal);

}
void MainWindow::botonImportar() {
	emit enviarController(this->getController());
	vImport->show();
	vImport->setWindowModality(Qt::WindowModal);
	
	
}
void MainWindow::ocultarImportar() {
	vImport->hide();
}
//void Mainwindow::on_botonpath_clicked()
//{
//   qstringlist filenames = qfiledialog::getopenfilenames(this, tr("open file"), "/path/to/file/", tr("all (*.*)"));
//   ui->listwidget->additems(filenames);
//}
//void MainWindow::on_pushButton_2_clicked() {
//	menu  *menus = new menu();
//	menus->setModal(true);
//	menus->show();
//}
//
//void mainwindow::testslot() 
//{
//	menu  *menus = new menu();
//	menus->setmodal(true);
//	qstringlist filenames = qfiledialog::getopenfilenames(this, tr("open file"), "/path/to/file/", tr("all (*.*)"));
//	ui->listwidget->additems(filenames);
//}