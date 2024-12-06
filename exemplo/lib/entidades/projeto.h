#ifndef ENTIDADES_H_INCLUDED
#define ENTIDADES_H_INCLUDED

#include "../dominios/codigo_exemplo/codigo_exemplo.h"
#include "../dominios/codigo_pagamento/codigo_pagamento.h"
#include <string>

using namespace std;

class Projeto
{
private:
    CodigoPagamento codigoPagamento;
    CodigoExemplo codigoExemplo;

public:
    void setCodigoPagamento(const CodigoPagamento &);
    CodigoPagamento getCodigoPagamento() const;
    void setCodigoExemplo(const CodigoExemplo &);
    CodigoExemplo getCodigoExemplo() const;
};

// inline void Projeto::setCodigoPagamento(const CodigoPagamento &codigoPagamento)
// {
//     this->codigoPagamento = codigoPagamento;
// }

// inline CodigoPagamento Projeto::getCodigoPagamento() const
// {
//     return codigoPagamento;
// }

// inline void Projeto::setCodigoExemplo(const CodigoExemplo &codigoExemplo)
// {
//     this->codigoExemplo = codigoExemplo;
// }

// inline CodigoExemplo Projeto::getCodigoExemplo() const
// {
//     return codigoExemplo;
// }

// --------------------------------------------------------------------------
// Exemplo de declaraзгo de classe para teste de unidade de classe entidade.

class TUProjeto
{
private:
    const static int VALOR_VALIDO = 20; // Definiзгo de constante para evitar nъmero mбgico.
    Projeto *projeto;                   // Referкncia para unidade em teste.
    EstadoTeste estado;                 // Estado do teste.
    void setUp();                       // Mйtodo para criar unidade em teste.
    void tearDown();                    // Mйtodo para destruir unidade em teste.
    void testarCenariosSucesso();       // Cenбrio de teste.
    void testarCenariosFalha();         // Cenбrio de teste.
public:
    int run(); // Mйtodo para executar teste.
};

#endif // ENTIDADES_H_INCLUDED
