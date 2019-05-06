#pragma once
#include "Controller.h"
#include <QWidget>
#include "ui_PreBack.h"
#include "qtextedit.h"
#include "BackTrackingMain.h"
class PreBack : public QWidget
{
	Q_OBJECT

public:
	int dias;
	int slotsPorDia;
	PreBack(QWidget *parent = Q_NULLPTR);
	~PreBack();
	Controller * getController();
	void setController(Controller * controller);
	void setTam();
private slots:
	void enviarAulas();
	void enviarAlumnos();

private:
	
	Ui::PreBack ui;
	Controller *manager;
	int ** aulas;
};
