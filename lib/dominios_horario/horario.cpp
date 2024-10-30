#include <iostream>
#include <string>
#include <typeinfo>
#include <cctype>
#include "horario.hpp"

using namespace std;

bool Horario::validarHorario(string horario){

    //Primeiro verifica se o tamanho esta correto
    if (horario.length() != 5){
        return false;
    }

    //Logo apos verfica se o formato esta correto
    //Usei o metodo isdigit() que verifica de o caracter eh um digito alphanumerico
    if (!isdigit( horario[0]) || !isdigit( horario[1]) || horario[2] != ':' || !isdigit( horario[3]) || !isdigit( horario[4])){

       return false;
    }

    //Usei o metodo pushback para separar
    //as horas e os minutos
    string horas_str, minutos_str;
    horas_str.push_back(horario[0]);
    horas_str.push_back(horario[1]);
    minutos_str.push_back(horario[3]);
    minutos_str.push_back(horario[4]);

    //Mudando uma varivel de tipo string para int
    //para futuramente verificar se eh valido
    int horas = stoi(horas_str);
    int minutos = stoi(minutos_str);

    //Verifica se o horas eh valido
    if (horas > 23 || horas < 0){
        return false;
    }

    //Verifica se o minutos eh valido
    if (minutos > 59 || minutos < 0){
        return false;
    }

    return true;
}


bool Horario::setHorario(string horario){

    //verifica se eh valido e atribui o valor a class
    if (validarHorario(horario)){
        this->horario = horario;
        return true;
    }
    return false;

}


int main(){
    Horario *ptrHorario;
    ptrHorario = new Horario();

    if (ptrHorario->setHorario("11:30")){
        cout << "Horario = " << ptrHorario->getHorario() << endl;
    }
    else{
        cout << "Horario = Invalido" << endl;
    }


    if (ptrHorario->setHorario("11:90")){
        cout << "Horario = " << ptrHorario->getHorario() << endl;
    }
    else{
        cout << "Horario = Invalido" << endl;
    }

    return 0;
}
