#include <iostream>
#include <sstream>

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

void CodigoPagamento::validar(string val)
{
    for (char v : val)
        if (!isdigit(v))
            throw invalid_argument("O código só permite dígitos numéricos.");
    if (val[0] == CARACTERE_INICIAL_INVALIDO)
        throw invalid_argument("Primeiro dígito deve ser diferente de \"0\".");
    if (val.length() != TAMANHO)
    {
        stringstream ss;
        ss << "O código deve ter tamanho " << TAMANHO << ".";
        throw length_error(ss.str());
    }
}

void CodigoPagamento::setValor(string val)
{
    validar(val);
    this->valor = val;
}

enum EstadoTeste
{
    sucesso = -1,
    falha
};

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

void TUCodigoPagamento::setUp()
{
    codigoPagamento = new CodigoPagamento();
    estado = sucesso;
}

void TUCodigoPagamento::tearDown()
{
    delete codigoPagamento;
}

void TUCodigoPagamento::testarCenariosSucesso()
{
    try
    {
        for (size_t i = 0; i < (sizeof(VALORES_VALIDOS) / sizeof(VALORES_VALIDOS[0])); i++)
        {
            string valorValido = VALORES_VALIDOS[i];
            codigoPagamento->setValor(valorValido);
            if (codigoPagamento->getValor() != valorValido)
                estado = falha;
        }
    }
    catch (...)
    {
        estado = falha;
    }
}

void TUCodigoPagamento::testarCenariosFalha()
{
    for (size_t i = 0; i < (sizeof(VALORES_INVALIDOS) / sizeof(VALORES_INVALIDOS[0])); i++)
    {
        string valorInvalido = VALORES_INVALIDOS[i];

        try
        {
            codigoPagamento->setValor(valorInvalido);
            estado = falha;
        }
        catch (...)
        {
            if (codigoPagamento->getValor() == valorInvalido)
                estado = sucesso;
        }
    }
}

EstadoTeste TUCodigoPagamento::run()
{
    setUp();
    testarCenariosSucesso();
    testarCenariosFalha();
    tearDown();
    return estado;
}

int main()
{
    TUCodigoPagamento testeCodigoPagamento;

    switch (testeCodigoPagamento.run())
    {
    case sucesso:
        cout << "SUCESSO - CodigoPagamento";
        break;
    case falha:
        cout << "FALHA   - CodigoPagamento";
        break;
    }
}
