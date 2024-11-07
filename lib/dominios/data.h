#ifndef HEADERDATA_H_INCLUDED
#define HEADERDATA_H_INCLUDED
//Domínio data faz parte da entidade Destino


#endif // HEADERDATA_H_INCLUDED

// Data.h
#ifndef DATA_H
#define DATA_H

#include <iostream>
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
    
    // Novo método para entrada interativa de dados
    void inputData();
};

#endif
