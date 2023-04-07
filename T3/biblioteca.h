#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H
#include <vector>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <string>
#include <cstring>

#include "livros.h"
#include "revistas.h"
#include "jornais.h"
#include "artigos.h"

using namespace std;

// CONVENCIONADO: Livro = 0, Revista = 1, Jornal = 2, Artigo = 3

namespace poo {

	class Biblioteca {
	public:
		Biblioteca(string nome);
		virtual ~Biblioteca();
        virtual string getNome();
        virtual void setNome(string nome);
        virtual void atualizaQuantidadeNoArquivo(Obras* obra);
		virtual void incluiObra(Obras* obra, int qnt);
		virtual bool removeObra(string titulo, int qnt);
        virtual Obras* obtemObras(string titulo);
        virtual int nObras();
        virtual int nObras(int tipo);
        virtual int nObrasDiferentes();
        virtual int nObrasDiferentes(int tipo);
        virtual void imprime();
        virtual void imprimeOrdAlfabetica();
        virtual void ordenaPeloTipo();
        virtual void imprimeObra(string titulo);
		virtual vector<Obras *>& getVector();
        virtual void setVector(vector<Obras *> & v);
	private:
        string nome;
		vector<Obras*> obras;
	};
}
#endif /* BIBLIOTECA_H */
