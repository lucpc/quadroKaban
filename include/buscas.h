#ifndef BUSCAS_H
#define BUSCAS_H
#include <vector>

using namespace std;

/**
 * @brief template de busca sequencial
 * @param v
 * @param x
 * @return o índice do elemento buscado ou -1 caso não encontre
 */
template <typename T>
int buscaSequencial(vector<T>& v, T& x);

/**
 * @brief template de busca binária
 * @param v
 * @param x
 * @return o índice do elemento buscado 
 */
template <typename T>
void buscaBinaria(vector<T>& v, T& x);



#endif // BUSCAS_H
