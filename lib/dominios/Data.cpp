// Data.cpp
#include "headerData.h"

// Construtores
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

// Verificar se o ano é bissexto
bool Data::isBissexto(int a) {
    return (a % 4 == 0);
}

// Validar a data
bool Data::validarData(int d, int m, int a) {
    if (a < 0 || a > 99) return false; // Validar o ano (AA)
    if (m < 1 || m > 12) return false; // Validar o mês (MM)

    int diasMes[] = {31, (isBissexto(a) ? 29 : 28), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; // Dias válidos para cada mês

    if (d < 1 || d > diasMes[m - 1]) return false; // Validar o dia (DD)
    return true;
}

// Definir uma nova data
void Data::setData(int d, int m, int a) {
    if (validarData(d, m, a)) {
        dia = d;
        mes = m;
        ano = a;
    } else {
        cout << "Data inválida." << endl;
    }
}

// Métodos getters
int Data::getDia() {
    return dia;
}

int Data::getMes() {
    return mes;
}

int Data::getAno() {
    return ano;
}

// Exibir a data no formato DD-MM-AA
void Data::exibirData() {
    cout << (dia < 10 ? "0" : "") << dia << "-"
         << (mes < 10 ? "0" : "") << mes << "-"
         << (ano < 10 ? "0" : "") << ano << endl;
}

// Novo método para entrada interativa de dados
void Data::inputData() {
    int d, m, a;
    bool dataValida = false;

    // Continuar pedindo entrada até que a data seja válida
    while (!dataValida) {
        cout << "Digite o dia (1-31): ";
        cin >> d;
        cout << "Digite o mês (1-12): ";
        cin >> m;
        cout << "Digite o ano (0-99): ";
        cin >> a;

        // Validar a data inserida
        if (validarData(d, m, a)) {
            setData(d, m, a); // Definir a data
            dataValida = true; // Sair do loop
        } else {
            cout << "Data inválida! Por favor, tente novamente." << endl;
        }
    }
}

int main() {
    Data data1;
    
    // Entrada interativa da data
    data1.inputData();
    
    // Exibir a data inserida
    data1.exibirData();
    
    return 0;
}
