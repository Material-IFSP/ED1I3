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

    newStack->top = NULL;

    return newStack;
  }

  bool isEmpty(Stack *stack)
  {
    return (stack->top == NULL);
  }

  void push(Stack *stackOriginal, int newData)
  {
    Node *newNode = new Node;

    newNode->data = newData;
    newNode->next = stackOriginal->top;

    stackOriginal->top = newNode;
  }

  int pop(Stack *stackOriginal)
  {
    int removeData;

    Node *NodeToRemove = stackOriginal->top;

    removeData = NodeToRemove->data;

    stackOriginal->top = NodeToRemove->next;

    free(NodeToRemove);

    return removeData;
  }

  void print(Stack *stack)
  {
   	   Node *AtualNode;

    AtualNode = stack->top;

    while (AtualNode != NULL)
    {
      cout << AtualNode->data << endl;
      AtualNode = AtualNode->next;
    }

    cout << "------------------------" << endl;
  }

  int count(Stack *stack)
  {
    int quantidadeStack = 0;

    Node *AtualNode;

    AtualNode = stack->top;

    while (AtualNode != NULL)
    {
      quantidadeStack++;
      AtualNode = AtualNode->next;
    }

    return quantidadeStack;
  }

  void freeStack(Stack *stack)
  {
    Node *AtualNode = stack->top;

    while (AtualNode != NULL)
    {
      Node *temporarioNode = AtualNode->next;

      free(AtualNode);

      AtualNode = temporarioNode;
    }

    free(stack);
  }
};

#endif
