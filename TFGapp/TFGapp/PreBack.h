#pragma once
#include "Controller.h"
#include <QWidget>
#include "ui_PreBack.h"
#include "qtextedit.h"
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
	void cambiarDias();
	void cambiarSlots();

private:
	
	Ui::PreBack ui;
	Controller *manager;
	int ** aulas;
};
