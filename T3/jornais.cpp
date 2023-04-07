#include "jornais.h"

namespace poo {

	Jornais::Jornais(string titulo, int ano, string editora, int dia, int mes) :
	Periodicos(titulo, ano, editora), dia(dia), mes(mes) {
	}

	Jornais::~Jornais() {
	}

	int Jornais::getTipo() {
		return 2;
	}

	int Jornais::getDia() {
		return dia;
	}

	int Jornais::getMes() {
		return mes;
	}

	void Jornais::imprimeFicha() {
		cout << "Tipo: Jornais" << endl;
		Periodicos::imprimeFicha();
		cout << "Dia: " << getDia() << endl;
		cout << "Mês: " << getMes() << endl;
	}
}
