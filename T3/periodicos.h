#ifndef PERIODICOS_H
#define PERIODICOS_H
#include "obras.h"

using namespace std;

namespace poo {

	class Periodicos : public Obras {
	public:
		Periodicos(string titulo, int ano, string editora);
		virtual ~Periodicos();
        virtual int getTipo() = 0;              /*método abstrato que vai ser implementado pelos filhos*/
		virtual string getEditora();
		virtual void imprimeFicha();
	private:
		string editora;
	};
}

#endif /* PERIODICOS_H */
