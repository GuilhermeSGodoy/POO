#include "Museu.h"

namespace catalogo {

    // Construtor
    Museu::Museu(string nome) :
    nome(nome) {
    }

    // Destrutor
    Museu::~Museu() {
    }

    // Retorna o nome do museu
    string Museu::getNome() {
        return nome;
    }

    // Atualiza o nome do museu
    void Museu::setNome(string nome) {
        this->nome = nome;
    }

    // Adiciona uma obra ao catálogo
    bool Museu::adicionaObra(ObraDeArte* obra) {
        for (unsigned int i = 0; i < obras.size(); i++)
            if (obras[i]->getTitulo() == obra->getTitulo())
                return false;

        obras.push_back(obra);
        return true;
    }

    // Remove uma obra do catálogo referente ao título passado
    // como parâmetro
    bool Museu::removeObra(string titulo) {
        for (unsigned int i = 0; i < obras.size(); i++) {
            if (obras[i]->getTitulo() == titulo) {
                obras.erase(obras.begin() + i);
                return true;
            }
        }
        return false;
    }

    // Retorna a obra de arte referente ao título passado como
    // parâmetro
    ObraDeArte* Museu::obtemObra(string titulo) {
        ObraDeArte* aux = NULL;
        for (unsigned int i = 0; i < obras.size(); i++) {
            if (obras[i]->getTitulo() == titulo) {
                aux = obras[i];
                return aux;
            }
        }
        return aux;
    }

    // Retorna a quantidade de obras do catálogo
    int Museu::qtdeObras() {
        return obras.size();
    }

    // Retorna a quantidade de pinturas do catálogo
    int Museu::qtdePinturas() {
        int qtde = 0;
        for (unsigned int i = 0; i < obras.size(); i++) {
            if (obras[i]->getCategoria() == 1)
                qtde++;
        }
        return qtde;
    }

    // Retorna a quantidade de esculturas do catálogo
    int Museu::qtdeEsculturas() {
        int qtde = 0;
        for (unsigned int i = 0; i < obras.size(); i++) {
            if (obras[i]->getCategoria() == 2)
                qtde++;
        }
        return qtde;
    }

    // Imprime as fichas das obras do catálogo
    void Museu::imprime() {
        cout << "==================================" << endl;
        cout << "Nome: " << getNome() << endl;

        if (obras.size() > 0) {
            vector<ObraDeArte*> copia = obras;
            
            // Ordenação do vetor de obras com relação ao ano
            sort(copia.begin(), copia.end(), ObraDeArte::compAno);

            // Variáveis auxiliares para determinar o intervalo
            // que será ordenado com relação ao nome da obra
            int inicio = 0;
            int fim;

            for (unsigned int i = 0; i < copia.size() - 1; i++) {
                fim = i; // Atualiza o fim do intervalo
                
                // Verifica se o ano da próxima obra é diferente da
                // atual, e, caso seja, utiliza os limites do intervalo
                // definidos para ordenar aquele trecho do vetor com
                // relação ao nome da obra
                if (copia[i]->getAnoCriacao() != copia[i + 1]->getAnoCriacao()) {
                    sort(copia.begin() + inicio, copia.begin() + fim + 1, ObraDeArte::compTitulo);
                    inicio = fim + 1; // Atualiza o início do intervalo
                }
            }

            for (unsigned int i = 0; i < copia.size(); i++) {
                cout << "==================================" << endl;
                copia[i]->imprimeFicha();
            }
        }
        cout << "==================================" << endl;
    }

    // Imprime as fichas das obras de acordo com a categoria
    // desejada
    void Museu::imprimePorCategoria(int categoria) {
        cout << "\n==================================" << endl;
        cout << "Nome: " << getNome() << endl;

        if (obras.size() > 0) {
            vector<ObraDeArte*> copia = obras;
            
            // Ordenação do vetor de obras com relação ao ano
            sort(copia.begin(), copia.end(), ObraDeArte::compAno);

            // Variáveis auxiliares para determinar o intervalo
            // que será ordenado com relação ao nome da obra
            int inicio = 0;
            int fim;

            for (unsigned int i = 0; i < copia.size() - 1; i++) {
                fim = i; // Atualiza o fim do intervalo
                
                // Verifica se o ano da próxima obra é diferente da
                // atual, e, caso seja, utiliza os limites do intervalo
                // definidos para ordenar aquele trecho do vetor com
                // relação ao nome da obra
                if (copia[i]->getAnoCriacao() != copia[i + 1]->getAnoCriacao()) {
                    sort(copia.begin() + inicio, copia.begin() + fim + 1, ObraDeArte::compTitulo);
                    inicio = fim + 1; // Atualiza o início do intervalo
                }
            }

            for (unsigned int i = 0; i < copia.size(); i++) {
                if (copia[i]->getCategoria() == categoria) {
                    cout << "==================================" << endl;
                    copia[i]->imprimeFicha();
                }
            }
        }
        cout << "==================================" << endl << endl;
    }

}
