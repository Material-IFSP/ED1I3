#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "./Functions/clear.h"
#include "./Functions/NumRandomicos.h"
#include "./Functions/PedirValores.h"
#include "./Functions/VerificarMedia.h"

using namespace std;

/*	funçoes organizadas por Headers
	p/ consulta abrir as funções 
	separadamente na pasta Funções :))
*/


int main(void)
{
  while(true){
	
  clear();
  const int quantNumeros = 10;

  string NumRandom = "DefaultNull";
  string Verif = "s";
  int *Num;
  

  cout << "Deseja gerar os valores aleatoriamente? (S/N) ";
  cin >> NumRandom;

  clear();
	
  Num = (int *)malloc(sizeof(int) * quantNumeros);

  
  /*Laço para verificar e deixar passar 
  apenas as duas opções válidas;  
  */
  
  while (NumRandom != "N" || NumRandom != "n" || NumRandom != "S" || NumRandom != "s"){
	  
	  if (NumRandom == "N" || NumRandom == "n" || NumRandom == "S" || NumRandom == "s")
		{
		break;
		}
		clear();
		cout << "Insira Apenas S para Sim ou N para Nao \n";
		cout << "Deseja gerar os valores aleatoriamente? (S/N) ";
		cin >> NumRandom;
  	  
  	  }
  	  
  /*Verificar se o user deseja inserir os numeros aleatorios
  	ou inseri-los manualmente;
  */  
  
  if (NumRandom == "N" || NumRandom == "n")
  {
    PedirValores(Num, quantNumeros);
    clear();
  }
  else if (NumRandom == "S" || NumRandom == "s")
  {
    NumRandomicos(Num, quantNumeros);
  }
  

  // Quantidade e Media dos Valores;
  int QMedia = quantNumeros;
  int media;

  int *MaiorMedia = VerifMaiorMedia(Num, QMedia, media);

  // Exibição do Resultado;
  {
    
	clear();
	cout << "Media dos valores inseridos: " << media << "." << endl;

    cout << "Quantidade de numeros maiores que a media: " << QMedia << "." << endl
         << endl;

    cout << "[  " ;

    for (int i = 0; i < QMedia; i++)
    {
      cout << " " << MaiorMedia[i] << ", " ;
    }

    cout << " ]" << endl;
  }

  free(Num);
  free(MaiorMedia);

  cout << "\n \n S para Sair ou N para Efetuar Outra Operacao:  ";
  cin >> Verif;
  
  if(Verif == "S" || Verif == "s")
  {
	  break;
  }  
  
  }
  return 0; 
}
