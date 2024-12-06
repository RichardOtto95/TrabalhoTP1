#include <iostream>
#include <sstream>
#include "codigo.hpp"

// Declarações dos métodos da casse Codigo

//Construtores

Codigo::Codigo(){
    valor = "000000"; // valor padrão do codigo
}

Codigo::Codigo(string val){
    setValor(val);
}
// metodo de validação
void Codigo::validar(string cod)
{
    if(cod.length() != TAMANHO){
        throw invalid_argument("O codigo deve conter exatos 6 caracteres");
    }
    for(int i = 0; i < 6 ; i++) {
        if( !isalpha(cod[i]) && !isdigit(cod[i]) ){ // se o caracter não for nem alfabeticou nem numerico ele não é aceito
                throw invalid_argument("O codigo deve conter apenas caracteres alfanumericos");
        }
    }
}
// metodo set
void Codigo::setValor(string val)
{
    validar(val);
    this->valor = val;
}

// Declarações dos métodos do Teste Unitário TUCodigo

void TUCodigo::setUp()
{
    codigo = new Codigo();
    estado = sucesso;
}

void TUCodigo::tearDown()
{
    delete codigo;
}

void TUCodigo::testarCenariosSucesso()
{
    try
    {
        for (size_t i = 0; i < (sizeof(VALORES_VALIDOS) / sizeof(VALORES_VALIDOS[0])); i++)
        {
            string valorValido = VALORES_VALIDOS[i];
            codigo->setValor(valorValido);
            if (codigo->getValor() != valorValido)
                estado = falha;
        }
    }
    catch (...)
    {
        estado = falha;
    }
}

void TUCodigo::testarCenariosFalha()
{
    for (size_t i = 0; i < (sizeof(VALORES_INVALIDOS) / sizeof(VALORES_INVALIDOS[0])); i++)
    {
        string valorInvalido = VALORES_INVALIDOS[i];

        try
        {
            estado = falha;
            codigo->setValor(valorInvalido);
        }
        catch (...)
        {
            if (codigo->getValor() != valorInvalido)
                estado = sucesso;
        }
    }
}

EstadoTeste TUCodigo::run()
{
    setUp();
    testarCenariosSucesso();
    testarCenariosFalha();
    tearDown();
    return estado;
}

int main()
{
    TUCodigo testeCodigo;

    switch (testeCodigo.run())
    {
    case sucesso:
        cout << "\nSUCESSO - Codigo";
        break;
    case falha:
        cout << "\nFALHA   - Codigo";
        break;
    }
}
