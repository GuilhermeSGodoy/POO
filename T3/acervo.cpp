#include "acervo.h"
#include "ui_acervo.h"
#include "obras.h"

acervo::acervo(poo::Biblioteca *b, QWidget *parent) :
	QWidget(parent),
    ui(new Ui::acervo),
    b(b)
{
    ui->setupUi(this);
    this->setWindowTitle(QString::fromStdString("Acervo"));
}

acervo::~acervo()
{
	delete ui;
}

void acervo::mostrarInformacoes()
{
	vector<poo::Obras *> auxiliar;
	auxiliar = b->getVector();

	ui->tableWidget->setRowCount(b->nObrasDiferentes());

    ui->tableWidget->setColumnCount(10);

	QStringList m_TableHeader;

	m_TableHeader<<"TIPO"<<"TÍTULO"<<"AUTOR"<<"GÊNERO"<<"EDITORA"<<"EDIÇÃO"<<"DIA"<<"MÊS"<<"ANO"<<"QUANTIDADE";
	ui->tableWidget->setHorizontalHeaderLabels(m_TableHeader);

	int lin = 0;

	for (int i = 0; i < auxiliar.size(); i++) {

		int tipo = auxiliar[i]->getTipo();

		poo::Livros *l;
		poo::Revistas *r;
		poo::Jornais *j;
		poo::Artigos *a;

		ui->tableWidget->setItem(lin, 1, new QTableWidgetItem(QString::fromStdString(auxiliar[i]->getTitulo())));

		int ano = auxiliar[i]->getAno();
		string anoS = to_string(ano);
		ui->tableWidget->setItem(lin, 8, new QTableWidgetItem(QString::fromStdString(anoS)));

		int qtde = auxiliar[i]->getQuantidade();
		string qtdeS = to_string(qtde);
        ui->tableWidget->setItem(lin, 9, new QTableWidgetItem(QString::fromStdString(qtdeS)));


		switch (tipo)
		{
			case 0: {
				l = (poo::Livros *) auxiliar[i];
				ui->tableWidget->setItem(lin, 0, new QTableWidgetItem(QString::fromStdString("Livro")));
				ui->tableWidget->setItem(lin, 2, new QTableWidgetItem(QString::fromStdString(l->getAutor())));
				ui->tableWidget->setItem(lin, 3, new QTableWidgetItem(QString::fromStdString(l->getGenero())));
                break;
			}

			case 1: {
				r = (poo::Revistas *) auxiliar[i];
				ui->tableWidget->setItem(lin, 0, new QTableWidgetItem(QString::fromStdString("Revista")));
                ui->tableWidget->setItem(lin, 4, new QTableWidgetItem(QString::fromStdString(r->getEditora())));

				int edicao = r->getEdicao();
				string edicaoS = to_string(edicao);
                ui->tableWidget->setItem(lin, 5, new QTableWidgetItem(QString::fromStdString(edicaoS)));
				break;
			}

			case 2: {
				j = (poo::Jornais *) auxiliar[i];
				ui->tableWidget->setItem(lin, 0, new QTableWidgetItem(QString::fromStdString("Jornal")));
                ui->tableWidget->setItem(lin, 4, new QTableWidgetItem(QString::fromStdString(j->getEditora())));

				int dia = j->getDia();
				int mes = j->getMes();
				string diaS = to_string(dia);
				string mesS = to_string(mes);
				ui->tableWidget->setItem(lin, 6, new QTableWidgetItem(QString::fromStdString(diaS)));
				ui->tableWidget->setItem(lin, 7, new QTableWidgetItem(QString::fromStdString(mesS)));
				break;
			}

			case 3: {
				a = (poo::Artigos *) auxiliar[i];
				ui->tableWidget->setItem(lin, 0, new QTableWidgetItem(QString::fromStdString("Artigo")));
				ui->tableWidget->setItem(lin, 2, new QTableWidgetItem(QString::fromStdString(a->getAutor())));
				break;
			}
		}
		lin++;
	}
}

void acervo::on_btn_close_clicked()
{
    void on_btn_close_clicked();
}


void acervo::on_commandLinkButton_clicked()
{
    this->setVisible(false);
}
