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

int getMediaIdades(Contato contacts[], int cntContato)
{
  int media = 0;

  for (int i = 0; i < cntContato; i++)
  {
    media += contacts[i].getIdade();
  }

  return media / cntContato;
}

string *getNomeMaiorMedia(Contato contacts[], int media, int cntContato, int &cntMaiorMedia)
{
  int *lgIndex;
  cntMaiorMedia = 0; //

  lgIndex = (int *)malloc(sizeof(int) * cntContato);

  for (int i = 0; i < cntContato; i++)
  {
    if (contacts[i].getIdade() > media)
    {
      *(lgIndex + cntMaiorMedia) = i;

      cntMaiorMedia++;
    }
  }

  string *MaiorMed = new string[cntMaiorMedia];//  

  for (int i = 0; i < cntMaiorMedia; i++)
  {
    MaiorMed[i] = contacts[*(lgIndex + i)].getNome(); // 
  }

  return MaiorMed;
}

Contato *getVelho(Contato contacts[], int cntContato, int &cntMaisVelho) //
{
  int MaiorIdade = 0;

  cntMaisVelho = 0;

  for (int i = 0; i < cntContato; i++)
  {
    if (contacts[i].getIdade() > MaiorIdade)
    {
      MaiorIdade = contacts[i].getIdade();
      cntMaisVelho = 1;
    }
    else if (contacts[i].getIdade() == MaiorIdade)
    {
      cntMaisVelho++;
    }
  }

  Contato *Velho = new Contato[cntMaisVelho];

  int addVelho = 0;

  for (int i = 0; i < cntContato; i++)
  {
    if (contacts[i].getIdade() == MaiorIdade)
    {
      Velho[addVelho] = contacts[i];
      addVelho++;
    }
  }

  return Velho;
}

void PopulandoContatos(Contato contacts[])
{
  contacts[0] = Contato("Joao", "joao@email.test", "+551144028922", Date(27, 11, 1998));
  contacts[1] = Contato("Alberto", "alberto@email.test", "+551144028922", Date(29, 4, 1962));
  contacts[2] = Contato("Murilo", "murilao@email.test", "+551144028922", Date(12, 1, 2001));
  contacts[3] = Contato("Jose", "jose@email.test", "+551144028922", Date(29, 4, 1952));
  contacts[4] = Contato("Caio", "caio@email.test", "+551144028922", Date(11, 8, 1999));
  contacts[5] = Contato("Maria", "maria@email.test", "+551144028922", Date(8, 6, 1972));
  contacts[6] = Contato("Lucas", "luquinhasobrabo@email.test", "+551144028922", Date(2, 5, 2011));
  contacts[7] = Contato("Roberta", "roberta@email.test", "+551144028922", Date(24, 1, 2002));
  contacts[8] = Contato("Miranda", "miranda@email.test", "+551144028922", Date(16, 5, 1984));
  contacts[9] = Contato("Renata", "renata@email.test", "+551144028922", Date(12, 12, 1992));
}

int main()
{
	while(true){
  const int cntContato = 10;
  string Verif = "aaaa";
  string ValoresAuto = "DefaultNull";

  Contato contacts[cntContato];
  
  
  cout << "Deseja Popular Manualmente os dados ou inseri-los automaticamente?\n S ou N ? : ";
  cin >> ValoresAuto;
  
  
  clear();
  
  
   while (ValoresAuto != "N" || ValoresAuto != "n" || ValoresAuto != "S" || ValoresAuto != "s"){
	  
	  if (ValoresAuto == "N" || ValoresAuto == "n" || ValoresAuto == "S" || ValoresAuto == "s")
		{
		break;
		}
		clear();
		cout << "Insira Apenas S para Sim ou N para Nao \n";
		cout << "Deseja gerar os valores automaticamente? (S/N) ";
		cin >> ValoresAuto;
  	  
  	  }
  	  
  /*Verificar se o user deseja inserir os numeros aleatorios
  	ou inseri-los manualmente;
  */  

  if (ValoresAuto == "S" || ValoresAuto == "s")
  {
    PopulandoContatos(contacts);
  }
  else if (ValoresAuto == "N" || ValoresAuto == "n")
  {
    for (int i = 0; i < cntContato; i++)
    {
      clear();

      cout << "Preenchendo dados para o " << i + 1 << " contato." << endl
           << endl;
      int DiaNasc, MesNasc, AnoNasc;
      string nome, email, telefone;

      InfoUser(nome, email, telefone);
      clear();
      cout << "Preenchendo dados para o " << i + 1 << " contato." << endl
           << endl;

      PedirNasc(DiaNasc, MesNasc, AnoNasc);
      clear();
      cout << "Preenchendo dados para o " << i + 1 << " contato." << endl
           << endl;

      Date DiaNasContato = Date(DiaNasc, MesNasc, AnoNasc);

      contacts[i] = Contato(nome, email, telefone, DiaNasContato);
    }
  }
  int media = getMediaIdades(contacts, cntContato);

  string *MaiorMedia; //largersThanAverage
  int cntMaiorMedia = 0;

  MaiorMedia = getNomeMaiorMedia(contacts, media, cntContato, cntMaiorMedia);

  int cntMaiordeIdade = 0;

  for (int i = 0; i < cntContato; i++)
  {
    if (contacts[i].getIdade() >= 18)
    {
      cntMaiordeIdade++;
    }
  }

  //int lgIdade = 0; // largerage
  //int cntOlders = 0;

  Contato *Velho;

  Velho = getVelho(contacts, cntContato, cntMaiorMedia);

  //exibindo os resultados
  {
    cout << "\n\nMedia de idades: " << media << endl
         << endl;

    cout << "Contatos com idades superior a media: " << endl;

    for (int i = 0; i < cntMaiorMedia; i++)
    {
      cout << "- " << MaiorMedia[i] << endl;
    }

    cout << endl;

    cout << "Quantidade de contatos maiores de idade: " << cntMaiordeIdade << endl
         << endl;

    cout << "-------//Contatos mais velhos\\--------" << endl;
    cout << "Quantidade de contatos mais velhos: " << cntMaiorMedia << endl;
    cout << "Contatos: " << endl
         << endl;

    cout << "[" << endl;
    for (int i = 0; i < cntMaiorMedia; i++)
    {
      cout << "  {" << endl;
      cout << "    Nome: " << Velho[i].getNome() << endl;
      cout << "    Email: " << Velho[i].getEmail() << endl;
      cout << "    Telefone: " << Velho[i].getTelefone() << endl;
      cout << "  }," << endl;
    }
    cout << "]" << endl;
  }
	
	
	cout << "\n \n S para Sair ou N para Efetuar Outra Operacao:  ";
	cin >> Verif;
  
  if(Verif == "S" || Verif == "s")
  {
	  break;
  }  
	}
  return 0;
}
