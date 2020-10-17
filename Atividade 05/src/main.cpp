#include <iostream>
#include <stdlib.h>

using namespace std;

#include "./lib/clear.h"
#include "./lib/Fila.h"
#include "./lib/ServicoFila.h"

int AtualSenha = NULL;

void Atendimento(Fila *desFila, Fila *senhasRespondidas, string &mensagem)
{
  ServicoFila servicoFila = ServicoFila();

  if (servicoFila.verifVazio(desFila))
  {
    mensagem = "Sem senhas para atendimento.";
    return;
  }

  int senhaAtual = servicoFila.desenfileirar(desFila);

  servicoFila.add(senhasRespondidas, true, senhaAtual);

  cout << "Senha atendida: " << senhaAtual << endl;
  AtualSenha = senhaAtual;
  cin.get();
}

void Menu(bool usarFila = false, Fila *fila = NULL, string titulo = "Escolha uma Opçao: ")
{
  if (titulo != "")
  {
    cout << titulo << endl
         << endl;
  }
  if(AtualSenha != NULL)
  {
  cout << "Senha atendida: " << AtualSenha << endl;
  cout << "\n";
  }

  cout << "0. Sair" << endl;
  cout << "1. Gerar uma senha" << endl;
  cout << "2. Realizar atendimento" << endl;

  cout << endl;

  if (usarFila)
  {
    ServicoFila servicoFila = ServicoFila();

    cout << "Quantidade de senhas restante: " << servicoFila.count(fila) << endl;
  }
}

void AddSenha(Fila *filaSenha)
{
  ServicoFila servicoFila = ServicoFila();

  servicoFila.add(filaSenha);
}

int main(int argc, char **argv)
{
  string mensagem = "";
  int opcaoAtual;
  bool
      opcaoInvalida = false,
      deixarSair = true;

  ServicoFila servicoFila = ServicoFila();
  Fila
      *senhasRespondidas = servicoFila.init(),
      *senhasGeradas = servicoFila.init();

  do
  {
    clear();

    Menu(true, senhasGeradas);

    cout << endl;

    if (mensagem != "")
    {
      cout << mensagem << endl
           << endl;
    }

    if (opcaoInvalida)
    {
      cout << "Opcao Invalida!." << endl
           << endl;
    }

    if (opcaoAtual && !deixarSair)
    {
      cout << "Nao e permitido sair com senhas pendentes!." << endl
           << endl;
    }

    cout << "Opcao : ";

    cin >> opcaoAtual;

    opcaoInvalida = false;
    mensagem = "";
    deixarSair = servicoFila.verifVazio(senhasGeradas);

    switch (opcaoAtual)
    {
    case 0:
      if (deixarSair)
      {
        cout << "Senhas Atendidas :  " << servicoFila.count(senhasRespondidas) << endl;

        exit(0);
      }
      break;

    case 1:
      AddSenha(senhasGeradas);
      break;

    case 2:
      Atendimento(senhasGeradas, senhasRespondidas, mensagem);
      break;

    default:
      opcaoInvalida = true;
      break;
    }
  } while (opcaoAtual != 0 || opcaoInvalida || !deixarSair);

  return 0;
}
