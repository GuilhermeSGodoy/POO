#include "Pessoa.h"

namespace poo {

    Pessoa::Pessoa(string nome, int CPF) :
    nome(nome), CPF(CPF) {
    }

    Pessoa::~Pessoa() {
    }

    string Pessoa::getNome() {
        return nome;
    }

    int Pessoa::getCPF() {
        return CPF;
    }

    void Pessoa::imprime() {
        cout << "Nome: " << getNome() << endl;
        cout << "CPF: " << getCPF() << endl;
    }

}
