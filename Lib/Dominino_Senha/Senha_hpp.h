#ifndef SENHA_HPP_H_INCLUDED
#define SENHA_HPP_H_INCLUDED

#include <iostream>
using namespace std;

class Senha{
private:
    string senha;

public:
    string get_senha(){return senha;}
    bool set_senha(string senha);
    bool validacao_senha(string senha);

    };

bool Senha::set_senha(string senha){
    if (validacao_senha(senha)){
        this -> senha = senha;
        return true;
    }
    return false;

}

#endif // SENHA_HPP_H_INCLUDED
