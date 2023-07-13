#include <iostream>
#include <string>
#include <fstream>
#include "../include/quadroKanban.h"
#include "../include/buscas.h"
#include "buscas.cpp"

quadroKanban::quadroKanban(){};

quadroKanban::~quadroKanban(){
    tarefas.clear();
    tarefasEmAndamento.clear();
    tarefasConcluidas.clear();
};

tarefa quadroKanban::getTarefa(int index){
    return tarefas[index];
}

int quadroKanban::getQuatidade(void){
    return tarefas.size();
}

void quadroKanban::inserirTarefa(tarefa t){
    tarefas.push_back(t);
    tarefasEmAndamento.push_back(t);
}

bool quadroKanban::removerTarefa(tarefa t){
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

bool quadroKanban::atualizarTarefa(tarefa t){
    int index = buscaSequencial(tarefasEmAndamento, t);
    if (index >= 0){
        t.setSituacao("Concluída");
        tarefasEmAndamento.erase(tarefasEmAndamento.begin()+index);
        tarefasConcluidas.push_back(t);
        return true;
    }
    return false;
    
}

void quadroKanban::mostrarTarefas(void){
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

void quadroKanban::mostrarEmAndamento(void){
    if (!tarefasEmAndamento.size()){
        std::cout << "\nNenhuma tarefa em andamento" << std::endl;
        return;
    }
    std::cout << std::endl;
    for (std::size_t i = 0; i < tarefasEmAndamento.size(); ++i){
        std::cout << "[" << i << "]" << tarefasEmAndamento[i].getNome() << std::endl;
    }
}

void quadroKanban::mostrarConcluidas(void){
    if (!tarefasConcluidas.size()){
        std::cout << "\nNenhuma tarefa concluída" << std::endl;
        return;
    }
    std::cout << std::endl;
    for (std::size_t i = 0; i < tarefasConcluidas.size(); ++i){
        std::cout << "[" << i << "]" << tarefasConcluidas[i].getNome() << std::endl;
    }
}

void quadroKanban::statusTarefa(tarefa t){
    buscaSequencial(tarefas, t);
    std::cout << "Tarefa: " << t.getNome() << std::endl;
    std::cout << "Descrição:" << std::endl << t.getDescricao() << std::endl;
    std::cout << "Data: " << t.getData() << std::endl;
    std::cout << "Hora: " << t.getHora() << std::endl;
    std::cout << "Prioridade: " << t.getPrioridade() << std::endl;
    std::cout << "Situação: " << t.getSituacao() << std::endl;
}

void quadroKanban::statusGeral(void){
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

void quadroKanban::salvarQuadro(void){
    std::ofstream arquivo;
    arquivo.open("../data/quadroKanban.bin", std::ios::binary);
    if (!arquivo.is_open()){
        std::cout << "Erro ao abrir arquivo" << std::endl;
        return;
    }
    for (std::size_t i = 0; i < tarefas.size(); ++i){
        arquivo.write((char*)&tarefas[i], sizeof(tarefa));
    }
    arquivo.close();
}

void quadroKanban::carregarQuadro(void){
    std::ifstream arquivo;
    arquivo.open("../data/quadroKanban.bin", std::ios::binary);
    if (!arquivo.is_open()){
        std::cout << "Erro ao abrir arquivo" << std::endl;
        return;
    }
    tarefa t;
    while (arquivo.read((char*)&t, sizeof(tarefa))){
        tarefas.push_back(t);
        if (t.getSituacao() == "Em andamento"){
            tarefasEmAndamento.push_back(t);
        } else{
            tarefasConcluidas.push_back(t);
        }
    }
    arquivo.close();
}
