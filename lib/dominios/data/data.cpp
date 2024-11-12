#include "data.h"
#include <stdexcept>
#include <iostream>

using namespace std;

// Declarações dos métodos da classe Data

void Data::validar(int d, int m, int a) {
    if (a < 0 || a > 99) throw invalid_argument("Ano inválido.");
    if (m < 1 || m > 12) throw invalid_argument("Mês inválido.");
    
    int diasMes[] = {31, (isBissexto(a) ? 29 : 28), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (d < 1 || d > diasMes[m - 1]) throw invalid_argument("Dia inválido.");
}

Data::Data(int d, int m, int a) {
    validar(d, m, a);
    this->dia = d;
    this->mes = m;
    this->ano = a;
}

bool Data::isBissexto(int a) {
    return (a % 4 == 0);
}

void Data::setData(int d, int m, int a) {
    validar(d, m, a);
    dia = d;
    mes = m;
    ano = a;
}

int Data::getDia() const { return dia; }
int Data::getMes() const { return mes; }
int Data::getAno() const { return ano; }

// Declarações dos métodos do Teste Unitário TUData

void TUData::setUp() {
    data = new Data();
    estado = sucesso;
}

void TUData::tearDown() {
    delete data;
}

void TUData::testarCenariosSucesso() {
    try {
        for (size_t i = 0; i < (sizeof(VALORES_VALIDOS) / sizeof(VALORES_VALIDOS[0])); i++) {
            int d = VALORES_VALIDOS[i][0];
            int m = VALORES_VALIDOS[i][1];
            int a = VALORES_VALIDOS[i][2];
            
            data->setData(d, m, a);
            if (data->getDia() != d || data->getMes() != m || data->getAno() != a) 
                estado = falha;
        }
    } catch (...) {
        estado = falha;
    }
}

void TUData::testarCenariosFalha() {
    for (size_t i = 0; i < (sizeof(VALORES_INVALIDOS) / sizeof(VALORES_INVALIDOS[0])); i++) {
        int d = VALORES_INVALIDOS[i][0];
        int m = VALORES_INVALIDOS[i][1];
        int a = VALORES_INVALIDOS[i][2];
        
        try {
            estado = falha;
            data->setData(d, m, a);
        } catch (...) {
            estado = sucesso;
        }
    }
}

EstadoTeste TUData::run() {
    setUp();
    testarCenariosSucesso();
    testarCenariosFalha();
    tearDown();
    return estado;
}

int main() {
    TUData testeData;

    switch (testeData.run()) {
    case sucesso:
        cout << "\nSUCESSO - Data";
        break;
    case falha:
        cout << "\nFALHA   - Data";
        break;
    }

    return 0;
}
