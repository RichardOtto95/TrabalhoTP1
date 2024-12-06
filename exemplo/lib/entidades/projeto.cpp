#include "projeto.h"
#include "../dominios/codigo_pagamento/codigo_pagamento.h"
#include "../dominios/codigo_exemplo/codigo_exemplo.h"

inline void Projeto::setCodigoPagamento(const CodigoPagamento &codigoPagamento)
{
    this->codigoPagamento = codigoPagamento;
}

inline CodigoPagamento Projeto::getCodigoPagamento() const
{
    return codigoPagamento;
}

inline void Projeto::setCodigoExemplo(const CodigoExemplo &codigoExemplo)
{
    this->codigoExemplo = codigoExemplo;
}

inline CodigoExemplo Projeto::getCodigoExemplo() const
{
    return codigoExemplo;
}

// --------------------------------------------------------------------------
// Implementaушes de mжtodos de classe de teste de unidade.

void TUProjeto::setUp()
{
    projeto = new Projeto();
    estado = sucesso;
}

void TUProjeto::tearDown()
{
    delete projeto;
}

void TUProjeto::testarCenariosSucesso()
{
    try
    {
        for (size_t i = 0; i < (sizeof(TUCodigoPagamento::VALORES_VALIDOS) / sizeof(TUCodigoPagamento::VALORES_VALIDOS[0])); i++)
        {
            const CodigoPagamento valorValido = CodigoPagamento(TUCodigoPagamento::VALORES_VALIDOS[i]);
            projeto->setCodigoPagamento(CodigoPagamento(TUCodigoPagamento::VALORES_VALIDOS[i]));
            if (projeto->getCodigoPagamento().getValor() != valorValido.getValor())
            {
                estado = falha;
                break;
            }
        }
    }
    catch (...)
    {
        estado = falha;
        return;
    }

    try
    {
        for (size_t i = 0; i < (sizeof(TUCodigoExemplo::VALORES_VALIDOS) / sizeof(TUCodigoExemplo::VALORES_VALIDOS[0])); i++)
        {
            const CodigoExemplo valorValido = CodigoExemplo(TUCodigoExemplo::VALORES_VALIDOS[i]);
            projeto->setCodigoExemplo(CodigoExemplo(TUCodigoExemplo::VALORES_VALIDOS[i]));
            if (projeto->getCodigoExemplo().getValor() != valorValido.getValor())
            {
                estado = falha;
                break;
            }
        }
    }
    catch (...)
    {
        estado = falha;
        return;
    }
}

void TUProjeto::testarCenariosFalha()
{
    for (size_t i = 0; i < (sizeof(TUCodigoPagamento::VALORES_INVALIDOS) / sizeof(TUCodigoPagamento::VALORES_INVALIDOS[0])); i++)
    {
        const CodigoPagamento valorInvalido = CodigoPagamento(TUCodigoPagamento::VALORES_INVALIDOS[i]);

        try
        {
            estado = falha;
            projeto->setCodigoPagamento(valorInvalido);
        }
        catch (...)
        {
            if (projeto->getCodigoPagamento().getValor() != valorInvalido.getValor())
                estado = sucesso;
        }

        if (estado = falha)
        {
            break;
            return;
        }
    }

    for (size_t i = 0; i < (sizeof(TUCodigoExemplo::VALORES_INVALIDOS) / sizeof(TUCodigoExemplo::VALORES_INVALIDOS[0])); i++)
    {
        const CodigoExemplo valorInvalido = CodigoExemplo(TUCodigoExemplo::VALORES_INVALIDOS[i]);

        try
        {
            estado = falha;
            projeto->setCodigoExemplo(valorInvalido);
        }
        catch (...)
        {
            if (projeto->getCodigoExemplo().getValor() != valorInvalido.getValor())
                estado = sucesso;
        }

        if (estado = falha)
        {
            break;
            return;
        }
    }
}

int TUProjeto::run()
{
    setUp();
    testarCenariosSucesso();
    if (estado == sucesso)
        testarCenariosFalha();
    tearDown();
    return estado;
}

int main()
{
    TUProjeto testeProjeto;

    switch (testeProjeto.run())
    {
    case sucesso:
        cout << "\nSUCESSO - CodigoPagamento";
        break;
    case falha:
        cout << "\nFALHA   - CodigoPagamento";
        break;
    }
}
