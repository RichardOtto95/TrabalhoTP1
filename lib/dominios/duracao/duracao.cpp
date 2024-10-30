#include <iostream>
#include <sstream>
#include "duracao.h"

// Declarações dos métodos da casse Duracao

void Duracao::validar(int val)
{
    if (val < MINIMO || val > MAXIMO)
        throw invalid_argument("O valor da duracao deve ser de 0 e 360.");
}

void Duracao::setValor(int val)
{
    validar(val);
    this->valor = val;
}

// Declarações dos métodos do Teste Unitário TUDuracao

void TUDuracao::setUp()
{
    duracao = new Duracao();
    estado = sucesso;
}

void TUDuracao::tearDown()
{
    delete duracao;
}

void TUDuracao::testarCenariosSucesso()
{
    try
    {
        for (size_t i = 0; i < (sizeof(VALORES_VALIDOS) / sizeof(VALORES_VALIDOS[0])); i++)
        {
            int valorValido = VALORES_VALIDOS[i];
            duracao->setValor(valorValido);
            if (duracao->getValor() != valorValido)
                estado = falha;
        }
    }
    catch (...)
    {
        estado = falha;
    }
}

void TUDuracao::testarCenariosFalha()
{
    for (size_t i = 0; i < (sizeof(VALORES_INVALIDOS) / sizeof(VALORES_INVALIDOS[0])); i++)
    {
        int valorInvalido = VALORES_INVALIDOS[i];

        try
        {
            estado = falha;
            duracao->setValor(valorInvalido);
        }
        catch (...)
        {
            if (duracao->getValor() != valorInvalido)
                estado = sucesso;
        }
    }
}

EstadoTeste TUDuracao::run()
{
    setUp();
    testarCenariosSucesso();
    testarCenariosFalha();
    tearDown();
    return estado;
}

int main()
{
    TUDuracao testeDuracao;

    switch (testeDuracao.run())
    {
    case sucesso:
        cout << "\nSUCESSO - Duracao";
        break;
    case falha:
        cout << "\nFALHA   - Duracao";
        break;
    }
}
