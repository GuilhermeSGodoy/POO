#include "biblioteca.h"

namespace poo {

   Biblioteca::Biblioteca(string nome) : nome(nome) {
   }

   Biblioteca::~Biblioteca() {
	   for (int i = 0; i < obras.size(); i++) {
		   delete (obras[i]);      //Todas as obras foram alocadas dinamicamente com new Livros(), por exemplo
							   //Então precisamos desalocá-las ao fechar a biblioteca, pois já estão salvas no arquivo
	   }
   }

   string Biblioteca::getNome() {
	   return nome;
   }

   void Biblioteca::setNome(string nome) {
	   this->nome = nome;
   }

   void Biblioteca::atualizaQuantidadeNoArquivo(Obras *obra) {
	   char *aux = new char[50];
	   int n;
	   int tipo = obra->getTipo();

	   string titulo;
	   fstream fs;

	   switch (tipo) {
		   case 0: {
			   fs.open("livros.dat", fstream::in | fstream::out | fstream::binary);
			   if (fs.is_open()) {
				   do {
					   fs.read(reinterpret_cast<char*>(aux), sizeof(char) * 50);   //Lendo titulo
					   fs.read(reinterpret_cast<char*>(&n), sizeof(int));          //Lendo ano
					   titulo.assign(aux);                                         //Transformando titulo em string pra comparar
					   if (titulo != obra->getTitulo()) {
						   fs.read(reinterpret_cast<char*>(&n), sizeof(int));      //Lendo quantidade
						   fs.read(reinterpret_cast<char*>(aux), sizeof(char) * 50);   //Lendo genero
						   fs.read(reinterpret_cast<char*>(aux), sizeof(char) * 50);   //Lendo autor
					   }
				   } while (titulo != obra->getTitulo());
				   n = obra->getQuantidade();                             //Armazena quantidade
				   fs.write(reinterpret_cast<char*>(&n), sizeof(int)); //Salva quantidade
			   }
			   break;
		   }
		   case 1: {
			   fs.open("revistas.dat", fstream::in | fstream::out | fstream::binary);
			   if (fs.is_open()) {
				   do {
					   fs.read(reinterpret_cast<char*>(aux), sizeof(char) * 50);   //Lendo titulo
					   fs.read(reinterpret_cast<char*>(&n), sizeof(int));          //Lendo ano
					   titulo.assign(aux);                                         //Transformando titulo em string pra comparar
					   if (titulo != obra->getTitulo()) {
						   fs.read(reinterpret_cast<char*>(&n), sizeof(int));      //Lendo quantidade
						   fs.read(reinterpret_cast<char*>(aux), sizeof(char) * 50);   //Lendo editora
						   fs.read(reinterpret_cast<char*>(&n), sizeof(int));      //Lendo edicao
					   }
				   } while (titulo != obra->getTitulo());
				   n = obra->getQuantidade();                             //Armazena quantidade
				   fs.write(reinterpret_cast<char*>(&n), sizeof(int)); //Salva quantidade
			   }
			   break;
		   }
		   case 2: {
			   fs.open("jornais.dat", fstream::in | fstream::out | fstream::binary);
			   if (fs.is_open()) {
				   do {
					   fs.read(reinterpret_cast<char*>(aux), sizeof(char) * 50);   //Lendo titulo
					   fs.read(reinterpret_cast<char*>(&n), sizeof(int));          //Lendo ano
					   titulo.assign(aux);                                         //Transformando titulo em string pra comparar
					   if (titulo != obra->getTitulo()) {
						   fs.read(reinterpret_cast<char*>(&n), sizeof(int));      //Lendo quantidade
						   fs.read(reinterpret_cast<char*>(aux), sizeof(char) * 50);   //Lendo editora
						   fs.read(reinterpret_cast<char*>(&n), sizeof(int));      //Lendo dia
						   fs.read(reinterpret_cast<char*>(&n), sizeof(int));      //Lendo mes
					   }
				   } while (titulo != obra->getTitulo());
				   n = obra->getQuantidade();                             //Armazena quantidade
				   fs.write(reinterpret_cast<char*>(&n), sizeof(int)); //Salva quantidade
			   }
			   break;
		   }
		   case 3: {
			   fs.open("artigos.dat", fstream::in | fstream::out | fstream::binary);
			   if (fs.is_open()) {
				   do {
					   fs.read(reinterpret_cast<char*>(aux), sizeof(char) * 50);   //Lendo titulo
					   fs.read(reinterpret_cast<char*>(&n), sizeof(int));          //Lendo ano
					   titulo.assign(aux);                                         //Transformando titulo em string pra comparar
					   if (titulo != obra->getTitulo()) {
						   fs.read(reinterpret_cast<char*>(&n), sizeof(int));      //Lendo quantidade
						   fs.read(reinterpret_cast<char*>(aux), sizeof(char) * 50);   //Lendo autor
					   }
				   } while (titulo != obra->getTitulo());
				   n = obra->getQuantidade();                             //Armazena quantidade
				   fs.write(reinterpret_cast<char*>(&n), sizeof(int)); //Salva quantidade
			   }
			   break;
		   }
	   }
	   delete[] aux;
	   fs.close();
   }

