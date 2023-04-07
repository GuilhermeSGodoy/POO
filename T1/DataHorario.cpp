#include "DataHorario.h"

namespace poo {

    DataHorario::DataHorario(int dia, int mes, int ano, int hora, int minuto, int segundo) :
    dia(dia), mes(mes), ano(ano), hora(hora), minuto(minuto), segundo(segundo) {
    }

    DataHorario::~DataHorario() {
    }

    int DataHorario::compara(DataHorario& data) {
        if (this->ano != data.ano) {
            if (this->ano > data.ano)
                return 1;
            else
                return -1;
        } else if (this->mes != data.mes) {
            if (this->mes > data.mes)
                return 1;
            else
                return -1;
        } else if (this->dia != data.dia) {
            if (this->dia > data.dia)
                return 1;
            else
                return -1;
        } else if (this->hora != data.hora) {
            if (this->hora > data.hora)
                return 1;
            else
                return -1;
        } else if (this->minuto != data.minuto) {
            if (this->minuto > data.minuto)
                return 1;
            else
                return -1;
        } else if (this->segundo != data.segundo) {
            if (this->segundo > data.segundo)
                return 1;
            else
                return -1;
        } else
            return 0;
    }

    int DataHorario::getDia() {
        return dia;
    }

    int DataHorario::getMes() {
        return mes;
    }

    int DataHorario::getAno() {
        return ano;
    }

    int DataHorario::getHora() {
        return hora;
    }

    int DataHorario::getMinuto() {
        return minuto;
    }

    int DataHorario::getSegundo() {
        return segundo;
    }

    void DataHorario::imprime(bool flag) {
        if (!flag)
            cout << getDia() << "/" << getMes() << "/" << getAno() << "  " << getHora() << ":" << getMinuto() << ":" << getSegundo() << endl;
        else if (hora > 12)
            cout << getDia() << "/" << getMes() << "/" << getAno() << "  " << getHora() - 12 << ":" << getMinuto() << ":" << getSegundo() << " PM" << endl;
        else if (hora == 12)
            cout << getDia() << "/" << getMes() << "/" << getAno() << "  " << getHora() << ":" << getMinuto() << ":" << getSegundo() << " PM" << endl;
        else
            cout << getDia() << "/" << getMes() << "/" << getAno() << "  " << getHora() << ":" << getMinuto() << ":" << getSegundo() << " AM" << endl;
    }

    void DataHorario::imprimePorExtenso() {
        string meses[12] = {"Janeiro", "Fevereiro", "Março", "Abril",
            "Maio", "Junho", "Julho", "Agosto",
            "Setembro", "Outubro", "Novembro", "Dezembro"};

        cout << getDia() << " de " << meses[getMes() - 1] << " de " << getAno() << " - " << getHora() << " horas, " << getMinuto() << " minutos e " << getSegundo() << " segundos." << endl;
    }

}
