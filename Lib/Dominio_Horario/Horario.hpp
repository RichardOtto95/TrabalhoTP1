#ifndef HORARIO_HPP_INCLUDED
#define HORARIO_HPP_INCLUDED

using namespace std;

class Horario{
private:
    string horario;
    bool validar_horario(string horario);

public:
    string get_horario(){return horario;}
    bool set_horario(string horario);

};

#endif // HORARIO_HPP_INCLUDED
