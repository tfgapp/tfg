#include "Header.h"

bool prepareR(Controller * main, int convocatoria)
{
	//Seleccionar que alumnos van a ir en esta convocatoria
	int numAulas = 1;
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

	for (int i = 0; i < (numAulas * slots * dias) - 1; i++) //Utilizo la lista completa de manager para test
	{
		convocados.push_back(&(*main->getListaAlumnos())[i]);
	}
	if (backtracking(main, &convocados, convocatoria, 0, aulas, 1, 0))
	{
		for (int i = 0; i < convocados.size(); i++)
		{
			insertarPresentacion(main->getDB(), *convocados[i]);
			insertarTribunales(main->getDB(), *convocados[i]);
		}
		return true;
	}
	
	return false;
}

bool RECURSIVE backtracking(Controller * main, vector<Alumno *> *convocados, int convocatoria, int slot, int ** aulas, int dia, int pos)
{
	//FIN CORRECTO
	if (pos >= convocados->size()) return true; 
	//FIN INCORRECTO (Fin de dias)
	if (dia > main->getDiaMax()) return false;
	//Aulas acabadas en ese slot
	if (aulas[dia - 1][slot] == 0) return backtrackingManage(main, convocados, convocatoria, slot + 1, aulas, dia, pos); 
	//Variables de apoyo
	Alumno * alumno = (*convocados)[pos];
	Presentacion * presentacion = alumno->getTFG()->getPresentacion();
	Profesor * profesor = NULL;
	//Bucle que busca todas las parejas de profesores con al menos un doctro
	for (int i = 0; i < main->getListaProfesores()->size(); i++)
	{
		profesor = &(*main->getListaProfesores())[i];
		//Dos comprobantes para pasar al siguiente profesor en caso incorrecto
		if (!profesor->estaEspecializado(alumno->getGrado()) || !profesor->estaDisponible(dia, slot)) continue; //Comprobamos disponibilidad + grado
		if (!profesor->getDoctor()) continue; //Comprobamos si es doctor

		for (int j = 0; j < main->getListaProfesores()->size(); j++)
		{
			if (j == i) continue; //Para no coger dos veces el mismo profesor

			profesor = &(*main->getListaProfesores())[j];
			if (!profesor->estaEspecializado(alumno->getGrado()) || !profesor->estaDisponible(dia, slot)) continue;//Comprobamos disponibilidad + grado

			//Pareja Viable
			presentacion->setAll(dia, slot, convocatoria);
			aulas[dia - 1][slot]--;
			presentacion->addTribunal(&(*main->getListaProfesores())[i]);
			presentacion->addTribunal(profesor);
			//if (!(dia > main->getDiaMax())) cout << "Conv: " << convocatoria << " Slot: " << slot << " Aula: " << aulas[dia - 1][slot] << " Dia: " << dia << " Pos: " << pos << "\n";
			if (backtrackingManage(main, convocados, convocatoria, 0, aulas, 1, pos + 1))
			{
				return true;
			}
			else
			{
				aulas[dia - 1][slot]++;
				presentacion->reset();
				while(!presentacion->getTribunal()->empty())
				{
					presentacion->getTribunal()->back()->getHorario(dia)->setSloot(slot, true);
					presentacion->getTribunal()->pop_back();
				}
			}
		}
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