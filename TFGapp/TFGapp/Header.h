#pragma once
#include "sqlite3/sqlite3.h"
#include <fstream>
#include <string>
#include <iostream>
#include <list>
#include "Profesor.h"
#include "Alumno.h"
#include "Horario.h"

using namespace std;

#define BBDD

static int BBDD callback(void *NotUsed, int argc, char **argv, char **azColName);
void BBDD crearTablaAlumno(sqlite3 *bd);
void BBDD crearTablaProfesor(sqlite3 *bd);
void BBDD crearTablaHorario(sqlite3 *bd);
void BBDD insertarHorario(sqlite3 * bd, Horario horario);
void BBDD insertarAlumno(sqlite3 * bd, Alumno alumno);
void BBDD insertarProfesor(sqlite3 * bd, Profesor profesor);
void BBDD insertarAlumnos(list<Alumno> lista, sqlite3 * db);
void BBDD insertarProfesores(list<Profesor> lista, sqlite3 * db);
void BBDD insertarHorarios(list<Horario> lista, sqlite3 * db);

#define CSV

int CSV leerHeader(ifstream* file, string* header);
list<Alumno> CSV importarAlumnos(char path[]);
list<Profesor> CSV importarProfesores(char path[]);
list<Horario> CSV importarHorarios(char path[], list<Profesor> listaProfesores);

#define UTILITY

Profesor * UTILITY existeProfesor(list<Profesor> *lista, string correo);
Horario * UTILITY existeHorario(list<Horario> *lista, string nombre, string dia);

//soy ulises, el otro es un mentiroso