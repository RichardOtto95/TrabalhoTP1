#ifndef HORARIO_HPP_INCLUDED
#define HORARIO_HPP_INCLUDED
#include <iostream>
#include "../../shared/estado_teste.h"

using namespace std;

class Horario{ //Geilson dos Santos - 231006239
private:
    string valor;
    void validar(string valor);

public:
    string getValor();
    void setValor(string valor);

};
inline string Horario::getValor(){
    return valor;}



// Teste

class TUHorario{
private:
    const string VALORES_VALIDOS[3] = {"00:00", "04:45", "22:02"};
    const string VALORES_INVALIDOS[3] = {"00500", "34:00", "22:64"};
    Horario *horario;
    EstadoTeste estado;
    void setUp();
    void tearDown();
    void testarCenariosSucesso();
    void testarCenariosFalha();

public:
    EstadoTeste run();
};
#endif // HORARIO_HPP_INCLUDED
