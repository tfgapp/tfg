#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
	manager = new Controller;
	connect(this, &MainWindow::enviarController, grado, &gradosMain::setController);
}

MainWindow::~MainWindow()
{
    delete ui;
}
Controller * MainWindow::getController() {
	return this->manager;
}
void MainWindow::setController(Controller * controller) {
	this->manager = controller;
}
void MainWindow::botonGrados() {
	grado = new gradosMain();
	grado->show();
	grado->setWindowModality(Qt::WindowModal);
	emit enviarController(this->getController());
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