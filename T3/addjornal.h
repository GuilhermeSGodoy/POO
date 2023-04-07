#ifndef ADDJORNAL_H
#define ADDJORNAL_H

#include <QWidget>
#include "biblioteca.h"

namespace Ui {
class addJornal;
}

class addJornal : public QWidget
{
	Q_OBJECT

public:
    explicit addJornal(poo::Biblioteca *b, QWidget *parent = nullptr);
	~addJornal();

private slots:
	void on_btn_addjornal_clicked();

	void on_btn_delJornal_clicked();

    void on_commandLinkButton_clicked();

private:
	Ui::addJornal *ui;

    poo::Biblioteca *b;
};

#endif // ADDJORNAL_H
