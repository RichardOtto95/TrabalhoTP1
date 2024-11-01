#include "dominio.hpp"
#include <iostream>
using namespace std;

bool Nome::validar(string nome){
    if (nome.size()>30){
        return false;
    }
    return true;

}

bool Nome::setNome(string nome){
    if(!validar(nome))
        return false;
    this->nome=nome;
    return true;


}

void TUNome::run() {
    Nome nome;

    if (nome.setNome("Michele")) {
        cout << "Teste com valor válido passou." << endl;
    } else {
        cout << "Teste com valor válido falhou." << endl;
    }

    if (!nome.setNome("Michelenakagomilebarbenchonsilvacosta")) {
        cout << "Teste com valor inválido passou." << endl;
    } else {
        cout << "Teste com valor inválido falhou." << endl;
    }
}

int main() {
    TUNome testeNome;
    testeNome.run();
    return 0;
}
