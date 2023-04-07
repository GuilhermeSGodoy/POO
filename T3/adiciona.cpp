#include "adiciona.h"
#include "ui_adiciona.h"

Adiciona::Adiciona(poo::Biblioteca *b, QWidget *parent) :
	QWidget(parent),
    ui(new Ui::Adiciona),
    b(b)
{
	ui->setupUi(this);
    this->setWindowTitle(QString::fromStdString("Atualização do Acervo"));

    addL = new addLivro(b);
    addR = new addRevista(b);
    addJ = new addJornal(b);
    addA = new addArtigo(b);
}

Adiciona::~Adiciona()
{
	delete ui;
}

void Adiciona::on_pushButton_clicked()
{
	addL->clearFocus();

    this->setVisible(false);

	addL->show();
	addL->setFocus();
}

void Adiciona::on_pushButton_2_clicked()
{
    addJ->clearFocus();

    this->setVisible(false);

    addJ->show();
    addJ->setFocus();
}

void Adiciona::on_pushButton_3_clicked()
{
	addR->clearFocus();

    this->setVisible(false);

	addR->show();
	addR->setFocus();
}

void Adiciona::on_pushButton_4_clicked()
{
	addA->clearFocus();

    this->setVisible(false);

	addA->show();
	addA->setFocus();
}


void Adiciona::on_pushButton_backMenu_clicked()
{
    this->setVisible(false);
}
