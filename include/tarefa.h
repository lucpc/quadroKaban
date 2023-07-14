#ifndef TAREFA_H
#define TAREFA_H
#include <string>

using namespace std;

class tarefa{
    public:

        /** construtores da classe tarefa
         *
         *construtor padrão da classe tarefa
         */
        tarefa(){};
        /**
         * construtor parametrizado da classe tarefa
         * @param nome nome da tarefa
         * @param descricao descrição da tarefa
         * @param data data da tarefa
         * @param hora hora da tarefa
         * @param prioridade prioridade da tarefa
         */
        tarefa(const string& nome, const string& descricao, const string& data, const string& hora, int prioridade);

        /**
         *destrutor padrão da classe tarefa
         */
        ~tarefa();
        /**
         *método que retorna o nome da tarefa
         */
        void setNome(string n);
        /**
         *método que recebe o nome da tarefa 
         *return string
         */
        string getNome(void);
        /**
         *método que retorna a descrição da tarefa
         */
        void setDescricao(string desc);
        /**
         *método que recebe a descrição da tarefa 
         *return string
         */
        string getDescricao(void);
        /**
         *método que retorna a data da tarefa
         */
        void setData(string dt);
        /**
         *método que recebe a data da tarefa 
         *return string
         */
        string getData(void);
        /**
         *método que retorna a hora da tarefa
         */
        void setHora(string hr);
        /**
         *método que recebe a hora da tarefa 
         *return string
         */
        string getHora(void);
        /**
         *método que retorna a situação da tarefa
         */
        void setSituacao(string sit);
        /**
         *método que recebe a situação da tarefa 
         *return string
         */
        string getSituacao(void);
        /**
         *método que retorna a prioridade da tarefa
         */
        void setPrioridade(int prio);
        /**
         *método que recebe a prioridade da tarefa 
         *return int
         */
        int getPrioridade(void);
        /*!
          método que retorna a prioridade da tarefa
        */
        bool operator==(tarefa);
        /*
          método overloading que compara se uma tarefa é igual a outra
        */

    private:
        /**
         *atributos da classe tarefa
         */
        string nome;
        string descricao;
        string data;
        string hora;
        string situacao;
        int prioridade;


};





#endif // TAREFA_H
