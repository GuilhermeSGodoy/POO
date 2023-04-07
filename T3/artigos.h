#ifndef ARTIGOS_H
#define ARTIGOS_H
#include "obras.h"

using namespace std;

namespace poo {

	class Artigos : public Obras {
	public:
        Artigos(string titulo, int ano, string autor);
		virtual ~Artigos();
		virtual int getTipo();
        virtual string getAutor();
		virtual void imprimeFicha();
	private:
        string autor;
	};
}

#endif /* ARTIGOS_H */
