#ifndef OBRADEARTE_H
#define OBRADEARTE_H

#include <string>
#include <iostream>

using namespace std;

namespace catalogo {

    class ObraDeArte
    {
        public:
            // Construtor e destrutor
            ObraDeArte(string titulo, string artista, string material, int anoCriacao);
            virtual ~ObraDeArte();

            // Métodos abstratos
            virtual int getCategoria() = 0;
            virtual void imprimeFicha() = 0;

            // Métodos getters e setters
            string getTitulo();
            void setTitulo(string titulo);
            string getArtista();
            void setArtista(string artista);
            string getMaterial();
            void setMaterial(string material);
            int getAnoCriacao();
            void setAnoCriacao(int anoCriacao);

            // Métodos auxiliares que serão usados como critérios
            // para a ordenação do vetor de obras de arte
            static bool compAno(ObraDeArte* obra1, ObraDeArte* obra2);
            static bool compTitulo(ObraDeArte* obra1, ObraDeArte* obra2);
        private:
            string titulo;
            string artista;
            string material;
            int anoCriacao;
    };

}

#endif // OBRADEARTE_H
