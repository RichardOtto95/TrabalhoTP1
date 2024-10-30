#include "dominio.hpp"
using namespace std;

bool Nome::validar(string valor){
    if (valor.size()>30){
        return false;
    }
    return true;

}

bool Nome::setValor(string valor){
    if(!validar(valor))
        return false;
    this->valor=valor;
    return true;


}
