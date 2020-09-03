#include <stdio.h>
#include <stdlib.h>

using namespace std;

/*
  Esta funcao recebe o duas matrizes e
  retorna um valor booleano para indicar se as
  matrizes possuem os valores iguais
*/
#ifndef MATRIZ
#define MATRIZ

extern bool compareMatrices(
    int **matrixA,
    int **matrixB,
    int horizontalSize,
    int verticalSize)
{
  bool MatrizesIguais = true;

  cout << "\n \n";
  for (int i = 0; i < horizontalSize; i++)
  {
    for (int j = 0; j < verticalSize; j++)
    {
      MatrizesIguais = matrixA[i][j] == matrixB[i][j];

      if (!MatrizesIguais)
      {
        break;
      }
    }

    if (!MatrizesIguais)
    {
      break;
    }
  }

  return MatrizesIguais;
}

#endif
