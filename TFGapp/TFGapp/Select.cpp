#include "Header.h"

static int BBDD callback(void *NotUsed, int argc, char **argv, char **azColName) {
	int i;
	for (i = 0; i < argc; i++) {
		printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
	}
	printf("\n");
	return 0;
}

void SELECT volcarGrados(Controller * main)
{
	char sql[] = "SELECT * FROM grados;";

	char * error = NULL;
	int resultado = sqlite3_exec(main->getDB(), sql, callback, main, &error);
	checkError(resultado, error);
}