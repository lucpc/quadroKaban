#include <iostream>
#include <string>
#include "../include/quadroKaban.h"
#include "../include/buscas.h"
#include "buscas.cpp"

quadroKaban::quadroKaban(){};

quadroKaban::~quadroKaban(){
    tarefas.clear();
    tarefasEmAndamento.clear();
    tarefasConcluidas.clear();
};

tarefa quadroKaban::getTarefa(int index){
    return tarefas[index];
}

int quadroKaban::getQuatidade(void){
    return tarefas.size();
}

void quadroKaban::inserirTarefa(tarefa t){
    tarefas.push_back(t);
    tarefasEmAndamento.push_back(t);
}

bool quadroKaban::removerTarefa(tarefa t){
    int index = buscaSequencial(tarefas, t);
    if (index >= 0){
        int s;
        if (tarefas[index].getSituacao() == "Em andamento"){
            s = buscaSequencial(tarefasEmAndamento, t);
        } else{
            s = buscaSequencial(tarefasConcluidas, t);
        }
        tarefas.erase(tarefas.begin()+index);
        return true;
    }
    return false;
}

bool quadroKaban::atualizarTarefa(tarefa t){
    int index = buscaSequencial(tarefasEmAndamento, t);
    if (index >= 0){
        t.setSituacao("Concluída");
        tarefasEmAndamento.erase(tarefasEmAndamento.begin()+index);
        tarefasConcluidas.push_back(t);
        return true;
    }
    return false;
    
}

void quadroKaban::mostrarTarefas(void){
    if (!tarefas.size()){
        std::cout << "\nSem tarefas no momento" << std::endl;
        return;
    }
    std::cout << std::endl;
    for (std::size_t i = 0; i < tarefas.size(); ++i){
        std::cout << "[" << i << "]" << tarefas[i].getNome() << std::endl;
    }
    std::cout << std::endl;
}

void quadroKaban::statusTarefa(tarefa t){
    buscaSequencial(tarefas, t);
    std::cout << "Tarefa: " << t.getNome() << std::endl;
    std::cout << "Descrição" << std::endl << t.getDescricao() << std::endl;
    std::cout << "Data: " << t.getData() << std::endl;
    std::cout << "Hora: " << t.getHora() << std::endl;
    std::cout << "Prioridade: " << t.getPrioridade() << std::endl;
    std::cout << "Situação: " << t.getSituacao() << std::endl;
}

void quadroKaban::statusGeral(void){
    if (getQuatidade() <= 0){
        std::cout << "\nQuadro vazio!" << std::endl;
        return;
    }
    std::cout << "\n================================\n" << std::endl;
    for (std::size_t i = 0; i < tarefas.size(); ++i){
        statusTarefa(tarefas[i]);
        std::cout << std::endl;
    }
    std::cout << "================================" << std::endl;
}