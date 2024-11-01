#include <iostream>
#include "../../shared/estado_teste.h"
#include <string>


using namespace std;

class Codigo
{ // Tauã Frade - 231021389
private:
    const int TAMANHO = 6;
    string valor;
    void validar(string);

public:
    void setValor(string);
    string getValor() const;
};

inline string Codigo::getValor() const
{
    return valor;
}

// Teste

class TUCodigo
{
private:
    const string VALORES_VALIDOS[5] = {"ABCDEF" , "d8eT5e" , "78J980", "123456", "m12E23"};
    const string VALORES_INVALIDOS[5] = {"-asetf" , "#@%!&*" , "12@4" , "mc@l+teegis" , " "};
    Codigo *codigo;
    EstadoTeste estado;
    void setUp();
    void tearDown();
    void testarCenariosSucesso();
    void testarCenariosFalha();

public:
    EstadoTeste run();
};