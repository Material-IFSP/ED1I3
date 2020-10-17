#include <iostream>
using namespace std;

#include "./Fila.h"

#ifndef SERVICOFILA_H
#define SERVICOFILA_H

class ServicoFila
{
public:
  Fila *init()
  {
    Fila *newFila = new Fila;

    newFila->begin = NULL;
    newFila->end = NULL;

    return newFila;
  }

  bool verifVazio(Fila *fila)
  {
    return fila->begin == NULL;
  }

  void add(Fila *fila, bool usarSenha = false, int senha = 0)
  {
    Node *newNode = new Node;

    bool FilaEstaVazia = verifVazio(fila);

    if (FilaEstaVazia || usarSenha)
    {
      newNode->data = usarSenha ? senha : 1;
    }
    else
    {
      newNode->data = fila->end->data + 1;
    }

    newNode->next = NULL;

    if (FilaEstaVazia)
    {
      fila->begin = newNode;
    }
    else
    {
      fila->end->next = newNode;
    }

    fila->end = newNode;
  }

  
  int desenfileirar(Fila *fila)
  {
    int ItemRemovido;
    Node *PrimNode = fila->begin;

    ItemRemovido = PrimNode->data;

    fila->begin = PrimNode->next;

    if (fila->begin == NULL)
    {
      fila->end == NULL;
    }

    free(PrimNode);

    return ItemRemovido;
  }

 
  void print(Fila *fila)
  {
    Node *NodeAtual = fila->begin;

    while (NodeAtual != NULL)
    {
      cout << NodeAtual->data << endl;
      NodeAtual = NodeAtual->next;
    }

    cout << "---------------";
  }

  
  int count(Fila *fila)
  {
    int countItens = 0;

    Node *NodeAtual = fila->begin;

    while (NodeAtual != NULL)
    {
      countItens++;
      NodeAtual = NodeAtual->next;
    }

    return countItens;
  }

 
  void freeFila(Fila *fila)
  {
    Node *NodeAtual = fila->begin;

    while (NodeAtual != NULL)
    {
      Node *temporaryNode = NodeAtual->next;

      free(NodeAtual);
      NodeAtual = temporaryNode;
    }

    free(fila);
  }
};

#endif
