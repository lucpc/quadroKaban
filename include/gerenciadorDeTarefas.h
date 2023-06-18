#ifndef GERENCIADORDETAREFAS_H
#define GERENCIADORDETAREFAS_H
#include "quadroKanban.h"

class gerenciadorDeTarefas{
    public:
        TaskManager();
        ~TaskManager();
        //inserir metodos para adicionar, mover e remover tarefas das colunas
        //metodos para classificar as tarefas usando algoritmos de ordenação

    private:
        quadroKanban quadro;
        


};

#endif // GERENCIADORDETAREFAS_H


