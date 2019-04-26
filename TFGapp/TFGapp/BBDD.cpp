#include "Header.h"

static int BBDD callback(void *NotUsed, int argc, char **argv, char **azColName) {
	int i;
	for (i = 0; i < argc; i++) {
		printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
	}
	printf("\n");
	return 0;
}

void BBDD checkError(int resultado, char * error)
{
	if (resultado != SQLITE_OK) {
		printf("SQL error: %s\n", error);
		sqlite3_free(error);
	}
}

sqlite3 * openBBDD(const char * path)
{
	sqlite3 *db = NULL;
	int rc = sqlite3_open("test.db", &db);
	if (rc != SQLITE_OK)
		std::cout << "ERROR: SQL Open" << '\n';
	return db;
}

void BBDD crearTablaProfesor(sqlite3 *bd)
{
	char sql[] = "CREATE TABLE IF NOT EXISTS profesores(" \
		"nombreCompleto TEXT," \
		"doctor INT);";

	char * error = NULL;
	int resultado = sqlite3_exec(bd, sql, 0, 0, &error);
	checkError(resultado, error);
}

void BBDD crearTablaHorario(sqlite3 *bd) {
	char sql[] = "CREATE TABLE IF NOT EXISTS horarios(" \
		"nombre TEXT NOT NULL,"\
		"dia INT,"\
		"sloot1 INT,"\
		"sloot2 INT,"\
		"sloot3 INT,"\
		"sloot4 INT,"\
		"sloot5 INT,"\
		"sloot6 INT,"\
		"sloot7 INT,"\
		"PRIMARY KEY(nombre, dia),"\
		"FOREIGN KEY(nombre) REFERENCES profesores(nombreCompleto) ON UPDATE CASCADE ON DELETE CASCADE );";

	char * error = NULL;
	int resultado = sqlite3_exec(bd, sql, 0, 0, &error);
	checkError(resultado, error);
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
	checkError(resultado, error);
}

void BBDD crearTablaTFG(sqlite3 *bd)
{
	char sql[] = "CREATE TABLE IF NOT EXISTS TFG(" \
		"titulo TEXT PRIMARY KEY NOT NULL," \
		"presentado TEXT," \
		"tutor TEXT," \
		"cotutor TEXT," \
		"presentacion TEXT," \
		"FOREIGN KEY(tutor) REFERENCES profesores(nombreCompleto)" \
		"ON UPDATE CASCADE ON DELETE CASCADE," \
		"FOREIGN KEY(cotutor) REFERENCES profesores(nombreCompleto)" \
		"ON UPDATE CASCADE ON DELETE CASCADE," \
		"FOREIGN KEY(presentacion) REFERENCES presentacion(idPresentacion)" \
		"ON UPDATE CASCADE ON DELETE CASCADE);";

	char * error = NULL;
	int resultado = sqlite3_exec(bd, sql, 0, 0, &error);
	checkError(resultado, error);
}

void BBDD crearTablaPresentacion(sqlite3 *bd){
	char sql[] = "CREATE TABLE IF NOT EXISTS alumnos(" \
		"idPresentacion TEXT PRIMARY KEY NOT NULL," \
		"hora INT," \
		"dia INT," \
		"aula INT," \
		"slot INT," \
		"convocatoria INT," \
		//vector<Profesor *> tribunal, #Revisar por que puede ser turbio para implementar
		");";

	char * error = NULL;
	int resultado = sqlite3_exec(bd, sql, 0, 0, &error);
	checkError(resultado, error);
}

void BBDD crearTablaGrado(sqlite3*bd) {
	char sql[] = "CREATE TABLE IF NOT EXISTS grados("\
		"nombre TEXT PRIMARY KEY NOT NULL"\
		");";

	char * error = NULL;
	int resultado = sqlite3_exec(bd, sql, 0, 0, &error);
	checkError(resultado, error);
}

void BBDD insertarHorario(sqlite3 * bd, Horario horario)
{
	string sql = "INSERT OR REPLACE INTO horarios(nombre,dia,sloot1,sloot2,sloot3,sloot4,sloot5,sloot6,sloot7) VALUES ('";
	sql += horario.getProfesor()->getNombre(); sql += "',";
	sql += to_string(horario.getDia()); sql += ",";
	sql += to_string(horario.getSloot(0)); sql += ", ";
	sql += to_string(horario.getSloot(1)); sql += ", ";
	sql += to_string(horario.getSloot(2)); sql += ", ";
	sql += to_string(horario.getSloot(3)); sql += ", ";
	sql += to_string(horario.getSloot(4)); sql += ", ";
	sql += to_string(horario.getSloot(5)); sql += ", ";
	sql += to_string(horario.getSloot(6)); sql += ");";

	char * error = NULL;
	int resultado = sqlite3_exec(bd, sql.c_str(), 0, 0, &error);
	checkError(resultado, error);
}

void BBDD insertarAlumno(sqlite3 * bd, Alumno alumno)
{
	string sql = "INSERT OR REPLACE INTO alumnos (nombre,apellido,ID,grado) VALUES ('";
	sql += alumno.getNombre(); sql += "', '";
	sql += alumno.getApellido(); sql += "', '";
	sql += alumno.getID(); sql += "','";
	sql += alumno.getGrado()->getNombre(); sql += "');";

	char * error = NULL;
	int resultado = sqlite3_exec(bd, sql.c_str(), 0, 0, &error);
	checkError(resultado, error);
}

void BBDD insertarProfesor(sqlite3 * bd, Profesor profesor)
{
	string sql = "INSERT OR REPLACE INTO profesores (nombreCompleto, doctor) VALUES ('";
	sql += profesor.getNombre(); sql += "', ";
	sql += to_string(profesor.getDoctor()); sql += ");";

	char * error = NULL;
	int resultado = sqlite3_exec(bd, sql.c_str(), 0, 0, &error);
	checkError(resultado, error);
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
