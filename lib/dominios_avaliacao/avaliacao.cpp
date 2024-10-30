#include <iostream>
#include <cctype>
#include <string>
#include <typeinfo>
#include "avaliacao.hpp"

using namespace std;


bool Avaliacao::validacaoAvaliacao(string avaliacao){

        //Verificacao do tamanho.
        if(avaliacao.length() != 1){
                return false;
            }

        //Verfica se o formato esta correto
        //Usei o metodo isdigit() que verifica se o caracter eh um digito alphanumerico
        if(!isdigit(avaliacao[0])){
                return false;}

        //Mudando uma varivel de tipo string para int
        //para futuramente verificar se eh valido
        int avali = stoi(avaliacao);

        //Verifica se a avaliacao eh valida
        if (avali > 5 || avali < 0){
            return false;
        }

        return true;
}

bool Avaliacao::setAvaliacao(string avaliacao){
    if (validacaoAvaliacao(avaliacao)){
        this->avaliacao = avaliacao;
        return true;
    }
    return false;

}

int main(){
    Avaliacao *ptrAvaliacao;
    ptrAvaliacao = new Avaliacao();

    if (ptrAvaliacao->setAvaliacao("5")){
        cout << "Avaliacao = " << ptrAvaliacao->getAvaliacao() << endl;
    }
    else{
        cout << "Avaliacao = Invalido" << endl;
    }


    if (ptrAvaliacao->setAvaliacao("6")){
        cout << "Avaliacao = " << ptrAvaliacao->getAvaliacao() << endl;
    }
    else{
        cout << "Avaliacao = Invalido" << endl;
    }

    return 0;
}

