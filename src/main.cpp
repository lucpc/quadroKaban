#include <iostream>

#include "../include/tarefa.h"
#include "../include/quadroKaban.h"

int main(void){
    quadroKaban *quadro = new quadroKaban;
    tarefa tarefa_inserir, tarefa_remover, tarefa_atualizar;
    
    int escolha = 0;

    std::string nome_tarefa, descricao, data, hora, situacao;
    int prioridade;

    std::cout << "------Quadro Kaban------" << std::endl;
    
    while (escolha != 5){
        std::cout << "[1] Visualizar quadro" << std::endl;
        std::cout << "[2] Inserir tarefa" << std::endl;
        std::cout << "[3] Remover tarefa" << std::endl;
        std::cout << "[4] Atualizar tarefa" << std::endl;
        std::cout << "[5] Sair do programa" << std::endl;

        std::cout << "Opção: ";
        std::cin >> escolha;

        switch (escolha){
            case 1:
                quadro->statusGeral();
                break;

            case 2:
                std::cout << "Nome da tarefa: ";
                std::cin >> nome_tarefa;
                std::cout << "\nBreve descrição: ";
                std::cin >> descricao;
                std::cout << "\nData da tarefa: ";
                std::cin >> data;
                std::cout << "\nHora da tarefa: ";
                std::cin >> hora;
                std::cout << "\nPrioridade da tarefa: ";
                std::cin >> prioridade;
                tarefa_inserir = tarefa(nome_tarefa, descricao, data, hora, prioridade);
                quadro->inserirTarefa(tarefa_inserir);
                break;
        
            case 3:
                quadro->mostrarTarefas();
                while (true){
                    std::cout << "Indique pelo número qual tarefa que deseja excluir: ";
                    std::cin >> escolha;
                    if (escolha >= quadro->getQuatidade() || escolha < 0){
                        std::cout << "Opção inválida!" << std::endl;
                    } else{
                        break;
                    }
                }
                tarefa_remover = quadro->getTarefa(escolha);
                quadro->removerTarefa(tarefa_remover);
                break;
            case 4:
                quadro->mostrarTarefas();
                while (true){
                    std::cout << "Indique pelo número qual tarefa que deseja atualizar: ";
                    std::cin >> escolha;
                    if (escolha >= quadro->getQuatidade() || escolha < 0){
                        std::cout << "Opção inválida!" << std::endl;
                    } else{
                        break;
                    }
                }
                tarefa_atualizar = quadro->getTarefa(escolha);   
                quadro->atualizarTarefa(tarefa_atualizar);
                break;
            
            default:
                break;
        }
    }
    return 0;
}