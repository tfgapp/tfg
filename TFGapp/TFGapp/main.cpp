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

	cout << "Añiadiendo datos de CSV...\n";
	importarProfesores(pathP , &main);
	importarAlumnos(pathA, &main);
	importarHorarios(pathD, &main);
	cout << "Datos CSV añiadidos...\n";

	cout << "Lista Grados:\n";
	for (auto dummy : main.getListaGrados) dummy.printGrado();

	cout << "Lista Alumnos:\n";
	for (auto dummy : main.getListaAlumnos) dummy.printAlumno();

	cout << "Lista Profesores:\n";
	for (auto dummy : main.getListaProfesores) dummy.printProfesor();

	//insertarProfesores(listaProfesores, db);
	//insertarAlumnos(listaAlumnos, db);
	//insertarHorarios(listaHorarios, db);

	sqlite3_close(db);

	return 0;
}