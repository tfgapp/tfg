#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "qfiledialog.h"
#include "Header.h"
#include "GradosMain.h"
#include "ImportMain.h"
#include "ProfesoresMain.h"
#include "menuAlumno.h"
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
	//void on_botonPath_clicked();
	//void on_pushButton_2_clicked();
	////void testSlot() ;
	void botonGrados();
	void botonProfesores();
	void botonAlumnos();
	void botonImportar();
	void ocultarImportar();
signals:
    void enviarController(Controller *controller);
private:
	Controller * manager;
    Ui::MainWindow *ui;
	GradosMain *grados;
	ImportMain *vImport;
	ProfesoresMain *profesores;
	menuAlumno *alumnos;
};

#endif // MAINWINDOW_H
