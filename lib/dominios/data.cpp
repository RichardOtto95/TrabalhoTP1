#include "data.h"
#include "estado_teste.h" // Referência ao arquivo estado_teste.h
#include <stdexcept>

Data::Data() : dia(1), mes(1), ano(0) {}

Data::Data(int d, int m, int a) {
    if (validarData(d, m, a)) {
        dia = d;
        mes = m;
        ano = a;
    } else {
        dia = 1;
        mes = 1;
        ano = 0;
        cout << "Data inválida. Configurada para 01-01-00." << endl;
    }
}

bool Data::isBissexto(int a) {
    return (a % 4 == 0);
}

bool Data::validarData(int d, int m, int a) {
    if (a < 0 || a > 99) return false; // Validar o ano
    if (m < 1 || m > 12) return false; // Validar o mês

    int diasMes[] = {31, (isBissexto(a) ? 29 : 28), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (d < 1 || d > diasMes[m - 1]) return false; // Validar o dia
    return true;
}

void Data::setData(int d, int m, int a) {
    if (validarData(d, m, a)) {
        dia = d;
        mes = m;
        ano = a;
    } else {
        cout << "Data inválida." << endl;
    }
}

int Data::getDia() { return dia; }
int Data::getMes() { return mes; }
int Data::getAno() { return ano; }

void Data::exibirData() {
    cout << (dia < 10 ? "0" : "") << dia << "-"
         << (mes < 10 ? "0" : "") << mes << "-"
         << (ano < 10 ? "0" : "") << ano << endl;
}

void Data::inputData() {
    int d, m, a;
    bool dataValida = false;

    while (!dataValida) {
        cout << "Digite o dia (1-31): ";
        cin >> d;
        cout << "Digite o mês (1-12): ";
        cin >> m;
        cout << "Digite o ano (0-99): ";
        cin >> a;

        if (validarData(d, m, a)) {
            setData(d, m, a);
            dataValida = true;
        } else {
            cout << "Data inválida! Por favor, tente novamente." << endl;
        }
    }
}

// Métodos de Teste

void Data::setUp() {
    // Configurações iniciais para os testes, caso necessário
}

void Data::tearDown() {
    // Limpeza ou redefinição após os testes, caso necessário
}

void Data::testarCenariosSucesso() {
    const int VALORES_VALIDOS[5][3] = {
        {1, 1, 0}, {31, 12, 99}, {29, 2, 20}, {28, 2, 99}, {15, 5, 75}
    };

    for (size_t i = 0; i < (sizeof(VALORES_VALIDOS) / sizeof(VALORES_VALIDOS[0])); i++) {
        int d = VALORES_VALIDOS[i][0];
        int m = VALORES_VALIDOS[i][1];
        int a = VALORES_VALIDOS[i][2];

        setData(d, m, a);

        if (getDia() != d || getMes() != m || getAno() != a) {
            throw std::runtime_error("Falha em cenário de sucesso");
        }
    }
}

void Data::testarCenariosFalha() {
    const int VALORES_INVALIDOS[3][3] = {
        {0, 1, 0}, {32, 12, 99}, {29, 2, 21}
    };

    for (size_t i = 0; i < (sizeof(VALORES_INVALIDOS) / sizeof(VALORES_INVALIDOS[0])); i++) {
        int d = VALORES_INVALIDOS[i][0];
        int m = VALORES_INVALIDOS[i][1];
        int a = VALORES_INVALIDOS[i][2];

        try {
            setData(d, m, a);
            throw std::runtime_error("Falha esperada não ocorreu");
        } catch (...) {
            // Esperado que a exceção ocorra
        }
    }
}

EstadoTeste Data::run() {
    try {
        setUp();
        testarCenariosSucesso();
        testarCenariosFalha();
        tearDown();
        return sucesso;
    } catch (...) {
        return falha;
    }
}

int main() {
    Data testeData;

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
