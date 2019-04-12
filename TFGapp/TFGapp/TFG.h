#include <iostream>
#include <string>
using namespace std;

class TFG {

private:

	string titulo;
	bool presentado;
public:
	TFG(); //Constructor por defecto
	TFG(string, bool); //Constructor con parametros
	void setString(string);
	string getString();
	void setPresentado(bool);
	bool getPresentado();
};