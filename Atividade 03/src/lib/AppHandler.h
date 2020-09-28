#include <iostream>
using namespace std;

#include "resetTittle.h"
#include "ServicoListaEmpregado.h"

#ifndef APPHANDLER_H
#define APPHANDLER_H

ListaEmpregado *handleInsertEmpregado(ListaEmpregado *empregado)
{
  ServicoListaEmpregado servicoListaEmpregado = ServicoListaEmpregado();

  int prontuario;
  string nome, title = "Cadastro de novo funcionario";
  double salario;
  string ok;

  bool ProntuarioEmUso = false;

  do
  {
    resetTitle(title);

    if (ProntuarioEmUso)
    {
      cout << "O prontuario inserido ja esta em uso, tente novamente." << endl
           << endl;
    }

    cout << "Digite o prontuario do novo funcionario(numero inteiro): ";
    cin >> prontuario;

    servicoListaEmpregado.find(
        empregado,
        prontuario,
        ProntuarioEmUso);
  } while (ProntuarioEmUso);

  resetTitle(title);
  cout << "Digite o nome do novo funcionario: ";
  cin >> nome;

  resetTitle(title);
  cout << "Digite o salario do novo funcionario: ";
  cin >> salario;
  
  Empregado newEmpregado = Empregado(prontuario, nome, salario);
    

  return servicoListaEmpregado.insert(empregado, newEmpregado);
};

void handleFindEmployee(ListaEmpregado *empregado)
{
  string title = "Procurando empregado.";
  int prontuarioEmpregado;

  resetTitle(title);

  cout << "Informe o prontuario do empregado: ";

  cin >> prontuarioEmpregado;

  resetTitle(title);

  ServicoListaEmpregado servicoListaEmpregado = ServicoListaEmpregado();
  ListaEmpregado *ponteiroEmpregado;

  bool empregadoFound = false;

  ponteiroEmpregado = servicoListaEmpregado.find(
      empregado,
      prontuarioEmpregado,
      empregadoFound);

  if (!empregadoFound)
  {
    cout << "Empregado nao encontrado." << endl
         << endl;
  }
  else
  {
    cout << "Empregado encontrado." << endl
         << endl;

    cout << "Prontuario: " << ponteiroEmpregado->data.getProntuario() << endl;
    cout << "Nome: " << ponteiroEmpregado->data.getNome() << endl;
    cout << "Salario: " << ponteiroEmpregado->data.getSalario() << endl;
    cout << "------------------------Fim" << endl
         << endl;
  }
};

ListaEmpregado *handleDeleteEmpregado(ListaEmpregado *empregado)
{
  string title = "Removendo empregado.";
  int prontuarioEmpregado;

  resetTitle(title);

  cout << "Informe o prontuario do empregado: ";

  cin >> prontuarioEmpregado;

  resetTitle(title);

  ServicoListaEmpregado servicoListaEmpregado = ServicoListaEmpregado();

  bool empregadoDelete = false;

  	  empregado = servicoListaEmpregado .remove(
      empregado,
      prontuarioEmpregado,
      empregadoDelete);

  if (empregadoDelete)
  {
    cout << "O empregado foi removido com sucesso." << endl
         << endl;
  }
  else
  {
    cout << "O empregado nao foi removido, pois nao foi encontrado" << endl
         << endl;
  }

  return empregado;
};

#endif
