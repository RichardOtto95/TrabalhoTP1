#include <iostream>
#include <sstream>
#include "dinheiro.h"

// Declarações dos métodos da casse Dinheiro

void Dinheiro::validar(double val)
{
    if (val < MINIMO || val > MAXIMO)
        throw invalid_argument("O valor do dinheiro deve ser de 0,00 e 200.000,00.");
}

void Dinheiro::setValor(double val)
{
    validar(val);
    this->valor = val;
}

// Declarações dos métodos do Teste Unitário TUDinheiro

void TUDinheiro::setUp()
{
    dinheiro = new Dinheiro();
    estado = sucesso;
}

void TUDinheiro::tearDown()
{
    delete dinheiro;
}

void TUDinheiro::testarCenariosSucesso()
{
    try
    {
        for (size_t i = 0; i < (sizeof(VALORES_VALIDOS) / sizeof(VALORES_VALIDOS[0])); i++)
        {
            double valorValido = VALORES_VALIDOS[i];
            dinheiro->setValor(valorValido);
            if (dinheiro->getValor() != valorValido)
                estado = falha;
        }
    }
    catch (...)
    {
        estado = falha;
    }
}

void TUDinheiro::testarCenariosFalha()
{
    for (size_t i = 0; i < (sizeof(VALORES_INVALIDOS) / sizeof(VALORES_INVALIDOS[0])); i++)
    {
        double valorInvalido = VALORES_INVALIDOS[i];

        try
        {
            estado = falha;
            dinheiro->setValor(valorInvalido);
        }
        catch (...)
        {
            if (dinheiro->getValor() != valorInvalido)
                estado = sucesso;
        }
    }
}

EstadoTeste TUDinheiro::run()
{
    setUp();
    testarCenariosSucesso();
    testarCenariosFalha();
    tearDown();
    return estado;
}

int main()
{
    TUDinheiro testeDinheiro;

    switch (testeDinheiro.run())
    {
    case sucesso:
        cout << "\nSUCESSO - Dinheiro";
        break;
    case falha:
        cout << "\nFALHA   - Dinheiro";
        break;
    }
}
