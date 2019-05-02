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



void BBDD insertarHorario(sqlite3 * bd, Horario horario); //Recibe una base de datos y un objeto Horario y lo inserta en la base de datos
void BBDD insertarAlumno(sqlite3 * bd, Alumno alumno); //Recibe una base de datos y un objeto Alumno y lo inserta en la base de datos
void BBDD insertarProfesor(sqlite3 * bd, Profesor profesor); //Recibe una base de datos y un objeto Profesor y lo inserta en la base de datos
void BBDD insertarGrado(sqlite3 * bd, Grado grado);

void BBDD insertarAlumnos(vector<Alumno> lista, sqlite3 * db); //Funcion bucle para insertar una lista de Alumnos
void BBDD insertarProfesores(vector<Profesor> lista, sqlite3 * db); //Funcion bucle para insertar una lista de Alumnos
void BBDD insertarHorarios(vector<Horario> lista, sqlite3 * db); //Funcion bucle para insertar una lista de Alumnos

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