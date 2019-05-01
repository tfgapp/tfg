#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "qfiledialog.h"
#include "Header.h"
#include "GradosMain.h"
#include "ImportMain.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
	Controller * getController();
	void setController(Controller * controller);
	void ocultarImportar(); 
	
	
private slots:
	//void on_botonPath_clicked();
	//void on_pushButton_2_clicked();
	////void testSlot() ;
	void botonGrados();
	void botonImportar();
signals:
    void enviarController(Controller *controller);
private:
	Controller * manager;
    Ui::MainWindow *ui;
	GradosMain *grados;
	ImportMain *vImport;
};

#endif // MAINWINDOW_H
