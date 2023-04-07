#ifndef ADDLIVRO_H
#define ADDLIVRO_H
#include "biblioteca.h"
#include <QWidget>

using namespace std;

namespace Ui {
class addLivro;
}

class addLivro : public QWidget
{
	Q_OBJECT

public:
    explicit addLivro(poo::Biblioteca *b, QWidget *parent = nullptr);
	~addLivro();

private slots:
	void on_btn_addlivro_clicked();

	void on_btn_delLivro_clicked();

    void on_commandLinkButton_clicked();

private:
	Ui::addLivro *ui;

    poo::Biblioteca *b;
};

#endif // ADDLIVRO_H
