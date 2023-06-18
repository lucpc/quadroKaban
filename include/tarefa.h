#ifndef TAREFA_H
#define TAREFA_H
#include <string>

using namespace std;

class tarefa{
    public:

        tarefa(const string& nome, const string& descricao, const string& data, 
                const string& hora,int prioridade);
        ~tarefa();
    private:
        string nome
        string descricao;
        string data;
        string hora;
        int prioridade;


};





#endif // TAREFA_H
