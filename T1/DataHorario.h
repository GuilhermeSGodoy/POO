#ifndef DATAHORARIO_H
#define DATAHORARIO_H

#include <iostream>

using namespace std;

namespace poo {

    class DataHorario {
    public:
        DataHorario(int dia = 1, int mes = 1, int ano = 1, int hora = 0, int minuto = 0, int segundo = 0);
        virtual ~DataHorario();
        
        int compara(DataHorario& data);
        int getDia();
        int getMes();
        int getAno();
        int getHora();
        int getMinuto();
        int getSegundo();
        void imprime(bool flag);
        void imprimePorExtenso();
    private:
        int dia;
        int mes;
        int ano;
        int hora;
        int minuto;
        int segundo;
    };

}

#endif /* DATAHORARIO_H */

