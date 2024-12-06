#ifndef VIAGEM_H
#define VIAGEM_H

#include "../../dominios/codigo/codigo.h"
#include "../../dominios/nome/nome.h"
#include "../../dominios/avaliacao/avaliacao.hpp"

class Viagem {
private:
    Codigo codigo;
    Nome nome;
    Avaliacao avaliacao;

public:
    // Construtor padrão e parametrizado
    Viagem() = default;
    Viagem(const Codigo &codigo, const Nome &nome, const Avaliacao &avaliacao);

    // Métodos getters
    Codigo getCodigo() const;
    Nome getNome() const;
    Avaliacao getAvaliacao() const;

    // Métodos setters
    void setCodigo(const Codigo &codigo);
    void setNome(const Nome &nome);
    void setAvaliacao(const Avaliacao &avaliacao);
};

#endif // VIAGEM_H
