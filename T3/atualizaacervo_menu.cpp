#include "atualizaacervo_menu.h"
#include "ui_atualizaacervo_menu.h"

atualizaAcervo_Menu::atualizaAcervo_Menu(poo::Biblioteca *b, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::atualizaAcervo_Menu),
    b(b)
{
    ui->setupUi(this);

    add = new Adiciona(b);
}

atualizaAcervo_Menu::~atualizaAcervo_Menu()
{
    delete ui;
}

void atualizaAcervo_Menu::on_btn_add_clicked()
{
    add->clearFocus();

    add->show();
    add->setFocus();
}
