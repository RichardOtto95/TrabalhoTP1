//Michele Nakagomi Lebarbenchon - 232029078

#ifndef DESTINO_H
#define DESTINO_H

#include "../../dominios/codigo/codigo.h"  
#include "../../dominios/nome/nome.h"     
#include "../../dominios/data/data.h"     
#include "../../dominios/avaliacao/avaliacao.hpp" 
#include <stdexcept>

using namespace std;

class Destino {
private:
    Codigo codigo;
    Nome nome;
    Data dataInicio;
    Data dataTermino;
    Avaliacao avaliacao;

public:
    void setCodigo(const Codigo &codigo);
    Codigo getCodigo() const;
    void setNome(const Nome &nome);
    Nome getNome() const;
    void setDataInicio(const Data &dataInicio);
    Data getDataInicio() const;
    void setDataTermino(const Data &dataTermino);
    Data getDataTermino() const;
    void setAvaliacao(const Avaliacao &avaliacao);
    Avaliacao getAvaliacao() const;
};

//codigo
inline void Destino::setCodigo(const Codigo &codigo) {
    this->codigo.setValor(codigo.getValor());
}

inline Codigo Destino::getCodigo() const {
    Codigo temp;
    temp.setValor(this->codigo.getValor());
    return temp;
}

//nome
inline void Destino::setNome(const Nome &nome) {
    this->nome.setValor(nome.getValor());
}

inline Nome Destino::getNome() const {
    Nome temp;
    temp.setValor(this->nome.getValor());
    return temp;
}

//data de inicio
inline void Destino::setDataInicio(const Data &dataInicio) {
    if (dataTermino.getDia() != 0 || dataTermino.getMes() != 0 || dataTermino.getAno() != 0) {
        if (dataInicio.getAno() > dataTermino.getAno() ||
            (dataInicio.getAno() == dataTermino.getAno() && dataInicio.getMes() > dataTermino.getMes()) ||
            (dataInicio.getAno() == dataTermino.getAno() && dataInicio.getMes() == dataTermino.getMes() && dataInicio.getDia() > dataTermino.getDia())) {
            throw std::invalid_argument("A data de início deve ser anterior ou igual à data de término.");
        }
    }
    this->dataInicio = dataInicio;
}

inline Data Destino::getDataInicio() const {
    return dataInicio;
}

//data termino
inline void Destino::setDataTermino(const Data &dataTermino) {
    if (dataInicio.getDia() != 0 || dataInicio.getMes() != 0 || dataInicio.getAno() != 0) {
        if (dataTermino.getAno() < dataInicio.getAno() ||
            (dataTermino.getAno() == dataInicio.getAno() && dataTermino.getMes() < dataInicio.getMes()) ||
            (dataTermino.getAno() == dataInicio.getAno() && dataTermino.getMes() == dataInicio.getMes() && dataTermino.getDia() < dataInicio.getDia())) {
            throw std::invalid_argument("A data de término deve ser posterior ou igual à data de início.");
        }
    }
    this->dataTermino = dataTermino;
}

inline Data Destino::getDataTermino() const {
    return dataTermino;
}


//avaliação
inline void Destino::setAvaliacao(const Avaliacao &avaliacao) {
    this->avaliacao = avaliacao;
}
inline Avaliacao Destino::getAvaliacao() const {
    return avaliacao;
}

#endif 
