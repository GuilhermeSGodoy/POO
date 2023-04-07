#ifndef ADICIONA_H
#define ADICIONA_H

#include <QWidget>

#include "addlivro.h"
#include "addrevista.h"
#include "addjornal.h"
#include "addartigo.h"

namespace Ui {
class Adiciona;
}

class Adiciona : public QWidget
{
	Q_OBJECT

public:
    explicit Adiciona(poo::Biblioteca *b, QWidget *parent = nullptr);
	~Adiciona();

private slots:
	void on_pushButton_clicked();

	void on_pushButton_3_clicked();

	void on_pushButton_2_clicked();

	void on_pushButton_4_clicked();

    void on_pushButton_backMenu_clicked();

private:
	Ui::Adiciona *ui;

	addLivro *addL;
	addRevista *addR;
	addJornal *addJ;
	addArtigo *addA;

    poo::Biblioteca *b;
};

#endif // ADICIONA_H
