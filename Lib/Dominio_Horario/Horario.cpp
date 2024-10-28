#include <iostream>
#include <string>
#include <typeinfo>
#include <cctype>
#include "Horario.hpp"

using namespace std;

bool Horario::validar_horario(string horario){

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


bool Horario::set_horario(string horario){

    //verifica se eh valido e atribui o valor a class
    if (validar_horario(horario)){
        this->horario = horario;
        return true;
    }
    return false;

}

int main(){
    Horario *ptr;
    ptr = new Horario();

    if (ptr->set_horario("11:30")){
        cout << "Horário = " << ptr->get_horario() << endl;
    }
    else{
        cout << "Horário = Invalido" << endl;
    }


    if (ptr->set_horario("11:90")){
        cout << "Horário = " << ptr->get_horario() << endl;
    }
    else{
        cout << "Horário = Invalido" << endl;
    }

    return 0;
}
