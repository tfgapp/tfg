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

public:
	Controller();
	Controller(sqlite3 *db);
	~Controller();

	vector <Alumno>* getListaAlumnos();
	vector <Profesor>* getListaProfesores();
	vector <Grado>* getListaGrados();
	sqlite3 * getDB();

	void setDB(sqlite3 *db);
	void setListaAlumnos(vector <Alumno>* alumnos);
	void setListaGrados(vector <Grado>* grados);
	void setListaProfesores(vector <Profesor>* profesores);

	Alumno* getAlumno(string id); //Busca por ID y devulve el objeto o NULL si no lo encuentra
	Profesor* getProfesor(string id); //Busca por ID y devulve el objeto o NULL si no lo encuentra
	Grado* getGrado(string id); //Busca por ID y devulve el objeto o NULL si no lo encuentra

	void addAlumno(Alumno alumno);
	void addProfesor(Profesor profesor);
	void addGrado(Grado grado);

	void eliminarAlumno(string id);
	void eliminarProfesor(string id);
	void eliminarGrado(string id);
	void enlazarTutor(Alumno *alumno, Profesor *profesor);
	void enlazarCoTutor(Alumno *alumno, Profesor *profesor);
};

