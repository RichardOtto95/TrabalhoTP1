#ifndef AVALIACAO_HPP_INCLUDED
#define AVALIACAO_HPP_INCLUDED

#include <iostream>
using namespace std;

class Avaliacao{
private:
    string avaliacao;

public:
    string get_avaliacao(){return avaliacao;}
    bool set_avaliacao(string avaliacao);
    bool validacao_avaliacao(string avaliacao);

};

#endif // AVALIACAO_HPP_INCLUDED
