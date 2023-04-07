#include "menuprincipal.h"
#include "ui_menuprincipal.h"
#include "obras.h"

MenuPrincipal::MenuPrincipal(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MenuPrincipal)
{

    ui->setupUi(this);
    this->setWindowTitle(QString::fromStdString("Menu Principal"));

    ///////// cria ou recupera biblioteca ///////////////////////////////////////////////////

    ifstream ifs ("biblioteca.dat", ios::binary);
    poo::Biblioteca *b;

    //////// Se já tem um arquivo com a biblioteca, recupera ele em b ///////////////////////

    if (ifs.is_open())
        ifs.read(reinterpret_cast<char*>(b), sizeof(poo::Biblioteca));

    //////// Senão, cria uma nova biblioteca b de nome "Delano" /////////////////////////////

    else
        b = new poo::Biblioteca("Biblioteca Comunitaria");

    ifs.close();
    /////////////////////////////////////////////////////////////////////////////////////////

    this->b = b;

    /////// Inicializa variáveis usadas na leitura dos arquivos /////////////////////////////

    char *aux = new char[50];
    int dia, mes, ano, quantidade, edicao;
    string titulo, genero, autor, editora;
    char testaArquivoVazio = ':';
    vector<poo::Obras*> v;

    /////// Abre e lê arquivo de livros, cria Livro e joga no Vector de obras v /////////////

    ifs.open("livros.dat", ios::in | ios::binary);
    ifs.read(reinterpret_cast<char*>(&testaArquivoVazio), sizeof(char));
    if (testaArquivoVazio != ':') {
        ifs.seekg(0);
        ifs.read(reinterpret_cast<char*>(aux), sizeof(char) * 50);
        do {
            titulo.assign(aux);
            ifs.read(reinterpret_cast<char*>(&ano), sizeof(int));
            ifs.read(reinterpret_cast<char*>(&quantidade), sizeof(int));
            ifs.read(reinterpret_cast<char*>(aux), sizeof(char) * 50);
            genero.assign(aux);
            ifs.read(reinterpret_cast<char*>(aux), sizeof(char) * 50);
            autor.assign(aux);

            poo::Livros* l = new poo::Livros(titulo, ano, genero, autor);
            l->aumentaQtde(quantidade - 1);
            v.push_back(l);
            ifs.read(reinterpret_cast<char*>(aux), sizeof(char) * 50);
        } while (ifs.good());
    }

    ifs.close();

    /////// Abre e lê arquivo de revistas, cria Revista e joga no Vector de obras v /////////

    testaArquivoVazio = ':';
    ifs.open("revistas.dat", ios::in | ios::binary);
    ifs.read(reinterpret_cast<char*>(&testaArquivoVazio), sizeof(char));
    if (testaArquivoVazio != ':') {
        ifs.seekg(0);
        ifs.read(reinterpret_cast<char*>(aux), sizeof(char) * 50);
        do {
            titulo.assign(aux);
            ifs.read(reinterpret_cast<char*>(&ano), sizeof(int));
            ifs.read(reinterpret_cast<char*>(&quantidade), sizeof(int));
            ifs.read(reinterpret_cast<char*>(aux), sizeof(char) * 50);
            editora.assign(aux);
            ifs.read(reinterpret_cast<char*>(&edicao), sizeof(int));

            poo::Revistas* r = new poo::Revistas(titulo, ano, editora, edicao);
            r->aumentaQtde(quantidade - 1);
            v.push_back(r);
            ifs.read(reinterpret_cast<char*>(aux), sizeof(char) * 50);
        } while (ifs.good());
    }
    ifs.close();

    /////// Abre e lê arquivo de jornais, cria Jornal e joga no Vector de obras v ///////////

    testaArquivoVazio = ':';
    ifs.open("jornais.dat", ios::in | ios::binary);
    ifs.read(reinterpret_cast<char*>(&testaArquivoVazio), sizeof(char));
    if (testaArquivoVazio != ':') {
        ifs.seekg(0);
        ifs.read(reinterpret_cast<char*>(aux), sizeof(char) * 50);
        do {
            titulo.assign(aux);
            ifs.read(reinterpret_cast<char*>(&ano), sizeof(int));
            ifs.read(reinterpret_cast<char*>(&quantidade), sizeof(int));
            ifs.read(reinterpret_cast<char*>(aux), sizeof(char) * 50);
            editora.assign(aux);
            ifs.read(reinterpret_cast<char*>(&dia), sizeof(int));
            ifs.read(reinterpret_cast<char*>(&mes), sizeof(int));

            poo::Jornais* j = new poo::Jornais(titulo, ano, editora, dia, mes);
            j->aumentaQtde(quantidade - 1);
            v.push_back(j);
            ifs.read(reinterpret_cast<char*>(aux), sizeof(char) * 50);
        } while (ifs.good());
    }
    ifs.close();

    /////// Abre e lê arquivo de artigos, cria Artigo e joga no Vector de obras v ///////////

    testaArquivoVazio = ':';
    ifs.open("artigos.dat", ios::in | ios::binary);
    ifs.read(reinterpret_cast<char*>(&testaArquivoVazio), sizeof(char));
    if (testaArquivoVazio != ':') {
        ifs.seekg(0);
        ifs.read(reinterpret_cast<char*>(aux), sizeof(char) * 50);
        do {
            titulo.assign(aux);
            ifs.read(reinterpret_cast<char*>(&ano), sizeof(int));
            ifs.read(reinterpret_cast<char*>(&quantidade), sizeof(int));
            ifs.read(reinterpret_cast<char*>(aux), sizeof(char) * 50);
            autor.assign(aux);

            poo::Artigos* a = new poo::Artigos(titulo, ano, autor);
            a->aumentaQtde(quantidade - 1);
            v.push_back(a);
            ifs.read(reinterpret_cast<char*>(aux), sizeof(char) * 50);
        } while (ifs.good());
    }
    ifs.close();

    /////// Deleta vetor auxiliar e passa conteudo do Vector v para a biblioteca /////////////

    delete[] aux;
    b->setVector(v);

    //////////////////////////////////////////////////////////////////////////////////////////
    //////// Abre novas janelas

    acervoMenu = new acervo(b);

    add = new Adiciona(b);
}

