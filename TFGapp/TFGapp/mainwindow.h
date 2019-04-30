#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "qfiledialog.h"
#include "Controller.h"
#include "gradosMain.h"
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
	
private slots:
	//void on_botonPath_clicked();
	//void on_pushButton_2_clicked();
	////void testSlot() ;
	void botonGrados();
signals:
    void enviarController(Controller *controller);
private:
	Controller * manager;
    Ui::MainWindow *ui;
	gradosMain *grado;
};

#endif // MAINWINDOW_H
