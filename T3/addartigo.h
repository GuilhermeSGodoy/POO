#ifndef ADDARTIGO_H
#define ADDARTIGO_H

#include <QWidget>
#include "biblioteca.h"

namespace Ui {
class addArtigo;
}

class addArtigo : public QWidget
{
	Q_OBJECT

public:
    explicit addArtigo(poo::Biblioteca *b, QWidget *parent = nullptr);
	~addArtigo();

private slots:
	void on_btn_addArtigo_clicked();

	void on_btn_delArtigo_clicked();

    void on_commandLinkButton_clicked();

private:
	Ui::addArtigo *ui;

    poo::Biblioteca *b;
};

#endif // ADDARTIGO_H
