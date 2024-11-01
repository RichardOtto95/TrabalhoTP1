#ifndef SENHA_HPP_INCLUDED
#define SENHA_HPP_INCLUDED
#include "../../shared/estado_teste.h"
#include <iostream>
using namespace std;

class Senha{ //Geilson dos Santos - 231006239
private:
    string valor;

public:
    string getValor();
    void setValor(string valor);
    void validar(string valor);

};

inline string Senha::getValor(){
    return valor;}

// Teste

class TUSenha{
private:
    const string VALORES_VALIDOS[3] = {"26485", "17835", "20496"};
    const string VALORES_INVALIDOS[4] = {"12345", "P9864", "23425", "235678"};
    Senha *senha;
    EstadoTeste estado;
    void setUp();
    void tearDown();
    void testarCenariosSucesso();
    void testarCenariosFalha();

public:
    EstadoTeste run();
};

#endif // SENHA_HPP_INCLUDED
