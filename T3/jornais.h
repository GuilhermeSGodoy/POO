#ifndef JORNAIS_H
#define JORNAIS_H
#include "periodicos.h"

using namespace std;

namespace poo {

	class Jornais : public Periodicos {
	public:
		Jornais(string titulo, int ano, string editora, int dia, int mes);
		virtual ~Jornais();
		virtual int getTipo();
        virtual int getDia();
        virtual int getMes();
		virtual void imprimeFicha();
	private:
		int dia, mes;
	};
}

#endif /* JORNAIS_H */
