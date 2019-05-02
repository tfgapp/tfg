#include "Controller.h"
void cargarBasedeDatos(sqlite3 *bd);

Controller::Controller()
{
}

Controller::Controller(sqlite3 *db)
{
	cargarBasedeDatos(db);
	this->db = db;
}

Controller::~Controller()
{
}

vector <Alumno>* Controller::getListaAlumnos() {
	return &alumnos;
}

vector <Profesor>* Controller::getListaProfesores() {
	return &profesores;
}

vector <Grado>* Controller::getListaGrados() {
	return &grados;
}

sqlite3 * Controller::getDB()
{
	return this->db;
}

void Controller::setListaAlumnos(vector <Alumno> *alumnos) {
	this->alumnos = *alumnos;
}

void Controller::setListaGrados(vector <Grado>* grados) {
	this->grados = *grados;
}

void Controller::setListaProfesores(vector <Profesor>* profesores) {
	this->profesores = *profesores;
}

void Controller::setDB(sqlite3 *db)
{
	this->db = db;
}

Alumno* Controller::getAlumno(string id) 
{
	for (int i = 0; i < (int)alumnos.size(); i++) 
		if (id == alumnos[i].getID())
			return &(alumnos[i]);

	return NULL;
}

Profesor* Controller::getProfesor(string id) {
	for (int i = 0; i < (int)profesores.size(); i++) {
		if (id == profesores[i].getNombre()) {
			return &profesores[i];
		}
	}
	return NULL;
}

Grado* Controller::getGrado(string id) {
	for (int i = 0; i < (int)grados.size(); i++) {
		if (id == grados[i].getNombre()) {
			return &grados[i];
		}
	}
	return NULL;
}

void Controller::addAlumno(Alumno alumno) {
	alumnos.push_back(alumno);
}

void Controller::addProfesor(Profesor profesor) {
	profesores.push_back(profesor);
}

void Controller::addGrado(Grado grado) {
	grados.push_back(grado);
}

void Controller::eliminarAlumno(string id)
{
	for (int i = 0; i < (int)alumnos.size(); i++) {
		if (id == alumnos[i].getID()) {
			alumnos.erase(alumnos.begin() + i);
		}
	}
}

void Controller::eliminarProfesor(string id) {
	for (int i = 0; i < (int)profesores.size(); i++) {
		if (id == profesores[i].getNombre()) {
			profesores.erase(profesores.begin() + i);
		}
	}
}

void Controller::eliminarGrado(string id) {
	for (int i = 0; i < (int)grados.size(); i++) {
		if (id == grados[i].getNombre()) {
			grados.erase(grados.begin() + i);
		}
	}
}

void Controller::enlazarTutor(Alumno *alumno, Profesor *profesor)
{
	alumno->getTFG()->setTutor(profesor);
}

void Controller::enlazarCoTutor(Alumno *alumno, Profesor *profesor)
{
	alumno->getTFG()->setCoTutor(profesor);
}

