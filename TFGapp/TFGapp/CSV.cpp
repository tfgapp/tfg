#include "Header.h"

int CSV leerHeader(ifstream* file)
{
	string dummy; //Almacenar Header

	getline((*file), dummy, '\n'); //Leo la primera linea(HEADER)

	int count = 1;
	for (auto iter : dummy)		if (iter == ',') count++; //Cuento el numero de comas para hallar el numero de campos
	return count;

}

void CSV importarAlumnos(char path[], Controller * main) //Inserta en una lista todos los alumnos de un CSV
{
	ifstream csv;
	csv.open(path);

	string grado;
	Grado * dummy_G = NULL;

	//Listas del controller
	vector<Grado> * grados = main->getListaGrados();
	vector<Alumno> * alumnos = main->getListaAlumnos();

	while (dummy_G == NULL) //Preguntamos a que grado pertenecen los alumnos del CSV de la lista existente
	{
		cout << "A que grado pertenecen los alumnos del CSV?\n";
		for (auto dummy : (*grados)) cout << dummy.getNombre() << " ";
		cout << "\n";
		cin >> grado;
		dummy_G = main->getGrado(grado);
		if (dummy_G == NULL)
			cout << "No existe ese grado\n";
	}

	int nColumnas = leerHeader(&csv);

	string * dummy = new string[nColumnas];

	while (csv.good()) //Por cada linea creo un alumnos y los guardo en la lista
	{
		for (int i = 0; i < nColumnas - 1; i++)	getline(csv, dummy[i], ',');

		getline(csv, dummy[nColumnas - 1], '\n');

		Alumno dummy_P(dummy[0], dummy[1], dummy[2], dummy_G);
		main->addAlumno(dummy_P);
	}

	csv.close();
	delete[] dummy;
}

void CSV importarProfesores(char path[], Controller * main) //Inserta en una lista todos los profesores de un CSV
{
	ifstream csv; //Variable para manejar el CSV
	csv.open(path); //Abro el CSV por primera vez
	string header; // Variable para leer el header

	//Listas del controller
	vector<Grado> * grados = main->getListaGrados();
	vector<Profesor> * profesores = main->getListaProfesores();

	getline(csv, header, '\n'); //Leo la primera liena del CSV que es el Header
	int nColumnas = 1;
	for (auto iter : header) { if (iter == ',') nColumnas++; } //Cuento el numero de columnas
	csv.close();

	csv.open(path); //Lo abro de nuevo para volver al principio y extraer los nombre de grados
	string * dummy = new string[nColumnas];
	vector<string> nombresGrado;
	for (int i = 0; i < nColumnas - 1; i++)	getline(csv, dummy[i], ','); //Guardo cada nombre del header por separado
	getline(csv, dummy[nColumnas - 1], '\n');

	for (int i = 2; i < nColumnas; i++)
	{
		Grado* dummy_G = main->getGrado(dummy[i]);
		if (main->getGrado(dummy[i]) == NULL)
			grados->push_back(Grado(dummy[i]));
		nombresGrado.push_back(dummy[i]);
	}

	while (csv.good())
	{
		for (int i = 0; i < nColumnas - 1; i++)	getline(csv, dummy[i], ',');

		getline(csv, dummy[nColumnas - 1], '\n');

		Profesor * aux = main->getProfesor(dummy[0]);
		if (aux == NULL)
		{
			Profesor dummy_P(dummy[0], dummy[1]);
			for (int i = 2; i < nColumnas; i++) dummy_P.addGrado(main->getGrado(nombresGrado[i - 2]), stoi(dummy[i]));
			profesores->push_back(dummy_P);
		}
		//else
			//cout << "El profesor con ID: " << aux->getNombre() << " ya existe. IMPLEMENTAR SOLUCIÓN\n";

	}

	csv.close();
	delete[] dummy;
}

void CSV importarHorarios(char path[], Controller * main) //Inserta en una lista todos los horarios de un CSV
{
	ifstream csv;
	csv.open(path);

	//Listas del controller
	vector<Grado> * grados = main->getListaGrados();
	vector<Profesor> * profesores = main->getListaProfesores();

	int nColumnas = leerHeader(&csv);
	vector<Horario> lista;
	string * dummy = new string[nColumnas];

	while (csv.good())
	{
		for (int i = 0; i < nColumnas - 1; i++)	getline(csv, dummy[i], ',');

		getline(csv, dummy[nColumnas - 1], '\n');

		if (existeHorario(&lista, dummy[0], dummy[1]) == NULL && main->getGrado(dummy[0]) != NULL)
		{
			bool sloots[7];
			for (int i = 2, j = 0; j < 7; i++, j++) sloots[j] = stoi(dummy[i]);
			Horario dummy_H(stoi(dummy[1]), sloots);

			dummy_H.setProfesor(main->getProfesor(dummy[0]));

			lista.push_back(dummy_H);
		}

	}

	csv.close();
	delete[] dummy;
}
