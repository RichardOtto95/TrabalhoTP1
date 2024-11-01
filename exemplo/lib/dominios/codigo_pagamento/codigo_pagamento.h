
#include <iostream>
#include "../../shared/estado_teste.h"

using namespace std;

class CodigoPagamento
{ // Richard Otto - 231006186
private:
    static const int TAMANHO = 8;
    static const char CARACTERE_INICIAL_INVALIDO = '0';
    string valor;
    void validar(string);

public:
    void setValor(string);
    string getValor() const;
};

inline string CodigoPagamento::getValor() const
{
    return valor;
}

// Teste

class TUCodigoPagamento
{
private:
    const string VALORES_VALIDOS[2] = {"38468513", "46843213"};
    const string VALORES_INVALIDOS[4] = {"654168w4", "03554861", "123456", "123456789"};
    CodigoPagamento *codigoPagamento;
    EstadoTeste estado;
    void setUp();
    void tearDown();
    void testarCenariosSucesso();
    void testarCenariosFalha();

public:
    EstadoTeste run();
};