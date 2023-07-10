#ifndef TAREFA_H
#define TAREFA_H
#include <string>

using namespace std;

class tarefa{
    public:

        tarefa(){};
        tarefa(const string& nome, const string& descricao, const string& data, const string& hora, int prioridade);
        ~tarefa();
        void setNome(string n);
        string getNome(void);
        void setDescricao(string desc);
        string getDescricao(void);
        void setData(string dt);
        string getData(void);
        void setHora(string hr);
        string getHora(void);
        void setSituacao(string sit);
        string getSituacao(void);
        void setPrioridade(int prio);
        int getPrioridade(void);

    private:
        string nome;
        string descricao;
        string data;
        string hora;
        string situacao;
        int prioridade;


};





#endif // TAREFA_H
