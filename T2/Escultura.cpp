#include "Escultura.h"

namespace catalogo {

    // Construtor
    Escultura::Escultura(string titulo, string artista, string material, int anoCriacao, double altura) :
    ObraDeArte(titulo, artista, material, anoCriacao), altura(altura) {
    }

    // Destrutor
    Escultura::~Escultura() {
    }

    // Retorna a altura da escultura
    double Escultura::getAltura() {
        return altura;
    }

    // Atualiza a altura da escultura
    void Escultura::setAltura(double altura) {
        this->altura = altura;
    }

    // Retorna a categoria referente à classe Escultura
    int Escultura::getCategoria() {
        return 2;
    }

    // Impressão da ficha das esculturas
    void Escultura::imprimeFicha() {
        cout << "Categoria: Escultura" << endl;
        cout << "Titulo: " << getTitulo() << endl;
        cout << "Artista: " << getArtista() << endl;
        cout << "Material: " << getMaterial() << endl;
        cout << "Ano de Criação: " << getAnoCriacao() << endl;
        cout << "Altura: " << getAltura() << endl;
    }

}
