#include <cctype>
#include <string>
#include <typeinfo>
#include "Senha_hpp.h"
using namespace std;

bool Senha::validacao_senha(string senha){
        int i,j, repeti;
        int adicao, subtra;
        string decrescente, crescente;

        //Verificacao do tamanho da senha.
        if(senha.length() != 5){
                return false;}


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


int main(){
    Senha *ptr;
    ptr = new Senha();

    if (ptr->set_senha("56843")){
        cout << "Senha = " << ptr->get_senha() << endl;
    }
    else{
        cout << "Senha = Invalido" << endl;
    }


    if (ptr->set_senha("1234t")){
        cout << "Senha = " << ptr->get_senha() << endl;
    }
    else{
        cout << "Senha = Invalido" << endl;
    }

    return 0;
}


