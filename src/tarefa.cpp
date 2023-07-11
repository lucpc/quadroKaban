#include <iostream>
#include <string>
#include "../include/tarefa.h"

tarefa::tarefa(const std::string& nome, const std::string& descricao, const std::string& data, const std::string& hora, int prioridade){
    setNome(nome);
    setDescricao(descricao);
    setData(data);
    setHora(hora);
    setPrioridade(prioridade);
    setSituacao("Em andamento");
}

tarefa::~tarefa(){};

void tarefa::setNome(std::string n){
    nome = n;
}
std::string tarefa::getNome(void){
    return nome;
}

void tarefa::setDescricao(std::string desc){
    descricao = desc;
}
std::string tarefa::getDescricao(void){
    return descricao;
}

void tarefa::setData(std::string dt){
    data = dt;
}
std::string tarefa::getData(void){
    return data;
}

void tarefa::setHora(std::string hr){
    hora = hr;
}
std::string tarefa::getHora(void){
    return hora;
}

void tarefa::setSituacao(std::string sit){
    situacao = sit;
}
std::string tarefa::getSituacao(void){
    return situacao;
}

void tarefa::setPrioridade(int prio){
    prioridade = prio;
}
int tarefa::getPrioridade(void){
    return prioridade;
}

bool tarefa::operator==(tarefa t){
    if (getNome() != t.nome){return false;}
    if (getDescricao() != t.descricao){return false;}
    if (getData() != t.data){return false;}
    if (getHora() != t.hora){return false;}
    if (getPrioridade() != t.prioridade){return false;}

    return true;
}


