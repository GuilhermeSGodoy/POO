#ifndef REVISTAS_H
#define REVISTAS_H
#include "periodicos.h"

using namespace std;

namespace poo {

	class Revistas : public Periodicos {
	public:
		Revistas(string titulo, int ano, string editora, int edicao);
		virtual int getTipo();
        virtual int getEdicao();
		virtual void imprimeFicha();
	private:
		int edicao;
	};
}
#endif /* REVISTAS_H */
