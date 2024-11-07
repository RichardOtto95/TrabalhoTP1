#include <iostream>
#include <sstream>
#include "nome.h"

// Declarações dos métodos da casse Nome

void Nome::validar(string val)
{
    if (val.length() > VALORMAXIMO)
        throw invalid_argument("O nome deve conter menos que 30 caracteres.");
}

void Nome::setValor(string val)
{
    validar(val);
    this->valor = val;
}

// Declarações dos métodos do Teste Unitário TUNome

void TUNome::setUp()
{
    nome = new Nome();
    estado = sucesso;
}

void TUNome::tearDown()
{
    delete nome;
}

void TUNome::testarCenariosSucesso()
{
    try
    {
        for (size_t i = 0; i < (sizeof(VALORES_VALIDOS) / sizeof(VALORES_VALIDOS[0])); i++)
        {
            string valorValido = VALORES_VALIDOS[i];
            nome->setValor(valorValido);
            if (nome->getValor() != valorValido)
                estado = falha;
        }
    }
    catch (...)
    {
        estado = falha;
    }
}

void TUNome::testarCenariosFalha()
{
    for (size_t i = 0; i < (sizeof(VALORES_INVALIDOS) / sizeof(VALORES_INVALIDOS[0])); i++)
    {
        string valorInvalido = VALORES_INVALIDOS[i];

        try
        {
            estado = falha;
            nome->setValor(valorInvalido);
        }
        catch (...)
        {
            if (nome->getValor() != valorInvalido)
                estado = sucesso;
        }
    }
}

EstadoTeste TUNome::run()
{
    setUp();
    testarCenariosSucesso();
    testarCenariosFalha();
    tearDown();
    return estado;
}

int main()
{
    TUNome testeNome;

    switch (testeNome.run())
    {
    case sucesso:
        cout << "\nSUCESSO - Nome";
        break;
    case falha:
        cout << "\nFALHA   - Nome";
        break;
    }
}
