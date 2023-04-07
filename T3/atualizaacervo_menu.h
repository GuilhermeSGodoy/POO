#ifndef ATUALIZAACERVO_MENU_H
#define ATUALIZAACERVO_MENU_H

#include <QWidget>

#include "adiciona.h"

namespace Ui {
class atualizaAcervo_Menu;
}

class atualizaAcervo_Menu : public QWidget
{
    Q_OBJECT

public:
    explicit atualizaAcervo_Menu(poo::Biblioteca *b, QWidget *parent = nullptr);
    ~atualizaAcervo_Menu();

private slots:
    void on_btn_add_clicked();

private:
    Ui::atualizaAcervo_Menu *ui;

    Adiciona *add;

    poo::Biblioteca *b;
};

#endif // ATUALIZAACERVO_MENU_H
