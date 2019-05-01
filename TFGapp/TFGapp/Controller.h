#pragma once
#include "Profesor.h"
#include "Alumno.h"
#include "Grado.h"
#include "Horario.h"

class Controller
{
	vector <Alumno> alumnos;
	vector <Profesor> profesores;
	vector <Grado> grados;

public:
	Controller();
	~Controller();

	vector <Alumno>* getListaAlumnos();
	vector <Profesor>* getListaProfesores();
	vector <Grado>* getListaGrados();
	void setListaAlumnos(vector <Alumno>* alumnos);
	void setListaGrados(vector <Grado>* grados);
	void setListaProfesores(vector <Profesor>* profesores);

	Alumno* getAlumno(string id);
	Profesor* getProfesor(string id);
	Grado* getGrado(string id);

	void addAlumno(Alumno *alumno);
	void addProfesor(Profesor *profesor);
	void addGrado(Grado *grado);

	void eliminarAlumno(string id);
	void eliminarProfesor(string id);
	void eliminarGrado(string id);
	void enlazarTutor(Alumno *alumno, Profesor *profesor);
	void enlazarCoTutor(Alumno *alumno, Profesor *profesor);
};

