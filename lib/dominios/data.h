#ifndef DATA_H
#define DATA_H

#include <iostream>
#include "estado_teste.h" // Inclui o arquivo estado_teste.h
using namespace std;

class Data {
private:
    int dia;
    int mes;
    int ano;

    bool isBissexto(int ano);
    bool validarData(int d, int m, int a);

public:
    Data();
    Data(int d, int m, int a);

    void setData(int d, int m, int a);
    int getDia();
    int getMes();
    int getAno();
    void exibirData();
    void inputData();

    // Métodos de Teste
    void setUp();
    void tearDown();
    void testarCenariosSucesso();
    void testarCenariosFalha();
    EstadoTeste run();
};

#endif // DATA_H
