#include "Sessao.h"

namespace poo {

    Sessao::Sessao(string nomePeca, DataHorario& data) :
    nomePeca(nomePeca), data(&data) {

        memset(lugares, 0, 210 * sizeof(Pessoa*));
    }

    Sessao::~Sessao() {
    }

    string Sessao::proximoLivre() {

        int livre = -1;

        for (int i = 0; i < 210; i++) {
            if (lugares[i] == NULL) {
                livre = i;
                break;
            }
        }

        if (livre == -1) {
            return "Sessão cheia";
        }
        else
            return calculaPoltrona(livre);
    }

    bool Sessao::verifica(string lugar) {

        int indice = calculaIndice(lugar);

        if (lugares[indice] == NULL)
            return true;
        else
            return false;
    }


    bool Sessao::ocupa(string lugar, Pessoa& P) {

        int indice = calculaIndice(lugar);

        if (lugares[indice] == NULL) {
            lugares[indice] = &P;
            return true;
        }
        else
            return false;
    }

    bool Sessao::desocupa(string lugar) {

        int indice = calculaIndice(lugar);

        if (lugares[indice] != NULL) {
            lugares[indice] = 0;
            return true;
        }
        else
            return false;

    }

    int Sessao::vagas() {
        int contVagas = 0;

        for (int i = 0; i < 210; i++)
            if (lugares[i] == NULL)
                contVagas++;

        return contVagas;
    }

    void Sessao::imprime() {

        cout << "Nome da Peca: " << nomePeca << endl;
        data->imprime(false);
        cout << endl;
        for (int i = 0; i < 210; i++) {
            if (lugares[i] != NULL) {
                cout << "Nome: " << lugares[i]->getNome() << endl;
                cout << "Poltrona: " << calculaPoltrona(i) << endl << endl;;
            }
        }
    }
    
    /*
     * Nome: calculaIndice
     * Entrada: string no formato [A-O][1-14], que indica uma poltrona do teatro
     * Saída: valor do índice correspondente à poltrona, a ser utilizado como índice
     *        do vetor de lugares
     */
    int Sessao::calculaIndice(string lugar) {

        int fileira = lugar[0] - 'A';
        string numero = lugar.substr(1);
        int pos = stoi(numero);
        int indice = fileira * 14 + pos - 1;

        return indice;
    }

    /*
     * Nome: calculaPoltrona
     * Entrada: inteiro i correspondente ao índice do vetor de lugares
     * Saída: string com a respectiva poltrona do índice i no formato [A-O][1-14] 
     */
    string Sessao::calculaPoltrona(int i) {

        string letras[15] = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O"};
        string letraPoltrona = letras[i / 14];

        int aux = (i % 14) + 1;
        string numero = to_string(aux);

        string resultado = letraPoltrona + numero;

        return resultado;
    }

}
