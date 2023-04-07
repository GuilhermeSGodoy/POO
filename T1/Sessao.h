#ifndef SESSAO_H
#define SESSAO_H

#include <cstring>
#include <cstdlib>
#include "DataHorario.h"
#include "Pessoa.h"

namespace poo {

    class Sessao {
    public:
        Sessao(string nomePeca, DataHorario& data);
        virtual ~Sessao();

        string proximoLivre();
        bool verifica(string lugar);
        bool ocupa(string lugar, Pessoa& P);
        bool desocupa(string lugar);
        int vagas();
        void imprime();

        // Métodos auxiliares criados com o intuito de evitar a redundância
        // de código nos outros métodos.
        int calculaIndice(string lugar);
        string calculaPoltrona(int i);
    private:
        string nomePeca;
        DataHorario* data;
        Pessoa* lugares[210];
    };

}

#endif /* SESSAO_H */

