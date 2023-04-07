#include "Pintura.h"

namespace catalogo {

    // Construtor
    Pintura::Pintura(string titulo, string artista, string material, int anoCriacao, string tipo) :
    ObraDeArte(titulo, artista, material, anoCriacao), tipo(tipo) {
    }

    // Destrutor
    Pintura::~Pintura() {
    }

    // Retorna o tipo da pintura
    string Pintura::getTipo() {
        return tipo;
    }

    // Atualiza o tipo da pintura
    void Pintura::setTipo(string tipo) {
        this->tipo = tipo;
    }

    // Retorna a categoria referente à classe Pintura
    int Pintura::getCategoria() {
        return 1;
    }

    // Impressão da ficha das pinturas
    void Pintura::imprimeFicha() {
        cout << "Categoria: Pintura" << endl;
        cout << "Titulo: " << getTitulo() << endl;
        cout << "Artista: " << getArtista() << endl;
        cout << "Material: " << getMaterial() << endl;
        cout << "Ano de Criação: " << getAnoCriacao() << endl;
        cout << "Tipo: " << getTipo() << endl;
    }

}