MenuPrincipal::~MenuPrincipal()
{
    /////// Inicializa variáveis usadas na leitura dos arquivos /////////////////////////////

    char *aux = new char[50];
    int n;
    string strAuxiliar;
    vector<poo::Obras*> v = b->getVector();

    ofstream ofs_livro  ("livros.dat", ios::binary | ios::out | ios::trunc);
    ofstream ofs_revista("revistas.dat", ios::binary | ios::out | ios::trunc);
    ofstream ofs_jornal ("jornais.dat", ios::binary | ios::out | ios::trunc);
    ofstream ofs_artigo ("artigos.dat", ios::binary | ios::out | ios::trunc);

    for (int i = 0; i < v.size(); i++) {
        int tipo = v[i]->getTipo();
        switch (tipo) {
            case 0: {
                poo::Livros* l = (poo::Livros*)v[i];

                strcpy(aux, v[i]->getTitulo().c_str());
                ofs_livro.write(reinterpret_cast<char*>(aux), sizeof(char) * 50);   //Salva o Titulo no arquivo
                n = v[i]->getAno();                                                 //Passa o ano para uma variável pra conseguir usar como ponteiro no arquivo
                ofs_livro.write(reinterpret_cast<char*>(&n), sizeof(int));          //Salva o Ano no arquivo
                n = v[i]->getQuantidade();                                          //Passa a Quantidade para uma variável pra conseguir usar como ponteiro no arquivo
                ofs_livro.write(reinterpret_cast<char*>(&n), sizeof(int));          //Salva a Quantidade no arquivo


                strcpy(aux, l->getGenero().c_str());
                ofs_livro.write(reinterpret_cast<char*>(aux), sizeof(char) * 50);
                strcpy(aux, l->getAutor().c_str());
                ofs_livro.write(reinterpret_cast<char*>(aux), sizeof(char) * 50);
                break;

            }
            case 1: {
                poo::Revistas* r = (poo::Revistas*)v[i];

                strcpy(aux, v[i]->getTitulo().c_str());
                ofs_revista.write(reinterpret_cast<char*>(aux), sizeof(char) * 50);   //Salva o Titulo no arquivo
                n = v[i]->getAno();                                                 //Passa o ano para uma variável pra conseguir usar como ponteiro no arquivo
                ofs_revista.write(reinterpret_cast<char*>(&n), sizeof(int));          //Salva o Ano no arquivo
                n = v[i]->getQuantidade();                                          //Passa a Quantidade para uma variável pra conseguir usar como ponteiro no arquivo
                ofs_revista.write(reinterpret_cast<char*>(&n), sizeof(int));          //Salva a Quantidade no arquivo


                strcpy(aux, r->getEditora().c_str());
                ofs_revista.write(reinterpret_cast<char*>(aux), sizeof(char) * 50);
                n = r->getEdicao();
                ofs_revista.write(reinterpret_cast<char*>(&n), sizeof(int));
                break;
            }
            case 2: {
                poo::Jornais* j = (poo::Jornais*)v[i];

                strcpy(aux, v[i]->getTitulo().c_str());
                ofs_jornal.write(reinterpret_cast<char*>(aux), sizeof(char) * 50);   //Salva o Titulo no arquivo
                n = v[i]->getAno();                                                 //Passa o ano para uma variável pra conseguir usar como ponteiro no arquivo
                ofs_jornal.write(reinterpret_cast<char*>(&n), sizeof(int));          //Salva o Ano no arquivo
                n = v[i]->getQuantidade();                                          //Passa a Quantidade para uma variável pra conseguir usar como ponteiro no arquivo
                ofs_jornal.write(reinterpret_cast<char*>(&n), sizeof(int));          //Salva a Quantidade no arquivo


                strcpy(aux, j->getEditora().c_str());
                ofs_jornal.write(reinterpret_cast<char*>(aux), sizeof(char) * 50);
                n = j->getDia();
                ofs_jornal.write(reinterpret_cast<char*>(&n), sizeof(int));
                n = j->getMes();
                ofs_jornal.write(reinterpret_cast<char*>(&n), sizeof(int));
                break;
            }
            case 3: {
                poo::Artigos* a = (poo::Artigos*)v[i];

                strcpy(aux, v[i]->getTitulo().c_str());
                ofs_artigo.write(reinterpret_cast<char*>(aux), sizeof(char) * 50);   //Salva o Titulo no arquivo
                n = v[i]->getAno();                                                 //Passa o ano para uma variável pra conseguir usar como ponteiro no arquivo
                ofs_artigo.write(reinterpret_cast<char*>(&n), sizeof(int));          //Salva o Ano no arquivo
                n = v[i]->getQuantidade();                                          //Passa a Quantidade para uma variável pra conseguir usar como ponteiro no arquivo
                ofs_artigo.write(reinterpret_cast<char*>(&n), sizeof(int));          //Salva a Quantidade no arquivo

                strcpy(aux, a->getAutor().c_str());
                ofs_artigo.write(reinterpret_cast<char*>(aux), sizeof(char) * 50);
                break;
            }
        }
    }


    delete[] aux;

    ofs_livro.close();
    ofs_revista.close();
    ofs_jornal.close();
    ofs_artigo.close();

    delete ui;
}


void MenuPrincipal::on_btn_atualiza_clicked()
{
    add->clearFocus();

    add->show();
    add->setFocus();
}


void MenuPrincipal::on_btn_acervo_clicked()
{
    acervoMenu->clearFocus();

    acervoMenu->mostrarInformacoes();
    acervoMenu->show();
    acervoMenu->setFocus();
}
