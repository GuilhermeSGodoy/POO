#ifndef ADDREVISTA_H
#define ADDREVISTA_H
#include <QWidget>
#include "biblioteca.h"

using namespace std;

namespace Ui {
class addRevista;
}

class addRevista : public QWidget
{
	Q_OBJECT

public:
    explicit addRevista(poo::Biblioteca *b, QWidget *parent = nullptr);
	~addRevista();

private slots:
    void on_btn_addrevista_clicked();
	void on_btn_delRevista_clicked();

    void on_commandLinkButton_clicked();

private:
    Ui::addRevista *ui;

    poo::Biblioteca *b;
};

#endif // ADDREVISTA_H
