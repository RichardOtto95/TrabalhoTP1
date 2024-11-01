#include <iostream>
#include <sstream>
#include "codigo_exemplo.h"

// Declarações dos métodos da casse CodigoExemplo

void CodigoExemplo::validar(string val)
{
    for (char v : val)
        if (!isdigit(v))
            throw invalid_argument("O código só permite dígitos numéricos.");
    if (val[0] == CARACTERE_INICIAL_INVALIDO)
        throw invalid_argument("Primeiro dígito deve ser diferente de \"0\".");
    if (val.length() != TAMANHO)
    {
        stringstream ss;
        ss << "O código deve ter tamanho " << TAMANHO << ".";
        throw length_error(ss.str());
    }
}

void CodigoExemplo::setValor(string val)
{
    validar(val);
    this->valor = val;
}

// Declarações dos métodos do Teste Unitário TUCodigoExemplo

void TUCodigoExemplo::setUp()
{
    codigoExemplo = new CodigoExemplo();
    estado = sucesso;
}

void TUCodigoExemplo::tearDown()
{
    delete codigoExemplo;
}

void TUCodigoExemplo::testarCenariosSucesso()
{
    try
    {
        for (size_t i = 0; i < (sizeof(VALORES_VALIDOS) / sizeof(VALORES_VALIDOS[0])); i++)
        {
            string valorValido = VALORES_VALIDOS[i];
            codigoExemplo->setValor(valorValido);
            if (codigoExemplo->getValor() != valorValido)
                estado = falha;
        }
    }
    catch (...)
    {
        estado = falha;
    }
}

void TUCodigoExemplo::testarCenariosFalha()
{
    for (size_t i = 0; i < (sizeof(VALORES_INVALIDOS) / sizeof(VALORES_INVALIDOS[0])); i++)
    {
        string valorInvalido = VALORES_INVALIDOS[i];

        try
        {
            estado = falha;
            codigoExemplo->setValor(valorInvalido);
        }
        catch (...)
        {
            if (codigoExemplo->getValor() != valorInvalido)
                estado = sucesso;
        }
    }
}

EstadoTeste TUCodigoExemplo::run()
{
    setUp();
    testarCenariosSucesso();
    testarCenariosFalha();
    tearDown();
    return estado;
}

int main()
{
    TUCodigoExemplo testeCodigoExemplo;

    switch (testeCodigoExemplo.run())
    {
    case sucesso:
        cout << "\nSUCESSO - CodigoExemplo";
        break;
    case falha:
        cout << "\nFALHA   - CodigoExemplo";
        break;
    }
}
