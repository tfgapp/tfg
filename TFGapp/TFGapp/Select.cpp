#include "Header.h"

static int SELECT callbackGrados(void *data, int argc, char **argv, char **azColName) 
{
	Controller * main = (Controller *)data;
	main->addGrado(Grado(argv[0]), false);
	return 0;
}

void SELECT volcarGrados(Controller * main)
{
	char sql[] = "SELECT * FROM grados;";

	char * error = NULL;
	int resultado = sqlite3_exec(main->getDB(), sql, callbackGrados, main, &error);
	checkError(resultado, error);
}

static int SELECT callbackProfesores(void *data, int argc, char **argv, char **azColName)
{
	Controller * main = (Controller *)data;
	Profesor dummy_P(argv[0], argv[1]);
	int pos = main->addProfesor(dummy_P, false);
	Profesor * profesor = &(*main->getListaProfesores())[pos];
	//Cargamos las disponibilidades de profesor
	string sql = "SELECT * FROM disponibilidad WHERE nombreProfesor='";
	sql += argv[0]; sql += "';";
	char * error = NULL;
	int resultado = sqlite3_exec(main->getDB(), sql.c_str(), callbackDisponibilidad, profesor, &error);
	checkError(resultado, error);
	//Cargamos los grados de profesor
	sql = "SELECT * FROM especialidades WHERE nombreProfesor='";
	sql += argv[0]; sql += "';";
	error = NULL;
	resultado = sqlite3_exec(main->getDB(), sql.c_str(), callbackEspecialidad, main, &error);
	checkError(resultado, error);

	for (int i = 0; i < profesor->getListaHorarios()->size(); i++)
	{
		if ((*profesor->getListaHorarios())[i].getDia() > main->getDiaMax())
			main->setDiaMax((*profesor->getListaHorarios())[i].getDia());
	}

	return 0;
}

static int SELECT callbackDisponibilidad(void *data, int argc, char **argv, char **azColName)
{
	Profesor * profesor = (Profesor *)data;
	bool slots[7] = { stoi(argv[2]), stoi(argv[3]) , stoi(argv[4]) , stoi(argv[5]) , stoi(argv[6]) , stoi(argv[7]) , stoi(argv[8]) };
	Horario dumm_H(stoi(argv[1]), slots, profesor);
	profesor->addHorario(dumm_H);

	return 0;
}

static int SELECT callbackEspecialidad(void *data, int argc, char **argv, char **azColName)
{
	Controller * main = (Controller *)data;
	Profesor * dummy_P = &(*main->getListaProfesores())[main->getListaProfesores()->size() - 1];
	dummy_P->addGrado(main->getGrado(argv[1]), stoi(argv[2]));

	return 0;
}

void SELECT volcarProfesores(Controller * main)
{
	char sql[] = "SELECT * FROM profesores;";

	char * error = NULL;
	int resultado = sqlite3_exec(main->getDB(), sql, callbackProfesores, main, &error);
	checkError(resultado, error);
}

static int SELECT callbackAlumnos(void *data, int argc, char **argv, char **azColName)
{
	Controller * main = (Controller *)data;
	Alumno dummy_A(argv[0], argv[1], argv[2], main->getGrado(argv[3]));
	int pos = main->addAlumno(dummy_A, false);
	Alumno * alumno = &(*main->getListaAlumnos())[pos];
	//TODO TFG
	string sql = "SELECT * FROM TFG WHERE alumno='";
	sql += argv[2]; sql += "';";
	char * error = NULL;
	int resultado = sqlite3_exec(main->getDB(), sql.c_str(), callbackTFG, main, &error);
	checkError(resultado, error);

	return 0;
}

static int SELECT callbackTFG(void *data, int argc, char **argv, char **azColName)
{
	Controller * main = (Controller *)data;
	Alumno * alumno = main->getAlumno(argv[4]);
	TFG dumm_t(argv[0], stoi(argv[1]));
	dumm_t.setTutor(main->getProfesor(argv[2]));
	dumm_t.setCoTutor(main->getProfesor(argv[3]));
	alumno->setTFG(dumm_t);
	return 0;
}

void SELECT volcarAlumnos(Controller * main)
{
	char sql[] = "SELECT * FROM alumnos;";

	char * error = NULL;
	int resultado = sqlite3_exec(main->getDB(), sql, callbackAlumnos, main, &error);
	checkError(resultado, error);
}