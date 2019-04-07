#pragma once
#include "sqlite3/sqlite3.h"
#include <fstream>
#include <string>
#include <iostream>
#include <list>
#include "Profesor.h"
#include "Alumno.h"

using namespace std;

#define BBDD

static int BBDD callback(void *NotUsed, int argc, char **argv, char **azColName);
void BBDD crearTablaAlumno(sqlite3 *bd);
void BBDD crearTablaProfesor(sqlite3 *bd);
void BBDD insertarAlumno(sqlite3 * bd, Alumno alumno);
void BBDD insertarProfesor(sqlite3 * bd, Profesor profesor);
void BBDD insertarAlumnos(list<Alumno> lista, sqlite3 * db);
void BBDD insertarProfesores(list<Profesor> lista, sqlite3 * db);

#define CSV

int CSV leerHeader(ifstream* file);
list<Alumno> CSV importarAlumnos(char path[]);
list<Profesor> CSV importarProfesores(char path[]);

#define UTILITY

Profesor * UTILITY existeProfesor(list<Profesor> *lista, string correo);

