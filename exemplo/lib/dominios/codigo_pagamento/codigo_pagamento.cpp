#include <iostream>
#include <sstream>
#include "codigo_pagamento.h"

// Declarações dos métodos da casse CodigoPagamento

void CodigoPagamento::validar(string val)
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

void CodigoPagamento::setValor(string val)
{
    validar(val);
    this->valor = val;
}

// Declarações dos métodos do Teste Unitário TUCodigoPagamento

void TUCodigoPagamento::setUp()
{
    codigoPagamento = new CodigoPagamento();
    estado = sucesso;
}

void TUCodigoPagamento::tearDown()
{
    delete codigoPagamento;
}

void TUCodigoPagamento::testarCenariosSucesso()
{
    try
    {
        for (size_t i = 0; i < (sizeof(VALORES_VALIDOS) / sizeof(VALORES_VALIDOS[0])); i++)
        {
            string valorValido = VALORES_VALIDOS[i];
            codigoPagamento->setValor(valorValido);
            if (codigoPagamento->getValor() != valorValido)
                estado = falha;
        }
    }
    catch (...)
    {
        estado = falha;
    }
}

void TUCodigoPagamento::testarCenariosFalha()
{
    for (size_t i = 0; i < (sizeof(VALORES_INVALIDOS) / sizeof(VALORES_INVALIDOS[0])); i++)
    {
        string valorInvalido = VALORES_INVALIDOS[i];

        try
        {
            estado = falha;
            codigoPagamento->setValor(valorInvalido);
        }
        catch (...)
        {
            if (codigoPagamento->getValor() != valorInvalido)
                estado = sucesso;
        }
    }
}

EstadoTeste TUCodigoPagamento::run()
{
    setUp();
    testarCenariosSucesso();
    testarCenariosFalha();
    tearDown();
    return estado;
}

int main()
{
    TUCodigoPagamento testeCodigoPagamento;

    switch (testeCodigoPagamento.run())
    {
    case sucesso:
        cout << "\nSUCESSO - CodigoPagamento";
        break;
    case falha:
        cout << "\nFALHA   - CodigoPagamento";
        break;
    }
}
