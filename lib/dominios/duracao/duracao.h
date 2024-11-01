
#include <iostream>
#include "../../shared/estado_teste.h"

using namespace std;

class Duracao
{ // Richard Otto - 231006186
private:
    const int MINIMO = 0;
    const int MAXIMO = 360;

    int valor;
    void validar(int);

public:
    void setValor(int);
    int getValor() const;
};

inline int Duracao::getValor() const
{
    return valor;
}

// Teste

class TUDuracao
{
private:
    const int VALORES_VALIDOS[3] = {0, 360, 237};
    const int VALORES_INVALIDOS[2] = {-1, 361};
    Duracao *duracao;
    EstadoTeste estado;
    void setUp();
    void tearDown();
    void testarCenariosSucesso();
    void testarCenariosFalha();

public:
    EstadoTeste run();
};