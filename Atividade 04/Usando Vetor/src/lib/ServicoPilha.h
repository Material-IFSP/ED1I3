#include <iostream>
using namespace std;

#include "Stack.h"

#ifndef SERVICOPILHA_H
#define SERVICOPILHA_H

class ServicoPilha
{
public:
  Stack *init()
  {
    Stack *newStack = new Stack;

    newStack->quantidade = 0;

    return newStack;
  }

  bool isEmpty(Stack *stack)
  {
    return (stack->quantidade == 0);
  }

  bool push(Stack *stack, int valor, int maximo)
  {
    bool allowStack = stack->quantidade < maximo; // canStack

    if (allowStack)
    {
      stack->node[stack->quantidade] = valor;
      stack->quantidade++;
    }

    return allowStack;
  }

  int pop(Stack *stack, bool &ValorFoiDesempilhado) //itHasBeenUnstacked
  {
    int ValorDesempilhado = 0;

    bool allowUnstack = stack->quantidade > 0;

    if (allowUnstack)
    {
      int UltimoIndexValor = stack->quantidade - 1;

      ValorDesempilhado = stack->node[UltimoIndexValor];

      stack->quantidade--;
    }

    ValorFoiDesempilhado = allowUnstack;

    return ValorDesempilhado;
  }

  void print(Stack *stack)
  {
    for (int i = stack->quantidade - 1; i >= 0; --i)
    {
      cout << stack->node[i] << endl;
    }
  }

  int count(Stack *stack)
  {
    return stack->quantidade;
  }

  void freeStack(Stack *stack)
  {
    free(stack);
  }
};

#endif
