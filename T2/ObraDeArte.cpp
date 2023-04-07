#include "ObraDeArte.h"

namespace catalogo {

    // Construtor
    ObraDeArte::ObraDeArte(string titulo, string artista, string material, int anoCriacao) :
    titulo(titulo), artista(artista), material(material), anoCriacao(anoCriacao) {
    }

    // Destrutor
    ObraDeArte::~ObraDeArte() {
    }

    // Retorna o título da obra
    string ObraDeArte::getTitulo() {
        return titulo;
    }

    // Atualiza o título da obra
    void ObraDeArte::setTitulo(string titulo) {
        this->titulo = titulo;
    }

    // Retorna o nome do artista da obra
    string ObraDeArte::getArtista() {
        return artista;
    }

    // Atualiza o nome do artista da obra
    void ObraDeArte::setArtista(string artista) {
        this->artista = artista;
    }

    // Retorna o tipo do material da obra
    string ObraDeArte::getMaterial() {
        return material;
    }

    // Atualiza o tipo do material da obra
    void ObraDeArte::setMaterial(string material) {
        this->material = material;
    }

    // Retorna o ano de criação da obra
    int ObraDeArte::getAnoCriacao() {
        return anoCriacao;
    }

    // Atualiza o ano de criação da obra
    void ObraDeArte::setAnoCriacao(int anoCriacao) {
        this->anoCriacao = anoCriacao;
    }

    // Critério de comparação para o ano de criação da obra
    bool ObraDeArte::compAno(ObraDeArte* obra1, ObraDeArte* obra2) {
        return obra1->getAnoCriacao() < obra2->getAnoCriacao();
    }

    // Critério de comparação para o título da obra
    bool ObraDeArte::compTitulo(ObraDeArte* obra1, ObraDeArte* obra2) {
        return obra1->getTitulo() < obra2->getTitulo();
    }

}
