#include "BackTrackingMain.h"
#include "qlistwidget.h"
#include "qlayout.h"
#include "qlineedit.h"
#include "qlabel.h"
#include "qsizepolicy.h"
#include "qsize.h"
#include "string.h"
#include "qstring.h"

BackTrackingMain::BackTrackingMain(vector <Alumno> *alumnos, Controller *controller,int ** aulas, int convocatoria, QWidget *parent)
	: QWidget(parent)
{
	this->alumnos = *alumnos;
	//*this->salida = *controller; //Salida es null pq  no esta reservado un espacio de memoria. Para poder hacer copia tienes que tener hueco, no tiene sentido copiar el controller pq vas a perder referencias
	this->salida = controller; 
	this->aulas = aulas;
	this->convocatoria = convocatoria;
	ui.setupUi(this);
	iniciarBack();
}

BackTrackingMain::~BackTrackingMain()
{

}
void BackTrackingMain::iniciarBack() {
	vector <Alumno*> *alum = new vector <Alumno*>;
	bool correcto;
	for (int i = 0; i < alumnos.size(); i++) {
		alum->push_back(&(alumnos)[i]);
	}
	correcto = prepareR(salida, convocatoria, alum, aulas);
	if (correcto) {
		QVBoxLayout *lays = new QVBoxLayout[7*salida->getDiaMax()+7+salida->getDiaMax()];
		bool introducirAlum = false;
		for(int i = 0, cont = 0; i < 7;i++)
			for (int j = 0; j < salida->getDiaMax(); j++) {
					ui.gridLayout->addLayout(&lays[cont], i, j, 1, 1);
					if (i == 0 && j != 0) {
						QLabel *b = new QLabel();
						lays[cont].addWidget(b);
						b->sizePolicy().setHorizontalStretch(1);
						b->setText(QString("Dia")+ QString::number(j));
					}
					else if (j == 0 && i != 0) {
						QLabel *b = new QLabel();
						lays[cont].addWidget(b);
						b->sizePolicy().setHorizontalStretch(1);
						b->setText(QString("Slot") + QString::number(i-1));
					}
					else if (j == 0 && i == 0) {
						QLabel *b = new QLabel();
						lays[cont].addWidget(b);
						b->sizePolicy().setHorizontalStretch(1);
						b->setText(QString("Tabla"));
					}
					else {
						for (int n = 0; n < alum->size(); n++) {
							int diaP = (*alum)[n]->getTFG()->getPresentacion()->getDia();
							int slotP = (*alum)[n]->getTFG()->getPresentacion()->getSlot();
							if (diaP == j && slotP == i - 1) {
								QString a((*alum)[n]->getNombre().c_str());
								QString dia(QString::number(diaP));
								QString slot(QString::number(slotP));
								QLabel *b = new QLabel();
								//b->setSizePolicy(QSizePolicy::Expanding);
								b->setText(dia + QString(" ") + slot + QString(" ") + a);
								lays[cont].addWidget(b);
								b->sizePolicy().setHorizontalStretch(1);
								introducirAlum = true;
								if ((i+j) % 2 == 0) {
									b->setStyleSheet("background-color: red");
								}
								else
									b->setStyleSheet("background-color: blue");
							}

						}
						if (!introducirAlum) {
							QLabel *b = new QLabel();
							QString dia(QString::number(j + 1));
							QString slot(QString::number(i));
							b->setText(QString("None"));
							lays[cont].addWidget(b);
							b->sizePolicy().setHorizontalStretch(1);
							if ((i+j) % 2 == 0) {
								b->setStyleSheet("background-color: red");
							}
							else
								b->setStyleSheet("background-color: blue");
						}
					}
					introducirAlum = false;
					cont++;
			}
		
	}
}