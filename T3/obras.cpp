#include "obras.h"

namespace poo {

	Obras::Obras(string titulo, int ano) :
	titulo(titulo), ano(ano) {
		quantidade = 1;
	}

	Obras::~Obras() {
	}

	void Obras::aumentaQtde(int qnt) {
		this->quantidade += qnt;
	}

	void Obras::diminuiQtde(int qnt) {
		this->quantidade -= qnt;
	}

	string Obras::getTitulo() {
		return titulo;
	}

	int Obras::getAno() {
		return ano;
	}

	int Obras::getQuantidade() {
		return quantidade;
	}

	bool Obras::compara(Obras* a, Obras* b) {
		return a->getTitulo() < b->getTitulo();
	}
}
