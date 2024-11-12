#ifndef DATA_H
#define DATA_H

#include <iostream>
#include "../../shared/estado_teste.h"

using namespace std;

class Data {
private:
    int dia;
    int mes;
    int ano;

    void validar(int d, int m, int a); // Validação em método separado
    bool isBissexto(int ano);

public:
    Data(int d = 1, int m = 1, int a = 0);

    void setData(int d, int m, int a);
    int getDia() const;
    int getMes() const;
    int getAno() const;
};

// Inline para getter
inline int Data::getDia() const { return dia; }
inline int Data::getMes() const { return mes; }
inline int Data::getAno() const { return ano; }

// Classe de Teste Unitário

class TUData {
private:
    const int VALORES_VALIDOS[5][3] = {
        {1, 1, 0}, {31, 12, 99}, {29, 2, 20}, {28, 2, 99}, {15, 5, 75}
    };
    const int VALORES_INVALIDOS[3][3] = {
        {0, 1, 0}, {32, 12, 99}, {29, 2, 21}
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
