#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

/*
  Esta funcao recebe o tamanho da colecao
  e salva a entrada dos inteiros digitados
  no terminal no endereco de memoria indicado
  
  Função recebe o tamanho do array ou matriz
  e se encarrega de salvar estes itens no 
  endereço de memoria indicado
*/
#ifndef PEDIRVALORES
#define PEDIRVALORES

extern void PedirValores(int *array, int tam_array)
{
  int ProxValor;

  for (int i = 0; i  < tam_array; i++)
  {
    cout << "Digite o valor " << i << " : ";
    
	cin >> ProxValor;

	*(array + i) = ProxValor;
    
  }
};

#endif
