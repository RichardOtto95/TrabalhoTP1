#include <iostream>
#include <sstream>
#include <cctype>
#include <string>
#include <typeinfo>
#include "avaliacao.hpp"

using namespace std;

void Avaliacao::setValor(string val){
    validar(val);
    this->valor = val;}

void Avaliacao::validar(string valor){

        //Verificacao do tamanho.
        if(valor.length() != 1){
            throw invalid_argument("Tamanho incorreto.");
            }

        //Verfica se o formato esta correto
        //Usei o metodo isdigit() que verifica se o caracter eh um digito alphanumerico
        if(!isdigit(valor[0])){
            throw invalid_argument("Formato incorreto.");}

        //Mudando uma varivel de tipo string para int
        //para futuramente verificar se eh valido
        int avali = stoi(valor);

        //Verifica se a avaliacao eh valida
        if (avali > 5 || avali < 0){
            throw invalid_argument("O digito da avaliacao deve ser entre 0 a 5.");}

}

// Declarações dos métodos do Teste Unitário TUAvaliacao

void TUAvaliacao::setUp()
{
    avaliacao = new Avaliacao();
    estado = sucesso;
}

void TUAvaliacao::tearDown()
{
    delete avaliacao;
}

void TUAvaliacao::testarCenariosSucesso()
{
    try
    {
        for (size_t i = 0; i < (sizeof(VALORES_VALIDOS) / sizeof(VALORES_VALIDOS[0])); i++)
        {
            string valorValido = VALORES_VALIDOS[i];
            avaliacao->setValor(valorValido);
            if (avaliacao->getValor() != valorValido)
                estado = falha;
        }
    }
    catch (...)
    {
        estado = falha;
    }
}

void TUAvaliacao::testarCenariosFalha()
{
    for (size_t i = 0; i < (sizeof(VALORES_INVALIDOS) / sizeof(VALORES_INVALIDOS[0])); i++)
    {
        string valorInvalido = VALORES_INVALIDOS[i];

        try
        {
            estado = falha;
            avaliacao->setValor(valorInvalido);
        }
        catch (...)
        {
            if (avaliacao->getValor() != valorInvalido)
                estado = sucesso;
        }
    }
}

EstadoTeste TUAvaliacao::run()
{
    setUp();
    testarCenariosSucesso();
    testarCenariosFalha();
    tearDown();
    return estado;
}

int main()
{
    TUAvaliacao testeAvaliacao;

    switch (testeAvaliacao.run())
    {
    case sucesso:
        cout << "\nSUCESSO - Avaliacao";
        break;
    case falha:
        cout << "\nFALHA   - Avaliacao";
        break;
    }
}
