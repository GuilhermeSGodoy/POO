#ifndef MUSEU_H
#define MUSEU_H

#include "ObraDeArte.h"
#include <algorithm>
#include <vector>
using namespace std;

namespace catalogo {

    class Museu
    {
        public:
            // Construtor e destrutor
            Museu(string nome);
            virtual ~Museu();

            // Getters e setters
            string getNome();
            void setNome(string nome);

            // Métodos da classe
            bool adicionaObra(ObraDeArte* obra);
            bool removeObra(string titulo);
            ObraDeArte* obtemObra(string titulo);
            int qtdeObras();
            int qtdePinturas();
            int qtdeEsculturas();
            void imprime();
            void imprimePorCategoria(int categoria);
        private:
            string nome;
            vector<ObraDeArte*> obras;
    };

}

#endif // MUSEU_H
