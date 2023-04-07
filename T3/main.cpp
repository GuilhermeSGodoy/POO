#include "menuprincipal.h"
#include "biblioteca.h"
//#include "obras.h"
//#include "livros.h"
//#include "artigos.h"
//#include "revistas.h"
//#include "jornais.h"

//#include <fstream>
//#include <iostream>
#include <QApplication>


using namespace poo;

//static Biblioteca Bibi("Delano Library");

bool recuperaArquivo()
{
	ifstream ifs("biblioteca.dat", ios::binary);
	if (!ifs.is_open())
		return false;

	Biblioteca *B;
	ifs.read(reinterpret_cast<char *>(&B), sizeof(Biblioteca));

	if (B->nObras() == 0)
		return true;
	else
		return false;
}

int main(int argc, char *argv[])
{
	//if (recuperaArquivo())
		//cout << "teste";

	/*
	ofstream ofs("biblioteca.dat", ios::binary);

	Biblioteca B("delano library");

	Livros l1("calculo 1", 1974, "dor de cabeça", "guidorizzi");

	Revistas r1("revista", 2019, "abril", 10);

	B.incluiObra(&l1);
	B.incluiObra(&r1);

	cout << B.nObras() << endl;

	B.removeObra("calculo 1");

	cout << B.nObras() << endl;

	B.salvaNoArquivo();

	ofs.close();
	*/

	QApplication a(argc, argv);
	MenuPrincipal w;
    w.show();

	return a.exec();
}
