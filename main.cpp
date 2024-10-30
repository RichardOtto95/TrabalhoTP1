#include <iostream>
#include "dominio.hpp"

using namespace std;

#define VALOR_VALIDO "VALIDO"
#define VALOR_INVALIDO "INVALIDO"

int main(){
    Nome nome;

    if(nome.setValor(VALOR_VALIDO))
        cout<<"Valor="<<nome.getValor()<<endl;
    else
        cout<<"Valor invalido, digite um nome menor que 30 caracteres."<<endl;


    if(nome.setValor("INVALIDO_INVALIDO_INVALIDO_INVALIDO"))
        cout<<"Valor="<<nome.getValor()<<endl;
    else
        cout<<"Valor invalido, digite um nome menor que 30 caracteres."<<endl;


    Nome *ptr = new Nome();

    if(ptr->setValor(VALOR_VALIDO))
        cout<<"Valor="<<ptr->getValor()<<endl;
    else
        cout<<"Valor invalido, digite um nome menor que 30 caracteres."<<endl;


    if(ptr->setValor("INVALIDO_INVALIDO_INVALIDO_INVALIDO"))
        cout<<"Valor="<<ptr->getValor()<<endl;
    else
        cout<<"Valor invalido, digite um nome menor que 30 caracteres."<<endl;

    delete ptr;
    return 0;
}
