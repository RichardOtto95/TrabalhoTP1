
#include <iostream>
#include "../../shared/estado_teste.h"

using namespace std;

class CodigoExemplo
{ // Richard Otto - 231006186
private:
    static const int TAMANHO = 8;
    static const char CARACTERE_INICIAL_INVALIDO = '0';
    string valor;
    void validar(string);

public:
    CodigoExemplo(const string &val = "12345678");
    void setValor(string);
    string getValor() const;
};

inline string CodigoExemplo::getValor() const
{
    return valor;
}

// Teste

class TUCodigoExemplo
{
private:
    CodigoExemplo *codigoExemplo;
    EstadoTeste estado;
    void setUp();
    void tearDown();
    void testarCenariosSucesso();
    void testarCenariosFalha();

public:
    static const string VALORES_VALIDOS[2];
    static const string VALORES_INVALIDOS[4];

    EstadoTeste run();
};

const string TUCodigoExemplo::VALORES_VALIDOS[2] = {"38468513", "46843213"};
const string TUCodigoExemplo::VALORES_INVALIDOS[4] = {"654168w4", "03554861", "123456", "123456789"};