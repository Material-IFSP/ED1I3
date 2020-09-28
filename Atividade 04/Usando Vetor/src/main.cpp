#include <iostream>
#include <stdlib.h>

using namespace std;

#include "./lib/Stack.h"
#include "./lib/ServicoPilha.h"

#define MAX 30

bool VerifPar(int value)
{
  return value % 2 == 0;
}

int main(int argc, char **argv)
{
  int UltimoValorInserido = 0, QuantInserida = 0, QuantValores = 30;

  ServicoPilha servicoPilha = ServicoPilha();
  Stack *StackPar, *StackImpar;

  int *OrdemEntr = new int[QuantValores]; 
  

  StackPar = servicoPilha.init();
  StackImpar = servicoPilha.init();

  bool EntradaInvalida = false;

  while (QuantInserida < QuantValores)
  {
    int newValor;

    if (EntradaInvalida)
    {
      cout << "Favor Inserir um numero Maior" << endl
           << endl;
    }

    cout << "Digite o " << QuantInserida + 1 << "º valor: ";

    cin >> newValor;

    EntradaInvalida = newValor <= UltimoValorInserido;

    if (!EntradaInvalida)
    {
      bool pushValor = false;

      if (VerifPar(newValor))
      {
        pushValor = servicoPilha.push(StackPar, newValor, MAX);
        OrdemEntr[QuantInserida] = 0;
      }
      else
      {
        pushValor = servicoPilha.push(StackImpar, newValor, MAX);
        OrdemEntr[QuantInserida] = 1;
      }

      if (!pushValor)
      {
        cout << "Ocorreu um erro ao Desempilhar." << endl;
        exit(1);
      }

      UltimoValorInserido = newValor;
      QuantInserida++;
    }
  }

  cout << endl;

  // unstacking
  
  for (int i = 0; i < QuantValores; i++)
  {
    int IndexOrdem = QuantValores - (i + 1);

    bool ValorAtualPar = OrdemEntr[IndexOrdem] == 0;

    bool ValorfoiREMOVIDO = false;
    int valorRemovido = 0;

    valorRemovido = ValorAtualPar
      ? servicoPilha.pop(StackPar, ValorfoiREMOVIDO)
      : servicoPilha.pop(StackImpar, ValorfoiREMOVIDO);

    if (!ValorfoiREMOVIDO)
    {
      cout << "Acorreu um erro ao remover valor." << endl;
      exit(1);
    }

    cout << valorRemovido << endl;
  }

  return 0;
}
