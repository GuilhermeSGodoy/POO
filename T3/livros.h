#ifndef LIVROS_H
#define LIVROS_H
#include "obras.h"

using namespace std;

namespace poo {

	class Livros : public Obras {
	public:
		Livros(string titulo, int ano, string genero, string autor);
		virtual int getTipo();
        virtual string getGenero();
		virtual string getAutor();
		virtual void imprimeFicha();
	private:
		string genero;
		string autor;
	};
}

#endif /* LIVROS_H */
