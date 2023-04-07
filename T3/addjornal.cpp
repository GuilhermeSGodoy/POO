#include "addjornal.h"
#include "ui_addjornal.h"
#include "jornais.h"

addJornal::addJornal(poo::Biblioteca *b, QWidget *parent) :
	QWidget(parent),
    ui(new Ui::addJornal),
    b(b)
{
	ui->setupUi(this);
    this->setWindowTitle(QString::fromStdString("Jornais"));
}

addJornal::~addJornal()
{
	delete ui;
}

void addJornal::on_btn_addjornal_clicked()
{
	string titulo;
	int dia;
	int mes;
	int ano;
	string editora;
	int quantidade;

	titulo = ui->campoTITULO->text().toStdString();
	dia = ui->campoDIA->text().toInt();
	mes = ui->campoMES->text().toInt();
	ano = ui->campoANO->text().toInt();
	editora = ui->campoEDITORA->text().toStdString();
	quantidade = ui->campoQUANTIDADE->text().toInt();

	poo::Jornais *aux = new poo::Jornais(titulo, ano, editora, dia, mes);
	aux->aumentaQtde(quantidade - 1);
	b->incluiObra(aux, quantidade);

	ui->campoTITULO->setText(nullptr);
	ui->campoDIA->setText(nullptr);
	ui->campoMES->setText(nullptr);
	ui->campoANO->setText(nullptr);
	ui->campoEDITORA->setText(nullptr);
	ui->campoQUANTIDADE->setText(nullptr);

    cout << "Adicionados " << quantidade << " novos Jornais."  << endl
         << "Quantidade atual de Obras:" << b->nObras() << endl
         << "Quantidade atual de Jornais:" << b->nObras(2) << endl
         << "Quantidade atual de Obras Distintas: " << b->nObrasDiferentes() << endl
         << "Quantidade atual de Jornais Distintos: " << b->nObrasDiferentes(2) << endl;
}

void addJornal::on_btn_delJornal_clicked()
{
	string titulo;
	int dia;
	int mes;
	int ano;
	string editora;
	int quantidade;

	titulo = ui->campoTITULO->text().toStdString();
	dia = ui->campoDIA->text().toInt();
	mes = ui->campoMES->text().toInt();
	ano = ui->campoANO->text().toInt();
	editora = ui->campoEDITORA->text().toStdString();
	quantidade = ui->campoQUANTIDADE->text().toInt();

	poo::Jornais *aux = new poo::Jornais(titulo, ano, editora, dia, mes);
	b->removeObra(aux->getTitulo(), quantidade);

	ui->campoTITULO->setText(nullptr);
	ui->campoDIA->setText(nullptr);
	ui->campoMES->setText(nullptr);
	ui->campoANO->setText(nullptr);
	ui->campoEDITORA->setText(nullptr);
	ui->campoQUANTIDADE->setText(nullptr);

}

void addJornal::on_commandLinkButton_clicked()
{
    this->setVisible(false);
}