   void Biblioteca::incluiObra(Obras* obra, int qnt) {
	   Obras* o = obtemObras(obra->getTitulo());   //Verifica se já existe a obra no acervo
	   char *aux = new char[50];                   //Cria um vetor de char de tamanho 50 que vou usar para salvar no arquivo
	   int n;                                      //Cria variável int para conseguir usar como ponteiro no arquivo
	   int tipo = obra->getTipo();                 //Cria variável int que armazena o tipo da obra passada

	   //Se não existe a obra no vector, salvo no vector E no arquivo
	   if (o == nullptr) {
		   obras.push_back(obra);  //Salvei no vector

		   ofstream ofs;

		   switch(tipo) {
			   case 0: {
				   ofs.open("livros.dat", ios::out | ios::binary | ios::app);     //Abro o arquivo para escrita no final
				   break;
			   }
			   case 1: {
				   ofs.open("revistas.dat", ios::out | ios::binary | ios::app);     //Abro o arquivo para escrita no final
				   break;
			   }
			   case 2: {
				   ofs.open("jornais.dat", ios::out | ios::binary | ios::app);     //Abro o arquivo para escrita no final
				   break;
			   }
			   case 3: {
				   ofs.open("artigos.dat", ios::out | ios::binary | ios::app);     //Abro o arquivo para escrita no final
				   break;
			   }
		   }


		   if (ofs.is_open()) {

			   //Salva titulo, ano e quantidade da obra no arquivo
			   strcpy(aux, obra->getTitulo().c_str());    //Copia a string Titulo para o aux[50]

			   ofs.write(reinterpret_cast<char*>(aux), sizeof(char) * 50); //Salva o Titulo no arquivo
			   n = obra->getAno();                //Passa o ano para uma variável pra conseguir usar como ponteiro no arquivo
			   ofs.write(reinterpret_cast<char*>(&n), sizeof(int));        //Salva o Ano no arquivo
			   n = obra->getQuantidade();         //Passa a Quantidade para uma variável pra conseguir usar como ponteiro no arquivo
			   ofs.write(reinterpret_cast<char*>(&n), sizeof(int));        //Salva a Quantidade no arquivo

			   switch (tipo) {
				   case 0: {
					   Livros* l = (Livros*)obra;     //Reinterpreta obra para sua classe original
					   strcpy(aux, l->getGenero().c_str());    //Copia a string Genero para o aux[50]
					   ofs.write(reinterpret_cast<char*>(aux), sizeof(char) * 50); //Salva o Genero no arquivo
					   strcpy(aux, l->getAutor().c_str());     //Copia a string Autor para o aux[50]
					   ofs.write(reinterpret_cast<char*>(aux), sizeof(char) * 50); //Salva o Autor no arquivo
					   break;
				   }
				   case 1: {
					   Revistas* r = (Revistas*)obra; //Reinterpreta obra para sua classe original
					   strcpy(aux, r->getEditora().c_str());   //Copia a string Editora para o aux[50]
					   ofs.write(reinterpret_cast<char*>(aux), sizeof(char) * 50); //Salva a Editora no arquivo
					   n = r->getEdicao();
					   ofs.write(reinterpret_cast<char*>(&n), sizeof(int));
					   break;
				   }
				   case 2: {
					   Jornais* j = (Jornais*)obra;
					   strcpy(aux, j->getEditora().c_str());
					   ofs.write(reinterpret_cast<char*>(aux), sizeof(char) * 50);
					   n = j->getDia();
					   ofs.write(reinterpret_cast<char*>(&n), sizeof(int));
					   n = j->getMes();
					   ofs.write(reinterpret_cast<char*>(&n), sizeof(int));
					   break;
				   }
				   case 3: {
					   Artigos* a = (Artigos*)obra;
					   strcpy(aux, a->getAutor().c_str());
					   ofs.write(reinterpret_cast<char*>(aux), sizeof(char) * 50);
					   break;
				   }
			   }
		   }
		   ofs.close();
	   }
	   //Se existe no vector, aumenta a quantidade na obra E no arquivo
	   else {
		   o->aumentaQtde(qnt);
		   this->atualizaQuantidadeNoArquivo(o);
	   }

	   delete[] aux;

   }

