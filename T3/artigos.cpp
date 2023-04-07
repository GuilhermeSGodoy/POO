#include "artigos.h"

namespace poo {

    Artigos::Artigos(string titulo, int ano, string autor) :
    Obras(titulo, ano), autor(autor) {

	}

	Artigos::~Artigos() {
	}

	int Artigos::getTipo() {
		return 3;
	}

	string Artigos::getAutor() {
		return autor;
	}

	void Artigos::imprimeFicha() {
		cout << "Tipo: Artigos" << endl;
		cout << "Título: " << getTitulo() << endl;
		cout << "Autor: " << getAutor() << endl;
		cout << "Ano: " << getAno() << endl;
		cout << "Quantidade: " << getQuantidade() << endl;
	}
}
