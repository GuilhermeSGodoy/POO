#ifndef PINTURA_H
#define PINTURA_H

#include "ObraDeArte.h"

namespace catalogo {

    class Pintura : public ObraDeArte
    {
        public:
            // Construtor e destrutor
            Pintura(string titulo, string artista, string material, int anoCriacao, string tipo);
            virtual ~Pintura();

            // Métodos abstratos implementados na subclasse
            void imprimeFicha();
            int getCategoria();

            // Métodos getters e setters
            string getTipo();
            void setTipo(string tipo);
        private:
            string tipo;
    };

}

#endif // PINTURA_H
