#include "Header.h"

static int BBDD callback(void *NotUsed, int argc, char **argv, char **azColName) {
	int i;
	for (i = 0; i < argc; i++) {
		printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
	}
	printf("\n");
	return 0;
}

void BBDD crearTablaHorario(sqlite3 *bd) {
	char sql[] = "CREATE TABLE IF NOT EXISTS horarios(" \
		"nombre TEXT  PRIMARY KEY NOT NULL,"\
		"dia INT,"\
		"sloot1 INT,"\
		"sloot2 INT,"\
		"sloot3 INT,"\
		"sloot4 INT,"\
		"sloot5 INT,"\
		"sloot6 INT,"\
		"sloot7 INT);";

	char * error = NULL;
	int resultado = sqlite3_exec(bd, sql, 0, 0, &error);

	if (resultado != SQLITE_OK) {
		fprintf(stderr, "SQL error: %s\n", error);
		sqlite3_free(error);
	}
	else {
		fprintf(stdout, "Table created successfully\n");
	}

}

void BBDD crearTablaAlumno(sqlite3 *bd)
{
	char sql[] = "CREATE TABLE IF NOT EXISTS alumnos(" \
		"nombre TEXT,"\
		"apellido TEXT,"\
		"ID TEXT PRIMARY KEY NOT NULL,"\
		"grado TEXT);";
	char * error = NULL;
	int resultado = sqlite3_exec(bd, sql, 0, 0, &error);

	if (resultado != SQLITE_OK) {
		fprintf(stderr, "SQL error: %s\n", error);
		sqlite3_free(error);
	}
	else {
		fprintf(stdout, "Table created successfully\n");
	}

}

void BBDD crearTablaProfesor(sqlite3 *bd)
{
	char sql[] = "CREATE TABLE IF NOT EXISTS profesores(" \
		"nombreCompleto TEXT,"\
		"doctor INT);";

	char * error = NULL;
	int resultado = sqlite3_exec(bd, sql, 0, 0, &error);

	if (resultado != SQLITE_OK) {
		fprintf(stderr, "SQL error: %s\n", error);
		sqlite3_free(error);
	}
	else {
		fprintf(stdout, "Table created successfully\n");
	}

}

void BBDD insertarHorario(sqlite3 * bd, Horario horario)
{
	string sql = "INSERT OR REPLACE INTO horarios(nombre,dia,sloot1,sloot2,sloot3,sloot4,sloot5,sloot6,sloot7) VALUES ('";
	sql += horario.getProfesor().getNombre(); sql += "',";
	sql += to_string(horario.getDia()); sql += ",";
	sql += to_string(horario.getSloot(2)); sql += ", ";
	sql += to_string(horario.getSloot(3)); sql += ", ";
	sql += to_string(horario.getSloot(4)); sql += ", ";
	sql += to_string(horario.getSloot(5)); sql += ", ";
	sql += to_string(horario.getSloot(6)); sql += ", ";
	sql += to_string(horario.getSloot(7)); sql += ", ";
	sql += to_string(horario.getSloot(8)); sql += ");";
	char * error = NULL;

	int resultado = sqlite3_exec(bd, sql.c_str(), 0, 0, &error);

	if (resultado != SQLITE_OK) {
		fprintf(stderr, "SQL error: %s\n", error);
		sqlite3_free(error);
	}
}

void BBDD insertarAlumno(sqlite3 * bd, Alumno alumno)
{
	string sql = "INSERT OR REPLACE INTO alumnos (nombre,apellido,ID,grado) VALUES ('";
	sql += alumno.getNombre(); sql += "', '";
	sql += alumno.getApellido(); sql += "', '";
	sql += alumno.getID(); sql += "','";
	sql += alumno.getGrado(); sql += "');";

	char * error = NULL;
	int resultado = sqlite3_exec(bd, sql.c_str(), 0, 0, &error);

	if (resultado != SQLITE_OK) {
		fprintf(stderr, "SQL error: %s\n", error);
		sqlite3_free(error);
	}
}

void BBDD insertarProfesor(sqlite3 * bd, Profesor profesor)
{
	string sql = "INSERT OR REPLACE INTO profesores (nombreCompleto, doctor) VALUES ('";
	sql += profesor.getNombre(); sql += "', ";
	sql += to_string(profesor.getDoctor()); sql += ");";

	char * error = NULL;
	int resultado = sqlite3_exec(bd, sql.c_str(), 0, 0, &error);

	if (resultado != SQLITE_OK) {
		fprintf(stderr, "SQL error: %s\n", error);
		sqlite3_free(error);
	}
}

void BBDD insertarHorarios(vector<Horario> lista, sqlite3 * db)
{
	for (auto dummy : lista) insertarHorario(db, dummy);
}

void BBDD insertarAlumnos(vector<Alumno> lista, sqlite3 * db)
{
	for (auto dummy : lista) insertarAlumno(db, dummy);
}

void BBDD insertarProfesores(vector<Profesor> lista, sqlite3 * db)
{
	for (auto dummy : lista) insertarProfesor(db, dummy);
}
