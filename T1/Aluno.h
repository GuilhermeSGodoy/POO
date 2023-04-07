#ifndef ALUNO_H
#define ALUNO_H

#include "Pessoa.h"

namespace poo {

    class Aluno : public Pessoa {
    public:
        Aluno(string nome, int CPF, int RA, double P1, double P2,
              double T1, double T2, double T3);
        virtual ~Aluno();
        
        int getRA();
        void imprime();
        double media();
        bool aprovado();
        bool sac();
        double notaSAC();
    private:
        int RA;
        double P1;
        double P2;
        double T1;
        double T2;
        double T3;
    };

}

#endif /* ALUNO_H */

