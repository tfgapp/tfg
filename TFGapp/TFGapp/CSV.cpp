#include "Header.h"

int CSV leerHeader(ifstream* file, string * header=NULL)
{
	if (header == NULL)
	{
		string dummy;

		getline((*file), dummy, '\n');

		int count = 0;
		for (auto iter : dummy)		if (iter == ',') count++;
		return count + 1;
	}
	else

	getline((*file), *header, '\n');

	int count = 0;
	for (auto iter : *header)		if (iter == ',') count++;
	return count + 1;
}

vector<Alumno> CSV importarAlumnos(char path[], vector<Grado> * grados)
{
	ifstream csv;
	csv.open(path);

	string grado;
	cout << "A que grado perteneces los alumnos del CSV?\n";
	cin >> grado;
	int i;
	for (i = 0; i < grados->size(); i ++)
		if ((*grados)[i].getNombre() == grado)
			break;
	Grado * dummy_G = &(*grados)[i];
	int nColumnas = leerHeader(&csv);
	vector<Alumno> lista;
	string * dummy = new string[nColumnas];

	while (csv.good())
	{
		for (int i = 0; i < nColumnas - 1; i++)	getline(csv, dummy[i], ',');

		getline(csv, dummy[nColumnas - 1], '\n');

		Alumno dummy_P(dummy[0], dummy[1], dummy[2], dummy_G);
		lista.push_back(dummy_P);
	}

	csv.close();
	delete[] dummy;
	return lista;
}

vector<Profesor> CSV importarProfesores(char path[], vector<Grado> * grados)
{
	ifstream csv;
	csv.open(path);
	string header;
	int nColumnas = leerHeader(&csv, &header);
	vector<Profesor> lista;
	string * dummy = new string[nColumnas];

	while (csv.good())
	{
		for (int i = 0; i < nColumnas - 1; i++)	getline(csv, dummy[i], ',');

		getline(csv, dummy[nColumnas - 1], '\n');

		Profesor * aux = existeProfesor(&lista, dummy[3]);
		if (aux == NULL)
		{
			Profesor dummy_P(dummy[0], dummy[1]);
			dummy_P.addGrado(&(*grados)[0]);
			lista.push_back(dummy_P);
		}
		else
			aux->addGrado(&(*grados)[0]);

	}

	csv.close();
	delete[] dummy;
	return lista;
}

vector<Horario> CSV importarHorarios(char path[], vector<Profesor> *listaProfesores)
{
	ifstream csv;
	csv.open(path);

	int nColumnas = leerHeader(&csv);
	vector<Horario> lista;
	string * dummy = new string[nColumnas];

	while (csv.good())
	{
		for (int i = 0; i < nColumnas - 1; i++)	getline(csv, dummy[i], ',');

		getline(csv, dummy[nColumnas - 1], '\n');

		if (existeHorario(&lista, dummy[0], dummy[1]) == NULL && existeProfesor(listaProfesores, dummy[0]) != NULL)
		{
			bool sloots[7];
			for (int i = 2, j = 0; j < 7; i++, j++) sloots[j] = stoi(dummy[i]);
			Horario dummy_H(stoi(dummy[1]), sloots);

			dummy_H.setProfesor(existeProfesor(listaProfesores, dummy[0]));

			lista.push_back(dummy_H);
		}

	}

	csv.close();
	delete[] dummy;
	return lista;
}
