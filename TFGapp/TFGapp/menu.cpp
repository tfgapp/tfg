#include "menu.h"
#include "ui_menu.h"

menu::menu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::menu)
{
    ui->setupUi(this);
}

menu::~menu()
{
    delete ui;
}



void menu::on_pushButton_clicked()
{
    /*aqui podemos escribir el codigo de lo que vamos a hacer*/

}
