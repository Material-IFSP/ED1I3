#include <iostream>
#include <stdlib.h>

using namespace std;

#include "./lib/Stack.h"
#include "./lib/ServicoPilha.h"


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
      if (VerifPar(newValor))
      {
        servicoPilha.push(StackPar, newValor);
        OrdemEntr[QuantInserida] = 0;
      }
      else
      {
        servicoPilha.push(StackImpar, newValor);
        OrdemEntr[QuantInserida] = 1;
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

    if (ValorAtualPar)
    {
      cout << servicoPilha.pop(StackPar) << endl;
    }
    else
    {
      cout << servicoPilha.pop(StackImpar) << endl;
    }
  }

  return 0;
}
