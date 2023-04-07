#include "addrevista.h"
#include "ui_addrevista.h"
#include "revistas.h"
#include <fstream>
#include <string>
#include <iostream>

addRevista::addRevista(poo::Biblioteca *b, QWidget *parent) :
	QWidget(parent),
    ui(new Ui::addRevista),
    b(b)
{
	ui->setupUi(this);
    this->setWindowTitle(QString::fromStdString("Revistas"));
}

addRevista::~addRevista()
{
	delete ui;
}

void addRevista::on_btn_addrevista_clicked()
{
    string titulo;
    int ano;
    string editora;
    int edicao;
	int quantidade;

    titulo = ui->campoTITULO->text().toStdString();
    ano = ui->campoANO->text().toInt();
	editora = ui->campoEDITORA->text().toStdString();    //Precisamos atualizar conforme os campos que ainda vamos colocar
	edicao = ui->campoEDICAO->text().toInt();
	quantidade = ui->campoQUANTIDADE->text().toInt();

    // Insere no vector
    poo::Revistas *aux = new poo::Revistas(titulo, ano, editora, edicao);
	aux->aumentaQtde(quantidade - 1);
	b->incluiObra(aux, quantidade);

	ui->campoTITULO->setText(nullptr);
	ui->campoANO->setText(nullptr);
	ui->campoEDITORA->setText(nullptr);
	ui->campoEDICAO->setText(nullptr);
	ui->campoQUANTIDADE->setText(nullptr);

    cout << "Adicionadas " << quantidade << " novas Revistas."  << endl
         << "Quantidade atual de Obras:" << b->nObras() << endl
         << "Quantidade atual de Revistas:" << b->nObras(1) << endl
         << "Quantidade atual de Obras Distintas: " << b->nObrasDiferentes() << endl
         << "Quantidade atual de Revistas Distintas: " << b->nObrasDiferentes(1) << endl;
}

void addRevista::on_btn_delRevista_clicked()
{
	string titulo;
	int ano;
	string editora;
	int edicao;
	int quantidade;

	titulo = ui->campoTITULO->text().toStdString();
	ano = ui->campoANO->text().toInt();
	editora = ui->campoEDITORA->text().toStdString();    //Precisamos atualizar conforme os campos que ainda vamos colocar
	edicao = ui->campoEDICAO->text().toInt();
	quantidade = ui->campoQUANTIDADE->text().toInt();

	poo::Revistas *aux = new poo::Revistas(titulo, ano, editora, edicao);
	b->removeObra(aux->getTitulo(), quantidade);

	ui->campoTITULO->setText(nullptr);
	ui->campoANO->setText(nullptr);
	ui->campoEDITORA->setText(nullptr);
	ui->campoEDICAO->setText(nullptr);
	ui->campoQUANTIDADE->setText(nullptr);
}

void addRevista::on_commandLinkButton_clicked()
{
    this->setVisible(false);
}
