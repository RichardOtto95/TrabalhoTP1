//Michele Nakagomi Lebarbenchon - 232029078

#include <iostream>
#include "destino.h"
#include "../../dominios/codigo/codigo.h"
#include "../../dominios/nome/nome.h"
#include "../../dominios/data/data.h"     
#include "../../dominios/avaliacao/avaliacao.hpp" 

int main() {
    Destino destino;
    Codigo codigo;
    Nome nome;
    Data dataInicio("01-06-2024");  // Inicialização com string no formato DD-MM-AAAA
    Data dataTermino("10-06-2024"); 
    Avaliacao avaliacao;

    // Configurar valores para os domínios
    codigo.setValor("D123");
    nome.setValor("Berlim");
    avaliacao.setValor("5");

    // Configurar a entidade com os valores de domínio
    destino.setCodigo(codigo);
    destino.setNome(nome);
    destino.setDataInicio(dataInicio);
    destino.setDataTermino(dataTermino);
    destino.setAvaliacao(avaliacao);

    // Exibir os valores configurados
    std::cout << "Destino: " << destino.getNome().getValor() << std::endl;
    std::cout << "Código da viagem: " << destino.getCodigo().getValor() << std::endl;
    std::cout << "Data de Início: " 
              << destino.getDataInicio().getDia() << "-" 
              << destino.getDataInicio().getMes() << "-" 
              << destino.getDataInicio().getAno() << std::endl;
    std::cout << "Data de Término: " 
              << destino.getDataTermino().getDia() << "-" 
              << destino.getDataTermino().getMes() << "-" 
              << destino.getDataTermino().getAno() << std::endl;
    std::cout << "Avaliação: " << destino.getAvaliacao().getValor() << std::endl;

    return 0;
}
