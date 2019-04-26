#include "Header.h"

#define CLEAR 0

int main()
{
	char pathP[] = "../datos_profesor.csv";
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
			cout << "TODO\n"; 
			break;
		case 5:
			main.addAlumno(&crearAlumno(main.getListaGrados()));
		case 6:
			cout << "TODO\n";
			break;
		case 7:
			cout << "Que garado quieres borrar\n";
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
		default:
			break;
		}

	}


	//insertarProfesores(listaProfesores, db);
	//insertarAlumnos(listaAlumnos, db);
	//insertarHorarios(listaHorarios, db);

	sqlite3_close(db);

	return 0;
}