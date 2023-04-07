#include "periodicos.h"

namespace poo {

	Periodicos::Periodicos(string titulo, int ano, string editora) :
	Obras(titulo, ano), editora(editora) {
	}

	Periodicos::~Periodicos() {
	}

	string Periodicos::getEditora() {
		return editora;
	}

	void Periodicos::imprimeFicha() {
		cout << "Tipo: Periódicos" << endl;
		cout << "Título: " << getTitulo() << endl;
		cout << "Ano: " << getAno() << endl;
		cout << "Quantidade: " << getQuantidade() << endl;
		cout << "Editora: " << getEditora() << endl;
	}
}
