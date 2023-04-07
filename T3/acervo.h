#ifndef ACERVO_H
#define ACERVO_H

#include <QWidget>
#include "biblioteca.h"

namespace Ui {
class acervo;
}

class acervo : public QWidget
{
	Q_OBJECT

public:
    explicit acervo(poo::Biblioteca *b, QWidget *parent = nullptr);
	~acervo();

	void mostrarInformacoes();
    void on_btn_close_clicked();

private slots:
    void on_commandLinkButton_clicked();

private:
	Ui::acervo *ui;

    poo::Biblioteca *b;
};

#endif // ACERVO_H
