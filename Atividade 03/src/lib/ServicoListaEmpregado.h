#include <iostream>
using namespace std;

#include "Empregado.h"

#ifndef LISTAEMPREGADO_H
#define LISTAEMPREGADO_H

struct ListaEmpregado
{
  Empregado data;
  struct ListaEmpregado *next;
};

class ServicoListaEmpregado
{
public:
  static ListaEmpregado *init()
  {
    return NULL;
  }

  static ListaEmpregado *insert(ListaEmpregado *empregado, Empregado newEmpregado)
  {
    ListaEmpregado *listaAuxiliar = new ListaEmpregado;

    listaAuxiliar->data = newEmpregado;
    listaAuxiliar->next = empregado;

    return listaAuxiliar;
  }

  static void print(ListaEmpregado *empregado, bool json = true)
  {
    double somaSalario = 0;
    ListaEmpregado *listaAuxiliar;

    listaAuxiliar = empregado;

    if (json)
    {
      cout << "[ " << endl;

      while (listaAuxiliar != NULL)
      {
        cout << "  {" << endl;
        cout << "    prontuario: " << listaAuxiliar->data.getProntuario() << "," << endl;
        cout << "    nome: " << listaAuxiliar->data.getNome() << "," << endl;
        cout << "    salario: " << listaAuxiliar->data.getSalario() << "," << endl;
        cout << "  }," << endl;

        listaAuxiliar = listaAuxiliar->next;
      }

      cout << " ]" << endl;
    }
    else
    {
      cout << "Listagem de funcionarios" << endl
           << endl;

      while (listaAuxiliar != NULL)
      {
        cout << "Prontuario: " << listaAuxiliar->data.getProntuario() << endl;
        cout << "Nome: " << listaAuxiliar->data.getNome() << endl;
        cout << "Salario: " << listaAuxiliar->data.getSalario() << endl;
        cout << endl;

        somaSalario += listaAuxiliar->data.getSalario();

        listaAuxiliar = listaAuxiliar->next;
      }
    }

    cout << "Somatoria dos salarios: " << somaSalario << endl
         << endl;

    cout << "------------------------ Fim \n " << endl;
  }

  static ListaEmpregado *find(ListaEmpregado *empregado, int prontuario, bool &empregadoFound)
  {
    ListaEmpregado *listaAuxiliar;

    listaAuxiliar = empregado;

    while (
        listaAuxiliar != NULL &&
        listaAuxiliar->data.getProntuario() != prontuario)
    {
      listaAuxiliar = listaAuxiliar->next;
    }

    empregadoFound = !(listaAuxiliar == NULL);

    return listaAuxiliar;
  }

  static ListaEmpregado *remove(ListaEmpregado *empregado, int prontuario, bool &empregadoDeleted)
  {
    ListaEmpregado
        *AntPointer = NULL,
        *listaAuxiliar;

    listaAuxiliar = empregado;

    while (
        listaAuxiliar != NULL &&
        listaAuxiliar->data.getProntuario() != prontuario)
    {
      AntPointer = listaAuxiliar;
      listaAuxiliar = listaAuxiliar->next;
    }

    if (listaAuxiliar == NULL) // nao encontrado
    {
      empregadoDeleted = false;
      return empregado;
    }

    if (AntPointer == NULL) // Era o primeiro item
    {
      empregado = listaAuxiliar->next;
    }
    else // Estava em qualquer outra posicao
    {
      AntPointer->next = listaAuxiliar->next;
    }

    free(listaAuxiliar);

    empregadoDeleted = true;

    return empregado;
  }
};

#endif
