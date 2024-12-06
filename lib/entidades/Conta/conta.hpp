
#include <iostream>
#include <string>
#include "../../dominios/senha/senha.hpp"
#include "../../dominios/codigo/codigo.hpp"


using namespace std;

class Conta {
    private:
        Codigo codigo;
        Senha senha;
    public:
        void setCodigo(const Codigo&);
        Codigo getCodigo() const;
        void setSenha(const Senha&);
        Senha getSenha() const;

};

// set e get

inline Codigo Conta::getCodigo() const{
    return codigo;
};

inline Senha Conta::getSenha() const{
    return senha;
};

inline void Conta::setCodigo(const Codigo &codigo){
    this->codigo = codigo;
};

inline void Conta::setSenha(const Senha &senha){
    this->senha = senha;
}

// Teste

class TUConta
{
private:   
    const string VALOR_VALIDO_CODIGO =  "1W2e33";
    const string VALOR_VALIDO_SENHA =  "19283";
    Conta* conta;
    EstadoTeste estado;
    void setUp();
    void tearDown();
    void testarCenario();
public:
    EstadoTeste run();

};
