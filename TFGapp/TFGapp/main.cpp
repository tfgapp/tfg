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

	int opc = 0;
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
    string dummy_S;
	while (opc != 0)
	{
		opc = menu();
		switch (opc)
		{
		case 0:
			break;
		case 1:
			cout << "Lista Grados:\n";
			for (auto dummy : (*main.getListaGrados())) dummy.printGrado();
			break;
		case 2:
			cout << "Lista Alumnos:\n";
			for (auto dummy : (*main.getListaAlumnos())) dummy.printAlumno();
			break;
		case 3:
			cout << "Lista Profesores:\n";
			for (auto dummy : (*main.getListaProfesores())) dummy.printProfesor();
			break;
		case 4:
            main.addGrado(crearGrado());
			break;
		case 5:
            main.addAlumno(crearAlumno(&main));
			break;
		case 6:
            main.addProfesor(crearProfesor(&main));
			break;
		case 7:
			cout << "Que grado quieres borrar?(ID)  ";
			cin >> dummy_S;
			borrarGrado(&main, dummy_S);
			break;
		case 8:
			cout << "Que alumno quieres borrar?(ID)  ";
			cin >> dummy_S;
			borrarAlumno(&main, dummy_S);
			break;
		case 9:
			cout << "Que Profesor quieres borrar?(ID)  ";
			cin >> dummy_S;
			borrarProfesor(&main, dummy_S);
			break;
		case 10:
			cout << "Inserte el path: ";
			cin >> dummy_S;
			importarAlumnos((char *)dummy_S.c_str(),&main, main.getGrado("Grado1"));
			break;
		case 11:
			cout << "Inserte el path: ";
			cin >> dummy_S;
			importarProfesores((char *)dummy_S.c_str(), &main);
			break;
		case 12:
			cout << "Inserte el path: ";
			cin >> dummy_S;
			importarHorarios((char *)dummy_S.c_str(), &main);
			break;
		default:
			cout << "Esa opcion no existe\n";
			break;
		}

	}

	prepareR(&main, 1);

    return qApplication.exec();
}
