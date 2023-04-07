#include "addlivro.h"
#include "ui_addlivro.h"
#include "livros.h"
#include "biblioteca.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

addLivro::addLivro(poo::Biblioteca *b, QWidget *parent) :
	QWidget(parent),
    ui(new Ui::addLivro),
    b(b)
{
	ui->setupUi(this);
    this->setWindowTitle(QString::fromStdString("Livros"));
}

addLivro::~addLivro()
{
	delete ui;
}

void addLivro::on_btn_addlivro_clicked()
{  
    string titulo;
	int ano;
	string genero;
	string autor;
	int quantidade;

	titulo = ui->campoTITULO->text().toStdString();
	ano = ui->campoANO->text().toInt();
	genero = ui->campoGENERO->text().toStdString();
	autor = ui->campoAUTOR->text().toStdString();
	quantidade = ui->campoQUANTIDADE->text().toInt();

    // Insere no vector
    poo::Livros *aux = new poo::Livros(titulo, ano, genero, autor);
	aux->aumentaQtde(quantidade - 1);
	b->incluiObra(aux, quantidade);

	ui->campoTITULO->setText(nullptr);
	ui->campoANO->setText(nullptr);
	ui->campoGENERO->setText(nullptr);
	ui->campoAUTOR->setText(nullptr);
	ui->campoQUANTIDADE->setText(nullptr);


    cout << "Adicionados " << quantidade << " novos Livros."  << endl
         << "Quantidade atual de Obras:" << b->nObras() << endl
         << "Quantidade atual de Livros:" << b->nObras(0) << endl
         << "Quantidade atual de Obras Distintas: " << b->nObrasDiferentes() << endl
         << "Quantidade atual de Livros Distintos: " << b->nObrasDiferentes(0) << endl;
}

void addLivro::on_btn_delLivro_clicked()
{
    string titulo;
	int ano;
	string genero;
	string autor;
	int quantidade;

	titulo = ui->campoTITULO->text().toStdString();
	ano = ui->campoANO->text().toInt();
	genero = ui->campoGENERO->text().toStdString();
    autor = ui->campoAUTOR->text().toStdString();
	quantidade = ui->campoQUANTIDADE->text().toInt();

	poo::Livros *aux = new poo::Livros(titulo, ano, genero, autor);
	b->removeObra(aux->getTitulo(), quantidade);

	ui->campoTITULO->setText(nullptr);
	ui->campoANO->setText(nullptr);
	ui->campoGENERO->setText(nullptr);
    ui->campoAUTOR->setText(nullptr);
	ui->campoQUANTIDADE->setText(nullptr);
}

void addLivro::on_commandLinkButton_clicked()
{
    this->setVisible(false);
}
