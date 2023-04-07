#ifndef OBRAS_H
#define OBRAS_H
#include <vector>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <string>

using namespace std;

namespace poo {

	class Obras {
	public:
		Obras(string titulo, int ano);
		virtual ~Obras();
		virtual int getTipo() = 0;
		virtual void imprimeFicha() = 0;
		virtual void aumentaQtde(int qnt);
		virtual void diminuiQtde(int qnt);
        virtual string getTitulo();
        virtual int getAno();
        virtual int getQuantidade();
		static bool compara(Obras* a, Obras* b);
	private:
		string titulo;
		int ano;
		int quantidade;
	};
}

#endif /* OBRAS_H */
