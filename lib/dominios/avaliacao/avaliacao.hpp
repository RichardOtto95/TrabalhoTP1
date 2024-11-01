#ifndef AVALIACAO_HPP_INCLUDED
#define AVALIACAO_HPP_INCLUDED
#include "../../shared/estado_teste.h"
#include <iostream>
using namespace std;

class Avaliacao{ //Geilson dos Santos - 231006239
private:
    string valor;

public:
    string getValor();
    void setValor(string valor);
    void validar(string valor);

};

inline string Avaliacao::getValor(){
    return valor;}


// Teste

class TUAvaliacao{
private:
    const string VALORES_VALIDOS[6] = {"0", "1", "2", "3", "4", "5"};
    const string VALORES_INVALIDOS[3] = {"6", "P", "-1"};
    Avaliacao *avaliacao;
    EstadoTeste estado;
    void setUp();
    void tearDown();
    void testarCenariosSucesso();
    void testarCenariosFalha();

public:
    EstadoTeste run();
};


#endif // AVALIACAO_HPP_INCLUDED
