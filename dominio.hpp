#ifndef DOMINIO_H_INCLUDED
#define DOMINIO_H_INCLUDED

#include<string>
using namespace std;


class Nome {
private:

    string valor;
    bool validar (string);

public:
    bool setValor(string);
    string getValor() const;

};
inline string Nome::getValor()const{
    return valor;
}

#endif // DOMINIO_H_INCLUDED
