#ifndef QUADROKABAN_H
#define QUADROKABAN_H
#include <vector>
#include "tarefa.h"


class quadroKaban{
    public:
    quadroKaban();
    ~quadroKaban();
    void inserirTarefa(tarefa t);
    bool removerTarefa(vector<tarefa> &v, tarefa t);
    void atualizarTarefa(tarefa t);
    void statusTarefa(tarefa t);
    void statusGeral(void);

    //inserir metodos para adicionar, mover e remover tarefas das colunas

    private:
    vector<tarefa> tarefas;
    vector<tarefa> tarefasConcluidas;
    vector<tarefa> tarefasEmAndamento;
};

#endif // !QUADROKABAN_H
