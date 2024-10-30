#include <iostream>
#include <cctype>
#include <string>
#include <typeinfo>
#include "senha.hpp"

using namespace std;

bool Senha::validacaoSenha(string senha){
        int i,j, repeti;
        int adicao, subtra;
        string decrescente, crescente;

        //Verificacao do tamanho da senha.
        if(senha.length() != 5){
                return false;
            }


         //Verificacao se todos os dígitos são números.
        for(int i = 0; i < senha.length(); i++){
            if(!isdigit(senha[i])){
                return false;}
        }


        //Verificacao da sequencia.
        adicao = (senha[0] - '0'); //adicao sera o numero base para calcular a sequência crescente.
        subtra = (senha[0] - '0'); //subtra sera o numero base para calcular a sequência decrescente.
        for(int i = 0; i < 5; i++){
            crescente += to_string(adicao); //forma a sequência crescente pelo adição de mais 1 no numero base
            adicao += 1;
            decrescente += to_string(subtra); //forma a sequência decrescente pelo  subtracao de menos 1 no numero base
            subtra -= 1;
        }

        if(senha == crescente || senha == decrescente){
            return false;
        }


        //Verificacao se há repetção de digitos.
        for(i = 0; i<5; i++){
            repeti = 0;
            for(j=0; j<5; j++){
                if(senha[i] == senha[j]){
                    repeti += 1;}

                if (repeti > 1){
                    return false;}
            }
        }
    }

bool Senha::setSenha(string senha){
    if (validacaoSenha(senha)){
        this -> senha = senha;
        return true;
    }
    return false;

}



int main(){
    Senha *ptrSenha;
    ptrSenha = new Senha();

    if (ptrSenha->setSenha("56843")){
        cout << "Senha = " << ptrSenha->getSenha() << endl;
    }
    else{
        cout << "Senha = Invalido" << endl;
    }


    if (ptrSenha->setSenha("1234t")){
        cout << "Senha = " << ptrSenha->getSenha() << endl;
    }
    else{
        cout << "Senha = Invalido" << endl;
    }

    return 0;
}
