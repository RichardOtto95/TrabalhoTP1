#ifndef DOMINIO_H_INCLUDED
#define DOMINIO_H_INCLUDED

#include<string>
using namespace std;


class Nome {
private:

    string nome;
    bool validar (string);

public:
    bool setNome(string);
    string getNome() const;

};
inline string Nome::getNome()const{
    return nome;
}

class TUNome {
public:
    void run();
};


#endif 
