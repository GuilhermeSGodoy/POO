#include "livros.h"

namespace poo {

	Livros::Livros(string titulo, int ano,string genero, string autor) :
	Obras(titulo, ano), genero(genero), autor(autor) {
	}

	int Livros::getTipo() {
		return 0;
	}

	string Livros::getGenero() {
		return genero;
	}

	string Livros::getAutor() {
		return autor;
	}

	void Livros::imprimeFicha() {
		cout << "Tipo: Livros" << endl;
		cout << "Título: " << getTitulo() << endl;
		cout << "Autor: " << getAutor() << endl;
		cout << "Ano: " << getAno() << endl;
		cout << "Quantidade: " << getQuantidade() << endl;
		cout << "Gênero: " << getGenero() << endl;

	}
}
