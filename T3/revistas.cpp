#include "revistas.h"

namespace poo {

	Revistas::Revistas(string titulo, int ano, string editora, int edicao) :
	Periodicos(titulo, ano, editora), edicao(edicao) {

	}

	int Revistas::getTipo() {
		return 1;
	}

	int Revistas::getEdicao() {
		return edicao;
	}

	void Revistas::imprimeFicha() {
		Periodicos::imprimeFicha();
		cout << "Edição: " << getEdicao() << endl;
	}
}
