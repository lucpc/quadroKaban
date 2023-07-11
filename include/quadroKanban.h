#ifndef QUADROKANBAN_H
#define QUADROKANBAN_H
#include <vector>
#include "tarefa.h"

using namespace std;


class quadroKanban{
    public:
    quadroKanban();
    ~quadroKanban();
    tarefa getTarefa(int index);
    int getQuatidade(void);
    void inserirTarefa(tarefa t);
    bool removerTarefa(tarefa t);
    bool atualizarTarefa(tarefa t);
    void mostrarTarefas(void);
    void statusTarefa(tarefa t);
    void statusGeral(void);

    //inserir metodos para adicionar, mover e remover tarefas das colunas


    private:
    vector<tarefa> tarefas;
    vector<tarefa> tarefasConcluidas;
    vector<tarefa> tarefasEmAndamento;

};

#endif // !QUADROKANBAN_H
