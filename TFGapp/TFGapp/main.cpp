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

	importarProfesores(pathP , &main);
	importarAlumnos(pathA, &main);
	importarHorarios(pathD, &main);

	////for (auto dummy : lista) dummy.printAlumno();
	//// for (auto dummy : lista2) dummy.printProfesor();

	//insertarProfesores(listaProfesores, db);
	//insertarAlumnos(listaAlumnos, db);
	//insertarHorarios(listaHorarios, db);

	sqlite3_close(db);

	return 0;
}