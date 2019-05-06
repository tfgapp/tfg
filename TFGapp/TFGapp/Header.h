#pragma once

#define FIRST 0

#include "sqlite3/sqlite3.h"
#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include "Controller.h"

#define BBDD 

void BBDD checkError(int resultado, char * error); //Funcion para leer los errores de Sqlite3
sqlite3 * openBBDD(const char * path);
void BBDD emptyDB(sqlite3 * db);

void BBDD crearTablaAlumnos(sqlite3 *bd); //Crea la tabla alumno desde un preset
void BBDD crearTablaProfesores(sqlite3 *bd); //Crea la tabla profesor desde un preset
void BBDD crearTablaDisponibilidad(sqlite3 *bd); //Crea la tabla horario desde un preset
void BBDD crearTablaTFG(sqlite3 *bd); //Crea la tabla TFG desde un preset
void BBDD crearTablaPresentaciones(sqlite3 *bd); //Crea la tabla Presentacion desde un preset
void BBDD crearTablaGrados(sqlite3 *bd);//Crea la tabla Grado desde un preset
void BBDD crearTablaEspecialidades(sqlite3 *bd); //Crea la tabla Especialidades desde un preset
void BBDD crearTablaTribunales(sqlite3 *bd); //Crea la tabla Especialidades desde un preset
void BBDD cargarBasedeDatos(sqlite3 *bd); //Crea todas las tablas de la base de datos

void BBDD insertarDisponibilidad(sqlite3 * bd, Horario horario);
void BBDD insertarAlumno(sqlite3 * bd, Alumno alumno);
void BBDD insertarProfesor(sqlite3 * bd, Profesor profesor);
void BBDD insertarGrado(sqlite3 * bd, Grado grado);
void BBDD insertarEspecialidad(sqlite3 * bd, Profesor profesor);
void BBDD insertarTFG(sqlite3 * bd, Alumno alumno);
void BBDD insertarPresentacion(sqlite3 * bd, Alumno alumno);
void BBDD insertarTribunales(sqlite3 * bd, Alumno alumno);

void BBDD borrarDisponibilidad(sqlite3 * bd, Horario horario);
void BBDD borrarAlumno(sqlite3 * bd, Alumno alumno);
void BBDD borrarProfesor(sqlite3 * bd, Profesor profesor);
void BBDD borrarGrado(sqlite3 * bd, string id);
void BBDD borrarEspecialidad(sqlite3 * bd, Profesor profesor);
void BBDD borrarTFG(sqlite3 * bd, Alumno alumno);
void BBDD borrarPresentacion(sqlite3 * bd, Alumno alumno);
void BBDD borrarTribunales(sqlite3 * bd, Alumno alumno);


#define CSV

int CSV leerHeader(ifstream* file); //Recibe un puntero a un archivo CSV recien abierto y devuelve el numero de columnas
void CSV importarAlumnos(char path[], Controller * main, Grado * grado); //Inserta en una lista todos los alumnos de un CSV
void CSV importarProfesores(char path[], Controller * main); //Inserta en una lista todos los profesores de un CSV
void CSV importarHorarios(char path[], Controller * main); //Inserta en una lista todos los horarios de un CSV

#define UTILITY

#define INTERFAZ

Alumno INTERFAZ crearAlumno(Controller * main);
Grado INTERFAZ crearGrado();
Profesor INTERFAZ crearProfesor(Controller * main);

void INTERFAZ borrarAlumno(Controller * main, string id);
void INTERFAZ borrarGrado(Controller * main, string id);
void INTERFAZ borrarProfesor(Controller * main, string id);
int INTERFAZ menu();

#define SELECT

static int SELECT callbackGrados(void *data, int argc, char **argv, char **azColName); //Funcion para recoger el resultado de la operación SELECT
void SELECT volcarGrados(Controller * main);

static int SELECT callbackProfesores(void *data, int argc, char **argv, char **azColName); //Funcion para recoger el resultado de la operación SELECT
static int SELECT callbackDisponibilidad(void *data, int argc, char **argv, char **azColName); //Funcion para recoger el resultado de la operación SELECT
static int SELECT callbackEspecialidad(void *data, int argc, char **argv, char **azColName); //Funcion para recoger el resultado de la operación SELECT
static int SELECT callbackEspecialidad(void *data, int argc, char **argv, char **azColName); //Funcion para recoger el resultado de la operación SELECT
void SELECT volcarProfesores(Controller * main);
void SELECT volcarAlumnos(Controller * main);

#define RECURSIVE

bool RECURSIVE prepareR(Controller * main, int convocatoria, vector<Alumno *> *convocados, int ** aulas);
bool RECURSIVE backtracking(Controller * main, vector<Alumno *> *convocados, int convocatoria, int slot, int ** aulas, int dia, int pos);
bool RECURSIVE backtrackingManage(Controller * main, vector<Alumno *> *convocados, int convocatoria, int slot, int ** aulas, int dia, int pos);