#include "Header.h"

static int BBDD callback(void *NotUsed, int argc, char **argv, char **azColName) {
	int i;
	for (i = 0; i < argc; i++) {
		printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
	}
	printf("\n");
	return 0;
}

void BBDD crearTablaAlumno(sqlite3 *bd)
{
	char sql[] = "CREATE TABLE IF NOT EXISTS alumnos(" \
		"nombre TEXT,"\
		"apellido1 TEXT,"\
		"apellido2 TEXT,"\
		"correo VARCHAR PRIMARY KEY NOT NULL,"\
		"grado INT);";
	char * error = NULL;
	int resultado = sqlite3_exec(bd, sql, callback, 0, &error);

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
		"nombre TEXT,"\
		"apellido1 TEXT,"\
		"apellido2 TEXT,"\
		"correo VARCHAR PRIMARY KEY NOT NULL,"\
		"doctor INT);";
	char * error = NULL;
	int resultado = sqlite3_exec(bd, sql, callback, 0, &error);

	if (resultado != SQLITE_OK) {
		fprintf(stderr, "SQL error: %s\n", error);
		sqlite3_free(error);
	}
	else {
		fprintf(stdout, "Table created successfully\n");
	}

}

void BBDD insertarAlumno(sqlite3 * bd, Alumno alumno)
{
	string sql = "INSERT OR REPLACE INTO alumnos (nombre,apellido1,apellido2,correo,grado) VALUES ('";
	sql += alumno.nombre; sql += "', '";
	sql += alumno.apellido1; sql += "', '";
	sql += alumno.apellido2; sql += "', '";
	sql += alumno.correo; sql += "', ";
	sql += to_string(alumno.grado); sql += ");";

	char * error = NULL;
	int resultado = sqlite3_exec(bd, sql.c_str(), 0, 0, &error);

	if (resultado != SQLITE_OK) {
		fprintf(stderr, "SQL error: %s\n", error);
		sqlite3_free(error);
	}
}

void BBDD insertarProfesor(sqlite3 * bd, Profesor profesor)
{
	string sql = "INSERT OR REPLACE INTO profesores (nombre,apellido1,apellido2,correo,doctor) VALUES ('";
	sql += profesor.nombre; sql += "', '";
	sql += profesor.apellido1; sql += "', '";
	sql += profesor.apellido2; sql += "', '";
	sql += profesor.correo; sql += "', ";
	sql += to_string(profesor.doctor); sql += ");";

	char * error = NULL;
	int resultado = sqlite3_exec(bd, sql.c_str(), 0, 0, &error);

	if (resultado != SQLITE_OK) {
		fprintf(stderr, "SQL error: %s\n", error);
		sqlite3_free(error);
	}
}

void BBDD insertarAlumnos(list<Alumno> lista, sqlite3 * db)
{
	for (auto dummy : lista) insertarAlumno(db, dummy);
}

void BBDD insertarProfesores(list<Profesor> lista, sqlite3 * db)
{
	for (auto dummy : lista) insertarProfesor(db, dummy);
}

int CSV leerHeader(ifstream* file)
{
	string dummy;
	getline((*file), dummy, '\n');

	int count = 0;
	for (auto iter : dummy)		if (iter == ',') count++;
	return count + 1;
}

list<Alumno> CSV importarAlumnos(char path[])
{
	ifstream csv;
	csv.open(path);

	int nColumnas = leerHeader(&csv);
	list<Alumno> lista;
	string * dummy = new string[nColumnas];

	while (csv.good())
	{
		for (int i = 0; i < nColumnas - 1; i++)	getline(csv, dummy[i], ',');

		getline(csv, dummy[nColumnas - 1], '\n');

		Alumno dummy_P(dummy[0], dummy[1], dummy[2], dummy[3], dummy[4]);
		lista.push_back(dummy_P);
	}

	csv.close();
	delete[] dummy;
	return lista;
}

list<Profesor> CSV importarProfesores(char path[])
{
	ifstream csv;
	csv.open(path);

	int nColumnas = leerHeader(&csv);
	list<Profesor> lista;
	string * dummy = new string[nColumnas];

	while (csv.good())
	{
		for (int i = 0; i < nColumnas - 1; i++)	getline(csv, dummy[i], ',');

		getline(csv, dummy[nColumnas - 1], '\n');

		Profesor * aux = existeProfesor(&lista ,dummy[3]);
		if (aux == NULL)
		{
			Profesor dummy_P(dummy[0], dummy[1], dummy[2], dummy[3], dummy[5]);
			dummy_P.addGrado(dummy[4], dummy[6]);
			lista.push_back(dummy_P);
		}
		else
			aux->addGrado(dummy[4], dummy[6]);
		
	}

	csv.close();
	delete[] dummy;
	return lista;
}

Profesor * UTILITY existeProfesor(list<Profesor> *lista, string correo)
{
	for (auto iterator = lista->begin(), end = lista->end(); iterator != end; ++iterator) 
		if ((*iterator).correo == correo)
			return &(*iterator);
	return NULL;
}