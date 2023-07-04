#include <iostream>
#include "../include/quadroKaban.h"
#include "../include/buscas.h"

quadroKaban::quadroKaban(){};

quadroKaban::~quadroKaban(){
    tarefas.clear();
    tarefasEmAndamento.clear();
    tarefasConcluidas.clear();
};

void quadroKaban::inserirTarefa(tarefa t){
    tarefas.push_back(t);
    tarefasEmAndamento.push_back(t);
}

bool quadroKaban::removerTarefa(vector<tarefa> &v, tarefa t){
    int index = buscaSequencial(v, t);
    if (index >= 0){
        v.erase(v.begin()+index);
        return true;
    }
    return false;
}

void quadroKaban::atualizarTarefa(tarefa t){
    t.setSituacao("Concluída");
    removerTarefa(tarefasEmAndamento, t);
    tarefasConcluidas.push_back(t);
}

void quadroKaban::statusTarefa(tarefa t){
    buscaSequencial(tarefas, t);
    std::cout << "Tarefa " << t.getNome() << std::endl;
    std::cout << "Descrição" << std::endl << t.getDescricao() << std::endl;
    std::cout << "Data " << t.getData() << std::endl;
    std::cout << "Hora " << t.getHora() << std::endl;
    std::cout << "Prioridade " << t.getPrioridade() << std::endl;
    std::cout << "Situação " << t.getSituacao() << std::endl;
}

void quadroKaban::statusGeral(void){
    for (int i = 0; i < tarefas.size(); ++i){
        statusTarefa(tarefas[i]);
        std::cout << "============" << std::endl;
    }
}