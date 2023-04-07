#ifndef PESSOA_H
#define PESSOA_H

#include <string>
#include <iostream>

using namespace std;

namespace poo {

    class Pessoa {
    public:
        Pessoa(string nome, int CPF);
        virtual ~Pessoa();
        
        string getNome();
        int getCPF();
        virtual void imprime();
    private:
        string nome;
        int CPF;
    };

}

#endif /* PESSOA_H */