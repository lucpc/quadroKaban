#ifndef QUADROKABAN_H
#define QUADROKABAN_H
#include <vector>
#include "tarefa.h"


class quadroKanban{
    public:
    quadroKanban();
    ~quadroKanban();
    //inserir metodos para adicionar, mover e remover tarefas das colunas


    private:
    vector<tarefa> tarefas;
    vector<tarefa> tarefasConcluidas;
    vector<tarefa> tarefasEmAndamento;
};

#endif // !QUADROKABAN_H
