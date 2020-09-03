#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "./Functions/clear.h"
#include "./Functions/Matriz.h"
#include "./Functions/PedirValores.h"
#include "./Functions/MostrarMatriz.h"
#include "./Functions/NumRandomicos.h"

using namespace std;

/*	funçoes organizadas por Headers
	p/ consulta abrir as funções 
	separadamente na pasta Funções :))
*/

int main(void)
{
	while(true){
	
  clear();
  const int Horizontal = 3;
  const int Vertical = 3;

  int **matrizA;
  int **matrizB;

  matrizA = (int **)malloc(sizeof(int) * Vertical);
  matrizB = (int **)malloc(sizeof(int) * Vertical);

  // alocando as "linhas"
  for (int i = 0; i < Vertical; i++)
  {
    matrizA[i] = (int *)malloc(sizeof(int) * Horizontal);
  }

  for (int i = 0; i < Vertical; i++)
  {
    matrizB[i] = (int *)malloc(sizeof(int) * Horizontal);
  }

  string NumRandom = "DefaultNull";
  string Verif = "s";
  
  cout << "Deseja gerar os valores aleatoriamente? (S/N) ";
  cin >> NumRandom;

  clear();
  
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
  	  
   if (NumRandom == "N" || NumRandom == "n")
  // populando manualmente
  {
  	clear();
    for (int i = 0; i < Vertical; i++)
    {
      cout << "Populando a linha " << i << " da matrix A" << endl
           << endl;

      PedirValores(matrizA[i], Horizontal);
      clear();
    }

    for (int i = 0; i < Vertical; i++)
    {
      cout << "Populando a linha " << i << " da matrix B" << endl
           << endl;

      PedirValores(matrizB[i], Horizontal);
      clear();
    }
  } 
  else if (NumRandom == "S" || NumRandom == "s")
  {
    //populando automaticamente
  for (int i = 0; i < Vertical; i++)
    {
      cout << "Populando a linha " << i << " da matrix A" << endl
           << endl;

      NumRandomicos(matrizA[i], Horizontal);
      clear();
    }

    for (int i = 0; i < Vertical; i++)
    {
      cout << "Populando a linha " << i << " da matrix B" << endl
           << endl;

      NumRandomicos2(matrizB[i], Horizontal,Vertical);
      clear();
    }
  }
  
  
  
  
  
  
/* 	chamando a função para mostrar os valores 
	no final do programa;
*/
  MostrarMatriz(matrizA, Horizontal, Vertical, "Matriz A");
  cout << endl;

  MostrarMatriz(matrizB, Horizontal, Vertical, "Matriz B");

  bool matrixAreEquals = compareMatrices(
      matrizA,
      matrizB,
      Horizontal,
      Vertical);

  string MatrizIgual = "As matrizes sao iguais";
  string MatrizDif = "As matrizes sao diferentes";

  cout << (matrixAreEquals ? MatrizIgual : MatrizDif) << endl;

  free(matrizA);
  free(matrizB);
  
  cout << "\n \n S para Sair ou N para Efetuar Outra Operacao:  ";
  cin >> Verif;
  
  if(Verif == "S" || Verif == "s")
  {
	  break;
  } 
  }

  return 0;
}
