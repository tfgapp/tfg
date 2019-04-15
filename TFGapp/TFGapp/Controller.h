#pragma once
#include <vector>
#include "Header.h"
class Controller
{
	vector <Alumno> alumnos;
	vector <Profesor> profesores;
	vector <Grado> grados;
	

public:
	vector <Alumno>* getListaAlumnos() {
		return &alumnos;
	}
	vector <Profesor>* getListaProfesores(){
		return &profesores;
	}
	vector <Grado>* getListaGrados() {
		return &grados;
	}
	Alumno* getAlumno(string id) {
		for (int i = 0; i < alumnos.size(); i++) {
			if (id = alumnos[i].getID) {
				return &alumnos[i];
			}
		}
		return NULL;
	}
	Profesor* getProfesor(string id) {
		for (int i = 0; i < profesores.size(); i++) {
			if (id = profesores[i].getNombre) {
				return &profesores[i];
			}
		}
		return NULL;
	}
	Grado* getGrado(string id) {
		for (int i = 0; i < grados.size(); i++) {
			if (id = grados[i].getNombre) {
				return &grados[i];
			}
		}
		return NULL;
	}
	void addAlumno(Alumno *alumno) {
		alumnos.push_back(*alumno);
	}
	void addProfesor(Profesor *profesor) {
		profesores.push_back(*profesor);
	}
	void addGrado(Grado *grado) {
		grados.push_back(*grado);
	}
	void eliminarAlumno(string id) {
		for (int i = 0; i < alumnos.size(); i++) {
			if (id = alumnos[i].getID) {
				alumnos.erase(alumnos.begin() + i);
			}
		}
	}
	void eliminarProfesor(string id) {
		for (int i = 0; i < profesores.size(); i++) {
			if (id = profesores[i].getNombre) {
				profesores.erase(profesores.begin() + i);
			}
		}
	}
	void eliminarGrado(string id) {
		for (int i = 0; i < grados.size(); i++) {
			if (id = grados[i].getNombre) {
				grados.erase(grados.begin() + i);
			}
		}
	}
	

	Controller();
	~Controller();
};

