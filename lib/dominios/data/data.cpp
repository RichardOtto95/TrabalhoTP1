#include "data_teste.h"
#include <stdexcept>
#include <sstream>
#include <iomanip>

using namespace std;

// Método para validar os componentes da data
void Data::validar(int d, int m, int a) {
    if (a < 0 || a > 99) throw invalid_argument("Ano inválido.");
    if (m < 1 || m > 12) throw invalid_argument("Mês inválido.");
    
    int diasMes[] = {31, (isBissexto(a) ? 29 : 28), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (d < 1 || d > diasMes[m - 1]) throw invalid_argument("Dia inválido.");
}

// Método para verificar se um ano é bissexto
bool Data::isBissexto(int a) {
    return (a % 4 == 0);
}

// Método para interpretar a string no formato DD-MM-AA
void Data::parseData(const string &dataStr) {
    if (dataStr.size() != 8 || dataStr[2] != '-' || dataStr[5] != '-')
        throw invalid_argument("Formato de data inválido. Use DD-MM-AA.");

    int d, m, a;
    char sep1, sep2;
    stringstream ss(dataStr);
    ss >> d >> sep1 >> m >> sep2 >> a;

    if (ss.fail() || sep1 != '-' || sep2 != '-')
        throw invalid_argument("Formato de data inválido.");

    validar(d, m, a);

    this->dia = d;
    this->mes = m;
    this->ano = a;
}

// Construtor
Data::Data(const string &dataStr) {
    parseData(dataStr);
}

// Método para definir a data
void Data::setData(const string &dataStr) {
    parseData(dataStr);
}

// Testes Unitários
void TUData::setUp() {
    data = new Data();
    estado = sucesso;
}

void TUData::tearDown() {
    delete data;
}

void TUData::testarCenariosSucesso() {
    try {
        for (const auto &valor : VALORES_VALIDOS) {
            data->setData(valor);
            stringstream ss;
            ss << setw(2) << setfill('0') << data->getDia() << "-"
               << setw(2) << setfill('0') << data->getMes() << "-"
               << setw(2) << setfill('0') << data->getAno();
            
            if (valor != ss.str())
                estado = falha;
        }
    } catch (...) {
        estado = falha;
    }
}

void TUData::testarCenariosFalha() {
    for (const auto &valor : VALORES_INVALIDOS) {
        try {
            estado = falha;
            data->setData(valor);
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
