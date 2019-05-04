#include "Header.h"

void prepareR(Controller * main, int convocatoria)
{
	//Controller copia_C = (*main);
	//Seleccionar que alumnos van a ir en esta convocatoria
	int numAulas = 3;
	int slots = 7;
	int dias = main->getDiaMax();
	int **aulas;
	aulas = new int*[dias];
	for (int i = 0; i < dias; i++) {
		aulas[i] = new int[slots];
		for (int j = 0; j < slots; j++) {
			aulas[i][j] = numAulas;
		}
	}
	vector<Alumno *> convocados;

	for (int i = 0; i < 31; i++) //Utilizo la lista completa de manager para test
	{
		convocados.push_back(&(*main->getListaAlumnos())[i]);
		convocados.push_back(&(*main->getListaAlumnos())[i + 100]);
		convocados.push_back(&(*main->getListaAlumnos())[i + 200]);
		convocados.push_back(&(*main->getListaAlumnos())[i + 300]);
	}
	bool a = backtracking(main, &convocados, convocatoria, 0, aulas, 1, 0); //COPIA CONTROLLER MIRAR

	for (int i = 0; i < dias; i++)
	{
		for (int j = 0; j < slots; j++)
		{
			cout << aulas[i][j] << " ";
		}
		cout << "\n";
	}
}

bool RECURSIVE backtracking(Controller * main, vector<Alumno *> *convocados, int convocatoria, int slot, int ** aulas, int dia, int pos)
{
	if (!(dia > main->getDiaMax())) cout << "Conv: " << convocatoria << " Slot: " << slot << " Aula: " << aulas[dia - 1][slot] << " Dia: " << dia << " Pos: " << pos << "\n";
	if (pos >= convocados->size()) return true;
	if (dia > main->getDiaMax())
	{
		return false;
	}
	if (aulas[dia - 1][slot] == 0) { 
		return backtrackingManage(main, convocados, convocatoria, slot + 1, aulas, dia, pos); 
	}
	Alumno * alumno = (*convocados)[pos];
	Presentacion * presentacion = alumno->getTFG()->getPresentacion();
	if (presentacion->getConvocatoria() != -1)
	{
		return backtracking(main, convocados, convocatoria, slot, aulas, dia, pos + 1);
	}
	
	bool doctor = false; int doctorN = -1;
	bool extra = false; int extraN = -1;
	
	
	for (int i = 0; i < main->getListaProfesores()->size(); i++)
	{
		Profesor * profesor = &(*main->getListaProfesores())[i];

		if (!profesor->estaEspecializado(alumno->getGrado()) || !profesor->estaDisponible(dia, slot)) continue;

		if (profesor->getDoctor() && !doctor)
		{
			presentacion->addTribunal(profesor);
			profesor->getHorario(dia)->setSloot(slot, false);
			doctor = true; doctorN = i;

		}
		else if(!extra)
		{
			extra = true; extraN = i;
			presentacion->addTribunal(profesor);
			profesor->getHorario(dia)->setSloot(slot, false);
		}

		if (doctor && extra)
		{
			presentacion->setAll(dia, slot, convocatoria);
			aulas[dia - 1][slot]--;
			if (backtrackingManage(main, convocados, convocatoria, 0, aulas, 1, pos + 1))
			{
				return true;
			}
			else 
			{
				aulas[dia - 1][slot]++;
				presentacion->reset();
				extra = false;
				(*main->getListaProfesores())[extraN].getHorario(dia)->setSloot(slot, true);
				presentacion->delTribunal((*main->getListaProfesores())[extraN].getNombre());
			}
		}
		if (i == main->getListaProfesores()->size() - 1 && doctor)
		{
			doctor = false;
			for (int j = 0; j < presentacion->getTribunal()->size(); j++)
			{
				presentacion->getTribunal()->back()->getHorario(dia)->setSloot(slot, true);
				presentacion->getTribunal()->pop_back();
			}
			i = doctorN;
		}
	}
	for (int j = 0; j < presentacion->getTribunal()->size(); j++)
	{
		presentacion->getTribunal()->back()->getHorario(dia)->setSloot(slot, true);
		presentacion->getTribunal()->pop_back();
	}
	if (backtrackingManage(main, convocados, convocatoria, slot + 1, aulas, dia, pos)) return true;
	return false;
}

bool RECURSIVE backtrackingManage(Controller * main, vector<Alumno *> *convocados, int convocatoria, int slot, int ** aulas, int dia, int pos)
{
	if (slot > 6)
	{
		dia++;
		slot = 0;
	}
	
	return backtracking(main, convocados, convocatoria, slot, aulas, dia, pos);
}