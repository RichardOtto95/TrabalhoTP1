#include "conta.hpp"
#include <string>


using namespace std;

// declarações metodos TU conta

void TUConta::setUp()
{
    conta = new Conta();
    estado = sucesso;
}

void TUConta::tearDown()
{
    delete conta;
}

void TUConta::testarCenario(){

    Senha senha;
    senha.setValor(VALOR_VALIDO_SENHA);
    conta->setSenha(senha);
    if(conta->getSenha().getValor() != VALOR_VALIDO_SENHA)
        estado = falha;
    
    Codigo codigo;
    codigo.setValor(VALOR_VALIDO_CODIGO);
    conta->setCodigo(codigo);
    if(conta->getCodigo().getValor() != VALOR_VALIDO_CODIGO)
        estado = falha;
}

EstadoTeste TUConta::run()
{
    setUp();
    testarCenario();
    tearDown();
    return estado;
}


int main()
{
    TUConta testeConta;

    switch (testeConta.run())
    {
    case sucesso:
        cout << "\nSUCESSO - Conta";
        break;
    case falha:
        cout << "\nFALHA   - Conta";
        break;
    }
}