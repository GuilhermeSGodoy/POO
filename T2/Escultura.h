#ifndef ESCULTURA_H
#define ESCULTURA_H

#include "ObraDeArte.h"

namespace catalogo {

    class Escultura : public ObraDeArte
    {
        public:
            // Construtor e destrutor
            Escultura(string titulo, string artista, string material, int anoCriacao, double altura);
            virtual ~Escultura();

            // Métodos abstratos implementados na subclasse
            void imprimeFicha();
            int getCategoria();

            // Métodos getters e setters
            double getAltura();
            void setAltura(double altura);
        private:
            double altura;
    };

}

#endif // ESCULTURA_H
