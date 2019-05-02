#include "Header.h"

static int SELECT callbackGrados(void *data, int argc, char **argv, char **azColName) {
	int i;
	Controller * main = (Controller *)data;
	for (i = 0; i < argc; i++)
	{
		main->getListaGrados()->push_back(Grado(argv[i]));
	}
	return 0;
}

void SELECT volcarGrados(Controller * main)
{
	char sql[] = "SELECT * FROM grados;";

	char * error = NULL;
	int resultado = sqlite3_exec(main->getDB(), sql, callbackGrados, main, &error);
	checkError(resultado, error);
}