#include "viagem.h"

// Construtor parametrizado
Viagem::Viagem(const Codigo &codigo, const Nome &nome, const Avaliacao &avaliacao)
    : codigo(codigo), nome(nome), avaliacao(avaliacao) {}

// Getters
Codigo Viagem::getCodigo() const {
    return codigo;
}

Nome Viagem::getNome() const {
    return nome;
}

Avaliacao Viagem::getAvaliacao() const {
    return avaliacao;
}

// Setters
void Viagem::setCodigo(const Codigo &codigo) {
    this->codigo = codigo; // Usa construtor de cópia do domínio
}

void Viagem::setNome(const Nome &nome) {
    this->nome = nome; // Usa construtor de cópia do domínio
}

void Viagem::setAvaliacao(const Avaliacao &avaliacao) {
    this->avaliacao = avaliacao; // Usa construtor de cópia do domínio
}
