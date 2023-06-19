#include <vector>
#include <iostream>
#include "../include/ordenacao.h"

using namespace std;

template <typename T>
void bubbleSort(vector<T>& v){
    int i, j;
    T aux;
    for(i = 0; i < v.size(); i++){
        for(j = 0; j < v.size() - 1; j++){
            if(v[j] > v[j + 1]){
                aux = v[j];
                v[j] = v[j + 1];
                v[j + 1] = aux;
            }
        }
    }
}




