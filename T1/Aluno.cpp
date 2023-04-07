#include "Aluno.h"

using namespace poo;

namespace poo {

    Aluno::Aluno(string nome, int CPF, int RA, double P1, double P2,
            double T1, double T2, double T3) :
    Pessoa(nome, CPF), RA(RA), P1(P1), P2(P2), T1(T1), T2(T2), T3(T3) {
    }

    Aluno::~Aluno() {
    }

    int Aluno::getRA() {
        return RA;
    }

    void Aluno::imprime() {
        Pessoa::imprime();
        cout << "Media: " << media() << endl;
    }

    double Aluno::media() {
        double MP = (P1 + P2) / 2;
        double MT = (T1 + 2 * T2 + 3 * T3) / 6;
        double MF = (MP * 8 + MT * 2) / 10;
        return MF;
    }

    bool Aluno::aprovado() {
        if (media() >= 6)
            return true;
        else
            return false;
    }

    bool Aluno::sac() {
        if (media() < 6 && media() >= 5)
            return true;
        else
            return false;
    }

    double Aluno::notaSAC() {
        double nota = 12 - media();
        if ((nota + media()) / 2 >= 6)
            return nota;
        else
            return 0;
    }

}
