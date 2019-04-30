#pragma once

#include <QWidget>
#include "ui_gradosMain.h"
#include "header.h"
class gradosMain : public QWidget
{
	Q_OBJECT

public:
	gradosMain(QWidget *parent = Q_NULLPTR);
	~gradosMain();
	Controller * getController();
	void setController(Controller * controller);
private slots:
	void crearGrado();
	void borrarGrado();
private:
	Controller *manager;
	Ui::gradosMain ui;
};
