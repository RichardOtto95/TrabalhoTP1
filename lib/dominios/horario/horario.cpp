#include <iostream>
#include <string>
#include <typeinfo>
#include <cctype>
#include "horario.hpp"

using namespace std;

void Horario::validar(string valor){

    //Primeiro verifica se o tamanho esta correto
    if (valor.length() != 5){
        throw invalid_argument("Tamanho incorreto.");}


    //Logo apos verfica se o formato esta correto
    //Usei o metodo isdigit() que verifica de o caracter eh um digito alphanumerico
    if (!isdigit( valor[0]) || !isdigit( valor[1]) || valor[2] != ':' || !isdigit( valor[3]) || !isdigit( valor[4])){
        throw invalid_argument("Formato incorreto.");}

    //Usei o metodo pushback para separar
    //as horas e os minutos
    string horas_str, minutos_str;
    horas_str.push_back(valor[0]);
    horas_str.push_back(valor[1]);
    minutos_str.push_back(valor[3]);
    minutos_str.push_back(valor[4]);

    //Mudando uma varivel de tipo string para int
    //para futuramente verificar se eh valido
    int horas = stoi(horas_str);
    int minutos = stoi(minutos_str);

    //Verifica se o horas eh valido
    if (horas > 23 || horas < 0){
        throw invalid_argument("O digito das horas deve ser entre 00 a 23.");}


    //Verifica se o minutos eh valido
    if (minutos > 59 || minutos < 0){
        throw invalid_argument("O digito das minutos deve ser entre 00 a 59.");}

}

void Horario::setValor(string valor){

    //verifica se eh valido e atribui o valor a class
    validar(valor);
    this->valor = valor;}



// Declarações dos métodos do Teste Unitário TUHorario
void TUHorario::setUp()
{
    horario = new Horario();
    estado = sucesso;
}

void TUHorario::tearDown()
{
    delete horario;
}

void TUHorario::testarCenariosSucesso()
{
    try
    {
        for (size_t i = 0; i < (sizeof(VALORES_VALIDOS) / sizeof(VALORES_VALIDOS[0])); i++)
        {
            string valorValido = VALORES_VALIDOS[i];
            horario->setValor(valorValido);
            if (horario->getValor() != valorValido)
                estado = falha;
        }
    }
    catch (...)
    {
        estado = falha;
    }
}

void TUHorario::testarCenariosFalha()
{
    for (size_t i = 0; i < (sizeof(VALORES_INVALIDOS) / sizeof(VALORES_INVALIDOS[0])); i++)
    {
        string valorInvalido = VALORES_INVALIDOS[i];

        try
        {
            estado = falha;
            horario->setValor(valorInvalido);
        }
        catch (...)
        {
            if (horario->getValor() != valorInvalido)
                estado = sucesso;
        }
    }
}

EstadoTeste TUHorario::run()
{
    setUp();
    testarCenariosSucesso();
    testarCenariosFalha();
    tearDown();
    return estado;
}

int main()
{
    TUHorario testeHorario;

    switch (testeHorario.run())
    {
    case sucesso:
        cout << "\nSUCESSO - Horario";
        break;
    case falha:
        cout << "\nFALHA   - Horario";
        break;
    }
}