   bool Biblioteca::removeObra(string titulo, int qnt) {
       if (qnt <= 0)
		   return false;

	   Obras* o = obtemObras(titulo);

	   //Se nao existe obra com o titulo recebido
	   if (o == nullptr) {
		   return false;
	   }
	   //Se existe a obra e temos n obras tal que n >= qnt a ser removida
       else if (o->getQuantidade() > qnt) {
		   o->diminuiQtde(qnt);
		   this->atualizaQuantidadeNoArquivo(o);
	   }
	   else {           
		   for (int i = 0; i < obras.size(); i++) {
			   if (obras[i]->getTitulo() == titulo) {
				   delete(obras[i]);                   //FOI ALOCADO DINAMICAMENTE, ENTAO NAO PODEMOS ESQUECER
				   obras.erase(obras.begin() + i);     //DE DESALOCAR ANTES DE TIRAR DO VECTOR
			   }
		   }
	   }
	   return true;
   }

   Obras* Biblioteca::obtemObras(string titulo) {
	   Obras* o = nullptr;

	   for (int i = 0; i < obras.size(); i++)
		   if (obras[i]->getTitulo() == titulo)
			   o = obras[i];

	   return o;
   }

   int Biblioteca::nObras() {
	   int cont = 0;

	   for (int i = 0; i < obras.size(); i++)
		   cont += obras[i]->getQuantidade();

       return cont;
   }

   int Biblioteca::nObras(int tipo) {
	   int cont = 0;

	   for (int i = 0; i < obras.size(); i++)
		   if (obras[i]->getTipo() == tipo)
			   cont += obras[i]->getQuantidade();

	   return cont;
   }

   int Biblioteca::nObrasDiferentes() {
	   return obras.size();
   }

   int Biblioteca::nObrasDiferentes(int tipo) {
	   int cont = 0;

	   for (int i = 0; i < obras.size(); i++)
		   if (obras[i]->getTipo() == tipo)
			   cont++;

	   return  cont;
   }

   void Biblioteca::imprime() {
	   for (int i = 0; i < obras.size(); i++)
		   obras[i]->imprimeFicha();
   }

   void Biblioteca::imprimeOrdAlfabetica() {
	   vector<Obras*> copia = obras;

	   sort(copia.begin(), copia.end(), Obras::compara);

	   for (int i = 0; i < copia.size(); i++)
		   copia[i]->imprimeFicha();
   }

   void Biblioteca::ordenaPeloTipo() {
       vector<Obras*> copia[4];

        for (int i = 0; i < obras.size(); i++)
            copia[obras[i]->getTipo()].push_back(obras[i]);

        sort(copia[0].begin(), copia[0].end(), Obras::compara);
        sort(copia[1].begin(), copia[1].end(), Obras::compara);
        sort(copia[2].begin(), copia[2].end(), Obras::compara);
        sort(copia[3].begin(), copia[3].end(), Obras::compara);

        vector<Obras*> ordenado;

        for (int i = 0; i < 4; i ++)
            for (int j = 0; j < copia[i].size(); j++)
                ordenado.push_back(copia[i][j]);

        setVector(ordenado);
   }

   void Biblioteca::imprimeObra(string titulo) {
	   for (int i = 0; i < obras.size(); i++)
		   if (obras[i]->getTitulo() == titulo){
			   obras[i]->imprimeFicha();
			   return;
		   }
   }

   vector<Obras *> &Biblioteca::getVector() {
	   return obras;
   }

   void Biblioteca::setVector(vector<Obras *> & v) {
       obras.assign(v.begin(), v.end());
   }
}
