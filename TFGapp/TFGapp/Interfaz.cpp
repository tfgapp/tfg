#include "Header.h"
using namespace std;

Alumno INTERFAZ crearAlumno(vector <Grado> *grados)
{
	Alumno dummy_A;
	string dummy_s;
	Grado * dummy_G = NULL;

	cout << "Dame el nombre del alumno: ";
	cin >> dummy_s;
	dummy_A.setNombre(dummy_s);
	
	cout << "Dame el apellido del alumno: ";
	cin >> dummy_s;
	dummy_A.setApellido(dummy_s);

	cout << "Dame la ID del alumno: ";
	cin >> dummy_s;
	dummy_A.setID(dummy_s);

	while (dummy_G == NULL) //Preguntamos a que grado pertenecen los alumnos del CSV de la lista existente
	{
		cout << "A que grado pertenece el Alumno?\n";
		for (auto dummy : (*grados)) cout << dummy.getNombre() << " ";
		cout << "\n";
		cin >> dummy_s;
		dummy_G = existeGrado(grados, dummy_s);
		if (dummy_G == NULL)
			cout << "No existe ese grado\n";
	}
	dummy_A.setGrado(dummy_G);

	return dummy_A;
}

void INTERFAZ borrarAlumno(Controller * main, string id)
{
	Alumno* dummy_A = existeAlumno(main->getListaAlumnos(), id);

	if (dummy_A == NULL)
		cout << "El alumno no existe\n";
	else
		main->eliminarAlumno(id);
}
void INTERFAZ borrarGrado(Controller *main, string id) {
	Grado* grado = existeGrado(main->getListaGrados(), id);

	if (grado == NULL)
		cout << "El grado no existe" << endl;
	else
		main->eliminarGrado(id);

}

void INTERFAZ borrarProfesor(Controller *main, string id) {
	Profesor* profesor = existeProfesor(main->getListaProfesores(), id);

	if (profesor == NULL)
		cout << "El profesor no existe" << endl;
	else
		main->eliminarProfesor(id);

}

int INTERFAZ menu() 
{
	int opcion;

	cout << "----------\n";
	cout << "0.Cerrar aplicacion.\n";
	cout << "1.Imprimir lista Grados.\n";
	cout << "2.Imprimir lista Alumnos.\n";
	cout << "3.Imprimir lista Profesores.\n";
	cout << "4.Crear Grado.\n";
	cout << "5.Crear Alumno.\n";
	cout << "6.Crear Profesor.\n";
	cout << "7.Borrar Grado.\n";
	cout << "8.Borrar Alumno.\n";
	cout << "9.Borrar Profesor.\n";
	cout << "----------\n";

	cin >> opcion;
	return opcion;
}



