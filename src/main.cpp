#include <iostream>
#include <string>
#include <vector>
#include "../include/tarefa.h"
#include "../include/quadroKanban.h"
#include <limits>


int main(void){
    quadroKanban *quadro = new quadroKanban;
    tarefa tarefa_inserir, tarefa_remover, tarefa_atualizar;
    
    int escolha = 0;

    std::string nome_tarefa, descricao, line, data, hora, situacao;
    int prioridade;

    std::cout << "------Quadro Kanban------" << std::endl;
    
    while (escolha >= 0){
        std::cout << "\n[1] Visualizar quadro" << std::endl;
        std::cout << "[2] Visualizar tarefas em andamento" << std::endl;
        std::cout << "[3] Visualizar tarefas concluídas" << std::endl;
        std::cout << "[4] Inserir tarefa" << std::endl;
        std::cout << "[5] Remover tarefa" << std::endl;
        std::cout << "[6] Atualizar tarefa" << std::endl;
        std::cout << "\n[-1] Sair do programa\n" << std::endl;

        std::cout << "Opção: ";
        std::cin >> escolha;

        switch (escolha){
            case 1:
                quadro->statusGeral();
                break;
            
            case 2:
                quadro->mostrarEmAndamento();
                break;
            
            case 3:
                quadro->mostrarConcluidas();
                break;

            case 4:
                std::cout << "\nDigite -1 para cancelar\n" << std::endl;
                std::cout << "Nome da tarefa: ";
                std::cin >> nome_tarefa;
                if (nome_tarefa == "-1"){
                    std::cout << "\nOperação cancelada!" << std::endl;
                    break;
                }
                std::cout << "Breve descrição: ";
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::getline(std::cin, descricao);                
                if (descricao == "-1"){
                    std::cout << "\nOperação cancelada!" << std::endl;
                    break;
                }
                std::cout << "Data da tarefa: ";
                std::cin >> data;
                if (data == "-1"){
                    std::cout << "\nOperação cancelada!" << std::endl;
                    break;
                }
                std::cout << "Hora da tarefa: ";
                std::cin >> hora;
                if (hora == "-1"){
                    std::cout << "\nOperação cancelada!" << std::endl;
                    break;
                }
                std::cout << "Prioridade da tarefa: ";
                std::cin >> prioridade;
                if (prioridade == -1){
                    std::cout << "\nOperação cancelada!" << std::endl;
                    break;
                }

                tarefa_inserir = tarefa(nome_tarefa, descricao, data, hora, prioridade);
                quadro->inserirTarefa(tarefa_inserir);
                break;
        
            case 5:
                quadro->mostrarTarefas();
                if (quadro->getQuatidade() <= 0){
                    break;
                }
                std::cout << "Digite -1 para cancelar\n" << std::endl;
                std::cout << "Indique pelo número qual tarefa que deseja excluir: ";
                while (true){
                    std::cin >> escolha;
                    if (escolha == -1){
                        std::cout << "\nOperação cancelada" << std::endl;
                        break;
                    }else if (escolha >= quadro->getQuatidade() || escolha < -1){
                        std::cout << "Opção inválida!" << std::endl;
                    }else{
                        break;
                    }
                }
                if (escolha == -1){break;}
                tarefa_remover = quadro->getTarefa(escolha);
                quadro->removerTarefa(tarefa_remover);
                std::cout << "\nTarefa " << tarefa_remover.getNome() << " removida!" << std::endl;
                break;
            case 6:
                quadro->mostrarTarefas();
                if (quadro->getQuatidade() <= 0){
                    break;
                }
                std::cout << "Digite -1 para cancelar\n" << std::endl;
                std::cout << "Indique pelo número qual tarefa que deseja atualizar: ";
                while (true){
                    std::cin >> escolha;
                    if (escolha == -1){
                        std::cout << "\nOperação cancelada!" << std::endl;
                        break;
                    }else if (escolha >= quadro->getQuatidade() || escolha < 0){
                        std::cout << "Opção inválida!" << std::endl;
                    }else{
                        break;
                    }
                }
                if (escolha == -1){break;}
                tarefa_atualizar = quadro->getTarefa(escolha);
                quadro->atualizarTarefa(tarefa_atualizar);
                break;
            
            default:
                break;
        }
    }
    return 0;
}
