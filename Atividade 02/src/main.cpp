#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>

#include "./class/clear.h"
#include "./class/Data.h"
#include "./class/Contato.h"

using namespace std;

void PedirNasc(int &DiaNasc, int &MesNasc, int &AnoNasc)
{
  cout << "Digite o dia de seu nascimento: ";
  cin >> DiaNasc;

  cout << "Digite o mês de seu nascimento: ";
  cin >> MesNasc;

  cout << "Digite o ano de seu nascimento: ";
  cin >> AnoNasc;
}

void InfoUser(string &nome, string &email, string &telefone)
{
  cout << "Digite o seu nome: ";
  cin >> nome;

  cout << "Digite o seu email: ";
  cin >> email;

  cout << "Digite o seu telefone: ";
  cin >> telefone;
}

void MostrarResultado(Contato user)
{
  cout << "Informacao do usuario" << endl
       << endl;

  cout << "Nome: " << user.getNome() << endl;
  cout << "Email: " << user.getEmail() << endl;
  cout << "Telefone: " << user.getTelefone() << endl;

  cout << "Data de nascimento: " << user.getDtNasc().getDate() << endl;
  cout << "Idade: " << user.getIdade() << endl;
}

int main()
{
  int DiaNasc, MesNasc, AnoNasc;
  string nome, email, telefone;

  InfoUser(nome, email, telefone);
  clear();

  PedirNasc(DiaNasc, MesNasc, AnoNasc);
  clear();

  Date NascUser = Date(DiaNasc, MesNasc, AnoNasc);

  Contato user = Contato(nome, email, telefone, NascUser);

  MostrarResultado(user);

  return 0;
}
