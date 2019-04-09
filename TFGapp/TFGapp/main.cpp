#include "Header.h"

#define CLEAR 1

int main()
{
	sqlite3 *db;
	int rc = sqlite3_open("test.db", &db);
	if (rc != SQLITE_OK)
	{
		std::cout << "ERROR: SQL Open" << '\n';
		return -1;
	}
	if (CLEAR)
	{
		sqlite3_exec(db, "DROP TABLE alumnos", 0, 0, 0);
		crearTablaAlumno(db);
		sqlite3_exec(db, "DROP TABLE profesores", 0, 0, 0);
		crearTablaProfesor(db);
		sqlite3_exec(db, "DROP TABLE horarios", 0, 0, 0);
		crearTablaHorario(db);
	}

	vector<Grado> lista_G;

	char path2[] = "../datos_profesor.csv";
	vector<Profesor> lista2 = importarProfesores(path2 , &lista_G);

	char path[] = "../datos_alumno.csv";
	vector<Alumno> lista = importarAlumnos(path, &lista_G);

	char path3[] = "../datos_disponibilidad.csv";
	vector<Horario> lista3 = importarHorarios(path3, &lista2);

	//for (auto dummy : lista) dummy.printAlumno();
	// for (auto dummy : lista2) dummy.printProfesor();

	insertarProfesores(lista2, db);
	insertarAlumnos(lista, db);
	insertarHorarios(lista3, db);

	sqlite3_close(db);

	return 0;
}