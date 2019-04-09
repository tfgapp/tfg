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

static int BBDD callback(void *NotUsed, int argc, char **argv, char **azColName);
void BBDD checkError(int resultado, char * error);
void BBDD crearTablaAlumno(sqlite3 *bd);
void BBDD crearTablaProfesor(sqlite3 *bd);
void BBDD crearTablaHorario(sqlite3 *bd);
void BBDD insertarHorario(sqlite3 * bd, Horario horario);
void BBDD insertarAlumno(sqlite3 * bd, Alumno alumno);
void BBDD insertarProfesor(sqlite3 * bd, Profesor profesor);
void BBDD insertarAlumnos(vector<Alumno> lista, sqlite3 * db);
void BBDD insertarProfesores(vector<Profesor> lista, sqlite3 * db);
void BBDD insertarHorarios(vector<Horario> lista, sqlite3 * db);

#define CSV

int CSV leerHeader(ifstream* file, string* header);
vector<Alumno> CSV importarAlumnos(char path[], vector<Grado>* grados);
vector<Profesor> CSV importarProfesores(char path[], vector<Grado>* grados);
vector<Horario> CSV importarHorarios(char path[], vector<Profesor> *listaProfesores);

#define UTILITY

Profesor * UTILITY existeProfesor(vector<Profesor> *lista, string correo);
Horario * UTILITY existeHorario(vector<Horario> *lista, string nombre, string dia);
Grado* UTILITY existeGrado(vector<Grado> *grados, string ID);


