#ifndef QUADROKANBAN_H
#define QUADROKANBAN_H
#include <vector>
#include "tarefa.h"

using namespace std;

//! classe que representa um quadro kanban
/*!
  conjunto de métodos e atributos que representam a estrutura de um quadro kanban
 */

class quadroKanban{
    public:

    /*!
      construtor padrão da classe quadroKanban
     */
    quadroKanban();
    /*!
      destrutor padrão da classe quadroKanban
     */
    ~quadroKanban();
    /*!
      método que retorna uma tarefa do quadro
      \param index indice da tarefa a ser retornada
      \return tarefa
     */
    tarefa getTarefa(int index);
    /*!
      método que retorna a quantidade de tarefas do quadro
      \return int
     */
    int getQuatidade(void);
    /*!
     metodo para inserir uma tarefa no quadro
    */
    void inserirTarefa(tarefa t);
    /*!
     metodo para remover uma tarefa do quadro
    */
    bool removerTarefa(tarefa t);
    /*!
     metodo para atualizar uma tarefa do quadro
    */
    bool atualizarTarefa(tarefa t);
    /*!
     metodo para mostrar as tarefas do quadro 
    */
    void mostrarTarefas(void);
    /*!
     metodo para mostrar as tarefas do quadro em andamento
    */
    void mostrarEmAndamento(void);
    /*!
     metodo para mostrar as tarefas do quadro concluidas
    */
    void mostrarConcluidas(void);
    /*!
     metodo para mostrar as tarefas do quadro por status
    */
    void statusTarefa(tarefa t);
    /*!
     metodo para mostrar as tarefas do quadro por status
    */
    void statusGeral(void);



    private:

    /*!
     vetor de tarefas do quadro
    */
    vector<tarefa> tarefas;
    /*!
     vetor de tarefas concluidas do quadro
    */
    vector<tarefa> tarefasConcluidas;
    /*!
     vetor de tarefas em andamento do quadro
    */
    vector<tarefa> tarefasEmAndamento;

};

#endif // !QUADROKANBAN_H
