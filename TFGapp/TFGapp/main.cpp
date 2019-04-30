#include "Header.h"
#include "QApplication"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#define CLEAR 1

int main(int argc, char * argv[] )
{
    QApplication qApplication(argc,argv);
    MainWindow inicio;
    inicio.show();
    /*char pathP[] = "../datos_profesor.csv";
	char pathD[] = "../datos_disponibilidad.csv";
	char pathA[] = "../datos_alumno.csv";

	sqlite3 *db = openBBDD("test.db");

	if (CLEAR)
	{
		sqlite3_exec(db, "DROP TABLE alumnos", 0, 0, 0);
		crearTablaAlumno(db);
		sqlite3_exec(db, "DROP TABLE profesores", 0, 0, 0);
		crearTablaProfesor(db);
		sqlite3_exec(db, "DROP TABLE horarios", 0, 0, 0);
		crearTablaHorario(db);
	}

	Controller main;
	int opc = 1;
	cout << "Añiadiendo datos de CSV...\n";
	importarProfesores(pathP , &main);
	importarAlumnos(pathA, &main);
	importarHorarios(pathD, &main);
	cout << "Datos CSV añiadidos...\n";

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
            main.addAlumno(crearAlumno(main.getListaGrados()));
			break;
		case 6:
            main.addProfesor(crearProfesor(main.getListaGrados()));
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
			importarAlumnos((char *)dummy_S.c_str(),&main);
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
    sqlite3_close(db);*/

    return qApplication.exec();
}
