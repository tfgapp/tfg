#include "Controller.h"
#include "Header.h"

Controller::Controller(sqlite3 *db)
{
	if(FIRST == 1) cargarBasedeDatos(db);
	this->db = db;
}

Controller::~Controller()
{
	sqlite3_close(db);
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

Grado* Controller::getGrado(string id) 
{
	for (int i = 0; i < (int)grados.size(); i++) {
		if (id == grados[i].getNombre()) {
			return &grados[i];
		}
	}
	return NULL;
}

int Controller::addAlumno(Alumno alumno, bool ins)
{
	alumnos.push_back(alumno);
	if (ins)
	{
		insertarAlumno(db, alumno);
		insertarTFG(db, alumno);
		insertarPresentacion(db, alumno);
		insertarTribunales(db, alumno);
	}
	return alumnos.size() - 1;
}

int Controller::addProfesor(Profesor profesor, bool ins)
{
	profesores.push_back(profesor);
	if (ins)
	{
		insertarProfesor(db, profesor);
		insertarEspecialidad(db, profesor);
	}
	return profesores.size() - 1;
}

int Controller::addGrado(Grado grado, bool ins)
{
	grados.push_back(grado);
	if (ins) insertarGrado(db, grado);
	return grados.size() - 1;
}

void Controller::addHorario(Horario horario, bool ins)
{
	if (horario.getDia() > this->diaMax) diaMax = horario.getDia();
	if (ins) insertarDisponibilidad(db, horario);
	horario.getProfesor()->addHorario(horario);
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

int Controller::getDiaMax()
{
	return this->diaMax;
}

void Controller::setDiaMax(int dia)
{
	this->diaMax = dia;
}