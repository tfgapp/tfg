#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(Controller * main, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{	
    ui->setupUi(this);
	grados = new GradosMain(main);
	profesores = new ProfesoresMain(main);
	vImport = new ImportMain(main);
	alumnos = new menuAlumno(main);
	this->manager = main;
	sqlite3 *db = openBBDD("test.db");
	Grado gradoIng;
	gradoIng.setNombre(string("Ingenieria"));
	manager->addGrado(gradoIng); 
	connect(this, &MainWindow::actualizar, profesores, &ProfesoresMain::actualizarLista);
	connect(this, &MainWindow::actualizar, alumnos, &menuAlumno::actualizarLista);
	connect(this, &MainWindow::actualizar, grados, &GradosMain::actualizarLista);
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

void MainWindow::botonGrados()
{
	emit actualizar();
	grados->show();
	grados->setWindowModality(Qt::WindowModal);
}

void MainWindow::botonProfesores()
{
	emit actualizar();
	profesores->show();
	profesores->setWindowModality(Qt::WindowModal);
}

void MainWindow::botonImportar() 
{
	vImport->show();
	vImport->setWindowModality(Qt::WindowModal);
}

void MainWindow::botonAlumnos()
{
	emit actualizar();
	alumnos->show();
	alumnos->setWindowModality(Qt::WindowModal);
}

void MainWindow::ocultarImportar()
{
	vImport->hide();
}

void MainWindow::botonOrganizar() 
{
	preBack = new PreBack();
	connect(this, &MainWindow::enviarController, preBack, &PreBack::setController);
	emit enviarController(this->getController());
	preBack->show();
	preBack->setWindowModality(Qt::WindowModal);
}