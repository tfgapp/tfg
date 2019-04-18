#pragma once
#include "sqlite3/sqlite3.h"
#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include <list>
#include "Profesor.h"
#include "Alumno.h"
#include "Horario.h"
#include "Grado.h"

using namespace std;

#define BBDD

static int BBDD callback(void *NotUsed, int argc, char **argv, char **azColName); //Funcion para recoger el resultado de la operación SELECT
void BBDD checkError(int resultado, char * error); //Funcion para leer los errores de Sqlite3
sqlite3 * openBBDD(const char * path);

void BBDD crearTablaAlumno(sqlite3 *bd); //Crea la tabla alumno desde un preset
void BBDD crearTablaProfesor(sqlite3 *bd); //Crea la tabla profesor desde un preset
void BBDD crearTablaHorario(sqlite3 *bd); //Crea la tabla horario desde un preset

void BBDD insertarHorario(sqlite3 * bd, Horario horario); //Recibe una base de datos y un objeto Horario y lo inserta en la base de datos
void BBDD insertarAlumno(sqlite3 * bd, Alumno alumno); //Recibe una base de datos y un objeto Alumno y lo inserta en la base de datos
void BBDD insertarProfesor(sqlite3 * bd, Profesor profesor); //Recibe una base de datos y un objeto Profesor y lo inserta en la base de datos

void BBDD insertarAlumnos(vector<Alumno> lista, sqlite3 * db); //Funcion bucle para insertar una lista de Alumnos
void BBDD insertarProfesores(vector<Profesor> lista, sqlite3 * db); //Funcion bucle para insertar una lista de Alumnos
void BBDD insertarHorarios(vector<Horario> lista, sqlite3 * db); //Funcion bucle para insertar una lista de Alumnos

#define CSV

int CSV leerHeader(ifstream* file); //Recibe un puntero a un archivo CSV recien abierto y devuelve el numero de columnas

vector<Alumno> CSV importarAlumnos(char path[], vector<Grado>* grados); //Inserta en una lista todos los alumnos de un CSV
vector<Profesor> CSV importarProfesores(char path[], vector<Grado>* grados); //Inserta en una lista todos los profesores de un CSV
vector<Horario> CSV importarHorarios(char path[], vector<Profesor> *listaProfesores); //Inserta en una lista todos los horarios de un CSV

#define UTILITY

Profesor * UTILITY existeProfesor(vector<Profesor> *lista, string correo); //Funcion para comprobar si existe un profesor con su ID
Horario * UTILITY existeHorario(vector<Horario> *lista, string nombre, string dia); //Funcion para comprobar si existe un horario con su ID
Grado* UTILITY existeGrado(vector<Grado> *grados, string ID); //Funcion para comprobar si existe un Grado con su ID
