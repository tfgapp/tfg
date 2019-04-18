#include "Header.h"

#define CLEAR 1

int main()
{
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

	vector<Grado> listaGrados;

	char path2[] = "../datos_profesor.csv";
	vector<Profesor> listaProfesores = importarProfesores(path2 , &listaGrados);

	char path[] = "../datos_alumno.csv";
	vector<Alumno> listaAlumnos = importarAlumnos(path, &listaGrados);

	char path3[] = "../datos_disponibilidad.csv";
	vector<Horario> listaHorarios = importarHorarios(path3, &listaProfesores);

	//for (auto dummy : lista) dummy.printAlumno();
	// for (auto dummy : lista2) dummy.printProfesor();

	insertarProfesores(listaProfesores, db);
	insertarAlumnos(listaAlumnos, db);
	insertarHorarios(listaHorarios, db);

	sqlite3_close(db);

	return 0;
}