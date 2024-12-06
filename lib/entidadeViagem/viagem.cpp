#include "viagem.h"

// Construtor parametrizado
Viagem::Viagem(const Codigo &codigo, const Nome &nome, const Avaliacao &avaliacao)
    : codigo(codigo), nome(nome), avaliacao(avaliacao) {}
    // Inicializa os atributos `codigo`, `nome` e `avaliacao` com os valores fornecidos.
    // Usa inicialização direta através do construtor de cópia dos respectivos domínios.

// Getters
Codigo Viagem::getCodigo() const {
    return codigo; // Retorna uma cópia do atributo `codigo`.
}

Nome Viagem::getNome() const {
    return nome; // Retorna uma cópia do atributo `nome`.
}

Avaliacao Viagem::getAvaliacao() const {
    return avaliacao; // Retorna uma cópia do atributo `avaliacao`.
}

// Setters
void Viagem::setCodigo(const Codigo &codigo) {
    this->codigo = codigo; // Atualiza o atributo `codigo` com o valor fornecido.
    // Utiliza o operador de atribuição ou construtor de cópia do domínio `Codigo`.
}

void Viagem::setNome(const Nome &nome) {
    this->nome = nome; // Atualiza o atributo `nome` com o valor fornecido.
    // Utiliza o operador de atribuição ou construtor de cópia do domínio `Nome`.
}

void Viagem::setAvaliacao(const Avaliacao &avaliacao) {
    this->avaliacao = avaliacao; // Atualiza o atributo `avaliacao` com o valor fornecido.
    // Utiliza o operador de atribuição ou construtor de cópia do domínio `Avaliacao`.
}
