#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "menu.h"
#include "ui_menu.h"
#include "qfiledialog.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
   menu  *menus = new menu();
   menus->setModal(true);
   QStringList fileNames = QFileDialog::getOpenFileNames(this, tr("Open File"), "/path/to/file/", tr("all (*.*)"));
   ui->listWidget->addItems(fileNames);
}
void MainWindow::on_pushButton_2_clicked() {
	menu  *menus = new menu();
	menus->setModal(true);
	menus->show();
}
