#pragma once
#include "sqlite3/sqlite3.h"
#include "Profesor.h"
#include "Alumno.h"
#include "Grado.h"
#include "Horario.h"

class Controller
{
	vector <Alumno> alumnos;
	vector <Profesor> profesores;
	vector <Grado> grados;
	sqlite3 *db;
	int diaMax = 7;

public:
	Controller(sqlite3 *db);
	~Controller();

	vector <Alumno>* getListaAlumnos();
	vector <Profesor>* getListaProfesores();
	vector <Grado>* getListaGrados();
	sqlite3 * getDB();
	int getDiaMax();

	void setDB(sqlite3 *db);
	void setListaAlumnos(vector <Alumno>* alumnos);
	void setListaGrados(vector <Grado>* grados);
	void setListaProfesores(vector <Profesor>* profesores);
	void setDiaMax(int dia);

	Alumno* getAlumno(string id); //Busca por ID y devulve el objeto o NULL si no lo encuentra
	Profesor* getProfesor(string id); //Busca por ID y devulve el objeto o NULL si no lo encuentra
	Grado* getGrado(string id); //Busca por ID y devulve el objeto o NULL si no lo encuentra

	int addAlumno(Alumno alumno, bool ins=true);
	int addProfesor(Profesor profesor, bool ins = true);
	int addGrado(Grado grado, bool ins = true);
	void addHorario(Horario horario, bool ins = true);

	void eliminarAlumno(string id);
	void eliminarProfesor(string id);
	void eliminarGrado(string id);
	void enlazarTutor(Alumno *alumno, Profesor *profesor);
	void enlazarCoTutor(Alumno *alumno, Profesor *profesor);

	void modificarGrado(Grado * actual, Grado cambio);
};

