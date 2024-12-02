
#include <iostream>
#include "../../shared/estado_teste.h"

using namespace std;

class Nome
{ // Michele Nakagomi - 232029078
private:
    const int VALORMAXIMO = 30;

    string valor;
    void validar(string);

public:
    void setValor(string);
    string getValor() const;
};

inline string Nome::getValor() const
{
    return valor;
}

// Teste

class TUNome
{
private:
    const string VALORES_VALIDOS[3] = {"michele", "bolodebanana", "dan234"};
    const string VALORES_INVALIDOS[2] = {"-1fdisjfvisjfcsidofjkcsdfjsfisfjmifjosd", "3akkasksadfwfksadfksdkdmcmckdds61"};
    Nome *nome;
    EstadoTeste estado;
    void setUp();
    void tearDown();
    void testarCenariosSucesso();
    void testarCenariosFalha();

public:
    EstadoTeste run();
};