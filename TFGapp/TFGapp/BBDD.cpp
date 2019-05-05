#include "Header.h"

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
		std::cout << "ERROR: SQL Open\n";
	return db;
}

void BBDD cargarBasedeDatos(sqlite3 *bd)
{
	crearTablaProfesores(bd);
	crearTablaGrados(bd);
	crearTablaAlumnos(bd);
	crearTablaDisponibilidad(bd);
	crearTablaTFG(bd);
	crearTablaPresentaciones(bd);
	crearTablaTribunales(bd);
	crearTablaEspecialidades(bd);
}

void BBDD emptyDB(sqlite3 * db)
{
	sqlite3_exec(db, "DROP TABLE alumnos;", 0, 0, 0);
	sqlite3_exec(db, "DROP TABLE profesores;", 0, 0, 0);
	sqlite3_exec(db, "DROP TABLE grados;", 0, 0, 0);
	sqlite3_exec(db, "DROP TABLE especialidades;", 0, 0, 0);
	sqlite3_exec(db, "DROP TABLE disponibilidad;", 0, 0, 0);
	sqlite3_exec(db, "DROP TABLE TFG;", 0, 0, 0);
	sqlite3_exec(db, "DROP TABLE presentaciones;", 0, 0, 0);
	sqlite3_exec(db, "DROP TABLE tribunales;", 0, 0, 0);
}


void BBDD crearTablaProfesores(sqlite3 *bd)
{
	char sql[] = "CREATE TABLE IF NOT EXISTS profesores(" \
		"nombreCompleto TEXT PRIMARY KEY," \
		"doctor INT);";

	char * error = NULL;
	int resultado = sqlite3_exec(bd, sql, 0, 0, &error);
	checkError(resultado, error);
}

void BBDD crearTablaGrados(sqlite3 *bd)
{
	char sql[] = "CREATE TABLE IF NOT EXISTS grados("\
		"nombre TEXT PRIMARY KEY NOT NULL);";

	char * error = NULL;
	int resultado = sqlite3_exec(bd, sql, 0, 0, &error);
	checkError(resultado, error);
}

void BBDD crearTablaAlumnos(sqlite3 *bd)
{
	char sql[] = "CREATE TABLE IF NOT EXISTS alumnos(" \
		"nombre TEXT,"\
		"apellidos TEXT,"\
		"ID TEXT PRIMARY KEY,"\
		"grado TEXT,"\
		"FOREIGN KEY(grado) REFERENCES grados(nombre)" \
		"ON UPDATE CASCADE ON DELETE SET NULL);";

	char * error = NULL;
	int resultado = sqlite3_exec(bd, sql, 0, 0, &error);
	checkError(resultado, error);
}

void BBDD crearTablaDisponibilidad(sqlite3 *bd) {
	char sql[] = "CREATE TABLE IF NOT EXISTS disponibilidad(" \
		"nombreProfesor TEXT,"\
		"dia INT,"\
		"slot1 INT,"\
		"slot2 INT,"\
		"slot3 INT,"\
		"slot4 INT,"\
		"slot5 INT,"\
		"slot6 INT,"\
		"slot7 INT,"\
		"PRIMARY KEY(nombreProfesor, dia),"\
		"FOREIGN KEY(nombreProfesor) REFERENCES profesores(nombreCompleto)" \
		"ON UPDATE CASCADE ON DELETE CASCADE );";

	char * error = NULL;
	int resultado = sqlite3_exec(bd, sql, 0, 0, &error);
	checkError(resultado, error);
}

void BBDD crearTablaTFG(sqlite3 *bd)
{
	char sql[] = "CREATE TABLE IF NOT EXISTS TFG(" \
		"titulo TEXT," \
		"presentado TEXT," \
		"tutor TEXT," \
		"cotutor TEXT," \
		"alumno TEXT," \
		"FOREIGN KEY(tutor) REFERENCES profesores(nombreCompleto)" \
		"ON UPDATE CASCADE ON DELETE SET NULL," \
		"FOREIGN KEY(cotutor) REFERENCES profesores(nombreCompleto)" \
		"ON UPDATE CASCADE ON DELETE SET NULL," \
		"FOREIGN KEY(alumno) REFERENCES alumnos(ID)" \
		"ON UPDATE CASCADE ON DELETE CASCADE," \
		"PRIMARY KEY(titulo, alumno));";

	char * error = NULL;
	int resultado = sqlite3_exec(bd, sql, 0, 0, &error);
	checkError(resultado, error);
}

