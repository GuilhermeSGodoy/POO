#ifndef MENUPRINCIPAL_H
#define MENUPRINCIPAL_H

#include <QWidget>

#include "atualizaacervo_menu.h"
#include "acervo.h"
#include "biblioteca.h"
#include <fstream>

QT_BEGIN_NAMESPACE
namespace Ui { class MenuPrincipal; }
QT_END_NAMESPACE

class MenuPrincipal : public QWidget
{
	Q_OBJECT

public:
	MenuPrincipal(QWidget *parent = nullptr);
	~MenuPrincipal();

private slots:
	void on_btn_atualiza_clicked();

	void on_btn_acervo_clicked();

private:
	Ui::MenuPrincipal *ui;

	acervo *acervoMenu;

	Adiciona *add;

    poo::Biblioteca* b;
};
#endif // MENUPRINCIPAL_H
