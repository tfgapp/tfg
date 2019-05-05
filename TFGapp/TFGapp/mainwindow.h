#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "qfiledialog.h"
#include "Header.h"
#include "GradosMain.h"
#include "ImportMain.h"
#include "PreBack.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(Controller * main , QWidget *parent = nullptr);
    ~MainWindow();
	Controller * getController();
	void setController(Controller * controller);
	
	
	
private slots:

	void botonGrados();
	void botonImportar();
	void ocultarImportar();
	void botonOrganizar();
signals:
    void enviarController(Controller *controller);
private:
	Controller * manager;
    Ui::MainWindow *ui;
	GradosMain *grados;
	ImportMain *vImport;
	PreBack *preBack;
};

#endif // MAINWINDOW_H
