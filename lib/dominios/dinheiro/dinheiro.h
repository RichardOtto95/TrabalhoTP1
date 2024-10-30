
#include <iostream>
#include "../../shared/estado_teste.h"

using namespace std;

class Dinheiro
{ // Richard Otto - 231006186
private:
    const double MINIMO = 0;
    const double MAXIMO = 200000;

    double valor;
    void validar(double);

public:
    void setValor(double);
    double getValor() const;
};

inline double Dinheiro::getValor() const
{
    return valor;
}

// Teste

class TUDinheiro
{
private:
    const double VALORES_VALIDOS[5] = {199999.999, 0, 0.0001, 496, 200000};
    const double VALORES_INVALIDOS[2] = {-0.00001, 200000.000001};
    Dinheiro *dinheiro;
    EstadoTeste estado;
    void setUp();
    void tearDown();
    void testarCenariosSucesso();
    void testarCenariosFalha();

public:
    EstadoTeste run();
};