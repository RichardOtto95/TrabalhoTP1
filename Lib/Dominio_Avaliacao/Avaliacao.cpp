#include <iostream>
#include <cctype>
#include <string>
#include <typeinfo>
#include "Avaliacao.hpp"

using namespace std;
bool Avaliacao::set_avaliacao(string avaliacao){
    if (validacao_avaliacao(avaliacao)){
        this -> avaliacao = avaliacao;
        return true;
    }
    return false;

}
bool Avaliacao::validacao_avaliacao(string avaliacao){

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

int main(){
    Avaliacao *ptr;
    ptr = new Avaliacao();

    if (ptr->set_avaliacao("5")){
        cout << "Avaliacao = " << ptr->get_avaliacao() << endl;
    }
    else{
        cout << "Avaliacao = Invalido" << endl;
    }


    if (ptr->set_avaliacao("6")){
        cout << "Avaliacao = " << ptr->get_avaliacao() << endl;
    }
    else{
        cout << "Avaliacao = Invalido" << endl;
    }

    return 0;
}


