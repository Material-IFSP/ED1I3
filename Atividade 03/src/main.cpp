#include <iostream>
using namespace std;

#include "./lib/clear.h"
#include "./lib/Empregado.h"
#include "./lib/AppHandler.h"
#include "./lib/ServicoListaEmpregado.h"

void Menu()
{
  cout << "Escolha uma das opcao abaixo." << endl
       << endl;

  cout << "0. Sair" << endl;
  cout << "1. Incluir" << endl;
  cout << "2. Excluir" << endl;
  cout << "3. Pesquisar" << endl;
  cout << "4. Listar" << endl;
}

int main(int argc, char **argv)
{
  int opcao = 0;
  bool
      json = false,
      ManterCounteudo = false,
      OpcaoInvalida = false;

  ServicoListaEmpregado servicoListaEmpregado = ServicoListaEmpregado();
  ListaEmpregado *empregado;

  empregado = servicoListaEmpregado.init();

  do
  {
    if (!ManterCounteudo)
      clear();
    ManterCounteudo = false;

    if (OpcaoInvalida)
    {
      cout << "Atencao. A opcao inserida anteriormente nao e valida.\n" << endl
           << endl;
    }

    Menu();

    cout << endl
         << "Opcao : ";

    cin >> opcao;

    switch (opcao)
    {
    case 0:
      exit(0);

    case 1:
      clear();
      OpcaoInvalida = false;
      empregado = handleInsertEmpregado(empregado);
      break;

    case 2:
      ManterCounteudo = true;
      OpcaoInvalida = false;
      empregado = handleDeleteEmpregado(empregado);
      break;

    case 3:
      ManterCounteudo = true;
      OpcaoInvalida = false;
      handleFindEmployee(empregado);
      break;

    case 4:
      clear();
      ManterCounteudo = true;
      OpcaoInvalida = false;
      servicoListaEmpregado .print(empregado, json);

      break;

    default:
      OpcaoInvalida = true;
      break;
    }

  } while (opcao != 0 || OpcaoInvalida);

  return 0;
}