void BBDD crearTablaPresentaciones(sqlite3 *bd){
	char sql[] = "CREATE TABLE IF NOT EXISTS presentaciones(" \
		"ID TEXT," \
		"hora INT," \
		"dia INT," \
		"aula INT," \
		"slot INT," \
		"convocatoria INT," \
		"FOREIGN KEY(ID) REFERENCES alumnos(ID)" \
		"ON UPDATE CASCADE ON DELETE CASCADE," \
		"PRIMARY KEY(convocatoria, ID));";

	char * error = NULL;
	int resultado = sqlite3_exec(bd, sql, 0, 0, &error);
	checkError(resultado, error);
}

void BBDD crearTablaTribunales(sqlite3 *bd)
{
	char sql[] = "CREATE TABLE IF NOT EXISTS tribunales(" \
		"presentacion TEXT," \
		"profesor TEXT," \
		"convocatoria INT," \
		"FOREIGN KEY(presentacion) REFERENCES presentaciones(ID)" \
		"ON UPDATE CASCADE ON DELETE CASCADE," \
		"FOREIGN KEY(profesor) REFERENCES profesores(nombreCompleto)" \
		"ON UPDATE CASCADE ON DELETE CASCADE," \
		"FOREIGN KEY(convocatoria) REFERENCES presentaciones(convocatoria)" \
		"ON UPDATE CASCADE ON DELETE CASCADE," \
		"PRIMARY KEY(presentacion, profesor, convocatoria));";

	char * error = NULL;
	int resultado = sqlite3_exec(bd, sql, 0, 0, &error);
	checkError(resultado, error);
}

