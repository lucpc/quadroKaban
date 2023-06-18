#include <iostream>
#include <vector>

using namespace std;

template <typename T>
void buscaSequencial(vector<T>& v, T& x){
    int i;
    for(i = 0; i < v.size(); i++){
        if(v[i] == x){
            cout << "Elemento encontrado na posicao " << i << endl;
            return;
        }
    }
    cout << "Elemento nao encontrado" << endl;
}

template <typename T>
void buscaBinaria(vector<T>& v, T& x){
    int inicio = 0;
    int fim = v.size() - 1;
    int meio;
    while(inicio <= fim){
        meio = (inicio + fim) / 2;
        if(v[meio] == x){
            cout << "Elemento encontrado na posicao " << meio << endl;
            return;
        }
        else if(v[meio] < x){
            inicio = meio + 1;
        }
        else{
            fim = meio - 1;
        }
    }
    cout << "Elemento nao encontrado" << endl;
    }
}
