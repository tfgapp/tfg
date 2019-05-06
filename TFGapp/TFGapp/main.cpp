#include "Header.h"
#include "QApplication"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "GradosMain.h"


int main(int argc, char * argv[])
{
	QApplication qApplication(argc, argv);

	char pathP[] = "../datos_profesor.csv";
	char pathD[] = "../datos_disponibilidad.csv";
	char pathA[] = "../datos_alumno.csv";

	sqlite3 *db = openBBDD("test.db");
	if (FIRST == 1) emptyDB(db);

	Controller main(db);

	if (FIRST == 0)
	{
		volcarGrados(&main);
		volcarProfesores(&main);
		volcarAlumnos(&main);
	}

	if(FIRST == 1)
	{
		importarProfesores(pathP, &main);
		importarAlumnos("../Alumnos.csv", &main, main.getGrado("Grado1"));
		importarAlumnos("../Alumnos4.csv", &main, main.getGrado("Grado2"));
		importarAlumnos("../Alumnos3.csv", &main, main.getGrado("Grado3"));
		importarAlumnos("../Alumnos2.csv", &main, main.getGrado("Grado4"));
		importarHorarios(pathD, &main);
	}

	MainWindow inicio(&main);
	inicio.show();
    
    return qApplication.exec();
}