void BBDD crearTablaEspecialidades(sqlite3 * bd)
{
	char sql[] = "CREATE TABLE IF NOT EXISTS especialidades(" \
		"nombreProfesor TEXT," \
		"nombreGrado TEXT," \
		"numeroMax INT, "\
		"FOREIGN KEY(nombreProfesor) REFERENCES profesores(nombreCompleto)" \
		"ON UPDATE CASCADE ON DELETE CASCADE, "\
		"FOREIGN KEY(nombreGrado) REFERENCES grados(nombre)" \
		"ON UPDATE CASCADE ON DELETE SET NULL," \
		"PRIMARY KEY (nombreProfesor, nombreGrado));";

	char * error = NULL;
	int resultado = sqlite3_exec(bd, sql, 0, 0, &error);
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

void BBDD insertarGrado(sqlite3 * bd, Grado grado)
{
	string sql = "INSERT OR REPLACE INTO grados (nombre) VALUES ('";
	sql += grado.getNombre(); sql += "');";

	char * error = NULL;
	int resultado = sqlite3_exec(bd, sql.c_str(), 0, 0, &error);
	checkError(resultado, error);
}

void BBDD insertarAlumno(sqlite3 * bd, Alumno alumno)
{
	string sql = "INSERT OR REPLACE INTO alumnos(nombre,apellidos,ID,grado) VALUES ('";
	sql += alumno.getNombre(); sql += "', '";
	sql += alumno.getApellido(); sql += "', '";
	sql += alumno.getID(); sql += "','";
	sql += alumno.getGrado()->getNombre(); sql += "');";

	char * error = NULL;
	int resultado = sqlite3_exec(bd, sql.c_str(), 0, 0, &error);
	checkError(resultado, error);
}

void BBDD insertarDisponibilidad(sqlite3 * bd, Horario horario)
{
	string sql = "INSERT OR REPLACE INTO disponibilidad(nombreProfesor,dia,slot1,slot2,slot3,slot4,slot5,slot6,slot7) VALUES ('";
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

void BBDD insertarTFG(sqlite3 * bd, Alumno alumno)
{
	TFG * tfg = alumno.getTFG();
	string sql = "INSERT OR REPLACE INTO TFG(titulo, presentado, tutor, cotutor, alumno) VALUES ('";
	sql += tfg->getTitulo(); sql += "','";
	sql += to_string(tfg->getPresentado()); sql += "','";
	sql += (tfg->getTutor() == NULL) ? "null" : tfg->getTutor()->getNombre(); sql += "', '";
	sql += (tfg->getCotutor() == NULL) ? "null" : tfg->getCotutor()->getNombre(); sql += "', '";
	sql += alumno.getID(); sql += "');";

	char * error = NULL;
	int resultado = sqlite3_exec(bd, sql.c_str(), 0, 0, &error);
	checkError(resultado, error);
}

void BBDD insertarPresentacion(sqlite3 * bd, Alumno alumno)
{
	Presentacion * presentacion = alumno.getTFG()->getPresentacion();
	string sql = "INSERT OR REPLACE INTO presentaciones(ID, hora, dia, aula, slot, convocatoria) VALUES ('";
	sql += alumno.getID(); sql += "',";
	sql += to_string(presentacion->getHora()); sql += ", ";
	sql += to_string(presentacion->getDia()); sql += ", ";
	sql += to_string(presentacion->getAula()); sql += ", ";
	sql += to_string(presentacion->getSlot()); sql += ", ";
	sql += to_string(presentacion->getConvocatoria()); sql += ");";

	char * error = NULL;
	int resultado = sqlite3_exec(bd, sql.c_str(), 0, 0, &error);
	checkError(resultado, error);
}

void BBDD insertarTribunales(sqlite3 * bd, Alumno alumno)
{
	Presentacion * presentacion = alumno.getTFG()->getPresentacion();
	for (int i = 0; i < presentacion->getTribunal()->size(); i++)
	{
		string sql = "INSERT OR REPLACE INTO tribunales(presentacion,profesor,convocatoria) VALUES ('";
		sql += alumno.getID(); sql += "','";
		sql += (*presentacion->getTribunal())[i]->getNombre(); sql += "', ";
		sql += to_string(presentacion->getConvocatoria()); sql += ");";

		char * error = NULL;
		int resultado = sqlite3_exec(bd, sql.c_str(), 0, 0, &error);
		checkError(resultado, error);
	}

}

void BBDD insertarEspecialidad(sqlite3 * bd, Profesor profesor)
{
	for (int i = 0; i < profesor.getListaGrados()->size(); i++)
	{
		string sql = "INSERT OR REPLACE INTO especialidades(nombreProfesor,nombreGrado,numeroMax) VALUES ('";
		sql += profesor.getNombre(); sql += "','";
		sql += (*profesor.getListaGrados())[i]->getNombre(); sql += "', ";
		sql += to_string((*profesor.getListaNTFG())[i]); sql += ");";

		char * error = NULL;
		int resultado = sqlite3_exec(bd, sql.c_str(), 0, 0, &error);
		checkError(resultado, error);
	}
	
}

void BBDD borrarProfesor(sqlite3 * bd, Profesor profesor)
{
}

void BBDD borrarGrado(sqlite3 * bd, string id)
{
	string sql = "DELETE FROM grados WHERE nombre='";
	sql += id; sql += "';";

	char * error = NULL;
	int resultado = sqlite3_exec(bd, sql.c_str(), 0, 0, &error);
	checkError(resultado, error);
}

void BBDD borrarAlumno(sqlite3 * bd, Alumno alumno)
{
}

void BBDD borrarDisponibilidad(sqlite3 * bd, Horario horario)
{
}

void BBDD borrarTFG(sqlite3 * bd, Alumno alumno)
{
}

void BBDD borrarPresentacion(sqlite3 * bd, Alumno alumno)
{
}

void BBDD borrarTribunales(sqlite3 * bd, Alumno alumno)
{
}

void BBDD borrarEspecialidad(sqlite3 * bd, Profesor profesor)
{
}