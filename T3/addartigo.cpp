#include "addartigo.h"
#include "ui_addartigo.h"
#include "artigos.h"

addArtigo::addArtigo(poo::Biblioteca *b, QWidget *parent) :
	QWidget(parent),
    ui(new Ui::addArtigo),
    b(b)
{
	ui->setupUi(this);
    this->setWindowTitle(QString::fromStdString("Artigos"));
}

addArtigo::~addArtigo()
{
	delete ui;
}

void addArtigo::on_btn_addArtigo_clicked()
{
	string titulo;
	int ano;
	string autor;
	int quantidade;

	titulo = ui->campoTITULO->text().toStdString();
	ano = ui->campoANO->text().toInt();
	autor = ui->campoAUTOR->text().toStdString();
	quantidade = ui->campoQUANTIDADE->text().toInt();

	poo::Artigos *aux = new poo::Artigos(titulo, ano, autor);
	aux->aumentaQtde(quantidade - 1);
	b->incluiObra(aux, quantidade);

	ui->campoTITULO->setText(nullptr);
	ui->campoANO->setText(nullptr);
	ui->campoAUTOR->setText(nullptr);
	ui->campoQUANTIDADE->setText(nullptr);

    cout << "Adicionados " << quantidade << " novos Artigos."  << endl
         << "Quantidade atual de Obras:" << b->nObras() << endl
         << "Quantidade atual de Artigos:" << b->nObras(3) << endl
         << "Quantidade atual de Obras Distintas: " << b->nObrasDiferentes() << endl
         << "Quantidade atual de Artigos Distintos: " << b->nObrasDiferentes(3) << endl;
}

void addArtigo::on_btn_delArtigo_clicked()
{
	string titulo;
	int ano;
	string autor;
	int quantidade;

	titulo = ui->campoTITULO->text().toStdString();
	ano = ui->campoANO->text().toInt();
	autor = ui->campoAUTOR->text().toStdString();
	quantidade = ui->campoQUANTIDADE->text().toInt();

	poo::Artigos *aux = new poo::Artigos(titulo, ano, autor);
	b->removeObra(aux->getTitulo(), quantidade);

	ui->campoTITULO->setText(nullptr);
	ui->campoANO->setText(nullptr);
	ui->campoAUTOR->setText(nullptr);
	ui->campoQUANTIDADE->setText(nullptr);
}

void addArtigo::on_commandLinkButton_clicked()
{
    this->setVisible(false);
}
