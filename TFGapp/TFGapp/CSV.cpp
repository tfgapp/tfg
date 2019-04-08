#include "Header.h"

int CSV leerHeader(ifstream* file, string * header = NULL)
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

list<Alumno> CSV importarAlumnos(char path[])
{
	ifstream csv;
	csv.open(path);

	int nColumnas = leerHeader(&csv);
	list<Alumno> lista;
	string * dummy = new string[nColumnas];

	while (csv.good())
	{
		for (int i = 0; i < nColumnas - 1; i++)	getline(csv, dummy[i], ',');

		getline(csv, dummy[nColumnas - 1], '\n');

		Alumno dummy_P(dummy[0], dummy[1], dummy[2], dummy[3], dummy[4]);
		lista.push_back(dummy_P);
	}

	csv.close();
	delete[] dummy;
	return lista;
}

list<Profesor> CSV importarProfesores(char path[])
{
	ifstream csv;
	csv.open(path);
	string header;
	int nColumnas = leerHeader(&csv, &header);
	list<Profesor> lista;
	string * dummy = new string[nColumnas];

	while (csv.good())
	{
		for (int i = 0; i < nColumnas - 1; i++)	getline(csv, dummy[i], ',');

		getline(csv, dummy[nColumnas - 1], '\n');

		Profesor * aux = existeProfesor(&lista, dummy[3]);
		if (aux == NULL)
		{
			Profesor dummy_P(dummy[0], dummy[1]);
			dummy_P.addGrado(dummy[4], dummy[6]);
			lista.push_back(dummy_P);
		}
		else
			aux->addGrado(dummy[4], dummy[6]);

	}

	csv.close();
	delete[] dummy;
	return lista;
}

list<Horario> CSV importarHorarios(char path[], list<Profesor> listaProfesores)
{
	ifstream csv;
	csv.open(path);

	int nColumnas = leerHeader(&csv);
	list<Horario> lista;
	string * dummy = new string[nColumnas];

	while (csv.good())
	{
		for (int i = 0; i < nColumnas - 1; i++)	getline(csv, dummy[i], ',');

		getline(csv, dummy[nColumnas - 1], '\n');

		if (existeHorario(&lista, dummy[0], dummy[1]) == NULL && existeProfesor(&listaProfesores, dummy[0]) != NULL)
		{
			bool sloots[7];
			for (int i = 2, j = 0; j < 7; i++, j++) sloots[j] = stoi(dummy[i]);
			Horario dummy_H(stoi(dummy[1]), sloots);

			dummy_H.setProfesor(existeProfesor(&listaProfesores, dummy[0]));

			lista.push_back(dummy_H);
		}

	}

	csv.close();
	delete[] dummy;
	return lista;
}
