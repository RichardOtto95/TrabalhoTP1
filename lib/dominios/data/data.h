#ifndef DATA_H
#define DATA_H

#include <iostream>
#include <string>
#include "../../shared/estado_teste.h"

using namespace std;

class Data {
private:
    int dia;
    int mes;
    int ano;

    void validar(int d, int m, int a); // Validação em método separado
    bool isBissexto(int ano);
    void parseData(const string &dataStr); // Método para interpretar string

public:
    Data(const string &dataStr = "01-01-00"); // Construtor recebe string no formato DD-MM-AA

    void setData(const string &dataStr);
    int getDia() const;
    int getMes() const;
    int getAno() const;
};

// Inline para getters
inline int Data::getDia() const { return dia; }
inline int Data::getMes() const { return mes; }
inline int Data::getAno() const { return ano; }

// Classe de Teste Unitário

class TUData {
private:
    const string VALORES_VALIDOS[5] = {
        "01-01-00", "31-12-99", "29-02-20", "28-02-99", "15-05-75"
    };
    const string VALORES_INVALIDOS[3] = {
        "00-01-00", "32-12-99", "29-02-21"
    };

    Data *data;
    EstadoTeste estado;

    void setUp();
    void tearDown();
    void testarCenariosSucesso();
    void testarCenariosFalha();

public:
    EstadoTeste run();
};

#endif // DATA_H
