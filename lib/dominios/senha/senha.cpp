#include <iostream>
#include <cctype>
#include <string>
#include <typeinfo>
#include "senha.hpp"

using namespace std;

void Senha::validar(string valor){
        int i,j, repeti;
        int adicao, subtra;
        string decrescente, crescente;

        //Verificacao do tamanho da senha.
        if(valor.length() != 5){
                throw invalid_argument("Tamanho de senha incorreto.");}


         //Verificacao se todos os dígitos são números.
        for(int i = 0; i < valor.length(); i++){
            if(!isdigit(valor[i])){
                throw invalid_argument("Senha com caracteres invalidos.");}
        }



        //Verificacao da sequencia.
        adicao = (valor[0] - '0'); //adicao sera o numero base para calcular a sequência crescente.
        subtra = (valor[0] - '0'); //subtra sera o numero base para calcular a sequência decrescente.
        for(int i = 0; i < 5; i++){
            crescente += to_string(adicao); //forma a sequência crescente pelo adição de mais 1 no numero base
            adicao += 1;
            decrescente += to_string(subtra); //forma a sequência decrescente pelo  subtracao de menos 1 no numero base
            subtra -= 1;
        }

        if(valor == crescente || valor == decrescente){
            throw invalid_argument("Senha em sequencia invalida");}


        //Verificacao se há repetção de digitos.
        for(i = 0; i<5; i++){
            repeti = 0;
            for(j=0; j<5; j++){
                if(valor[i] == valor[j]){
                    repeti += 1;}

                if (repeti > 1){
                    throw invalid_argument("Senha com caracteres repetidos.");}

            }
        }
    }

void Senha::setValor(string val){
    validar(val);
    this->valor = val;
}


// Declarações dos métodos do Teste Unitário TUAvaliacao

void TUSenha::setUp()
{
    senha = new Senha();
    estado = sucesso;
}

void TUSenha::tearDown()
{
    delete senha;
}

void TUSenha::testarCenariosSucesso()
{
    try
    {
        for (size_t i = 0; i < (sizeof(VALORES_VALIDOS) / sizeof(VALORES_VALIDOS[0])); i++)
        {
            string valorValido = VALORES_VALIDOS[i];
            senha->setValor(valorValido);
            if (senha->getValor() != valorValido)
                estado = falha;
        }
    }
    catch (...)
    {
        estado = falha;
    }
}

void TUSenha::testarCenariosFalha()
{
    for (size_t i = 0; i < (sizeof(VALORES_INVALIDOS) / sizeof(VALORES_INVALIDOS[0])); i++)
    {
        string valorInvalido = VALORES_INVALIDOS[i];

        try
        {
            estado = falha;
            senha->setValor(valorInvalido);
        }
        catch (...)
        {
            if (senha->getValor() != valorInvalido)
                estado = sucesso;
        }
    }
}

EstadoTeste TUSenha::run()
{
    setUp();
    testarCenariosSucesso();
    testarCenariosFalha();
    tearDown();
    return estado;
}

int main()
{
    TUSenha testeSenha;

    switch (testeSenha.run())
    {
    case sucesso:
        cout << "\nSUCESSO - Senha";
        break;
    case falha:
        cout << "\nFALHA   - Senha";
        break;
    }
}
