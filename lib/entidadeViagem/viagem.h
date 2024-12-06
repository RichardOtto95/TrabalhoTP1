#ifndef VIAGEM_H // - Arthus César Dias Fernandes - 231006103
#define VIAGEM_H

#include "../../dominios/codigo/codigo.h"        // Inclui o domínio que representa um código.
#include "../../dominios/nome/nome.h"            // Inclui o domínio que representa um nome.
#include "../../dominios/avaliacao/avaliacao.hpp" // Inclui o domínio que representa uma avaliação.

/// Classe que representa uma entidade de Viagem.
/// Contém três atributos principais: código, nome e avaliação.
/// Utiliza os domínios `Codigo`, `Nome` e `Avaliacao` para garantir consistência e validação de dados.
class Viagem {
private:
    Codigo codigo;        // Código associado à viagem, gerido pela classe `Codigo`.
    Nome nome;            // Nome associado à viagem, gerido pela classe `Nome`.
    Avaliacao avaliacao;  // Avaliação associada à viagem, gerida pela classe `Avaliacao`.

public:
    // Construtor padrão e parametrizado.
    Viagem() = default;  // Construtor padrão: inicializa um objeto vazio.
    Viagem(const Codigo &codigo, const Nome &nome, const Avaliacao &avaliacao);
    // Construtor parametrizado: inicializa um objeto com valores específicos para código, nome e avaliação.

    // Métodos getters.
    Codigo getCodigo() const;         // Retorna o código da viagem.
    Nome getNome() const;             // Retorna o nome da viagem.
    Avaliacao getAvaliacao() const;   // Retorna a avaliação da viagem.

    // Métodos setters.
    void setCodigo(const Codigo &codigo);         // Define ou atualiza o código da viagem.
    void setNome(const Nome &nome);               // Define ou atualiza o nome da viagem.
    void setAvaliacao(const Avaliacao &avaliacao); // Define ou atualiza a avaliação da viagem.
};

#endif // VIAGEM_H
