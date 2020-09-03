#include <stdio.h>
#include <stdlib.h>

extern void MostrarMatriz(
    int **matriz,
    int Horizontal,
    int Vertical,
    string TituloA = "Matriz")
{
  cout << TituloA << "\n \n";

  for (int i = 0; i < Vertical; i++)
  {
    for (int j = 0; j < Horizontal; j++)
    {
      cout << matriz[i][j] << " ";
    }

    cout << endl;
  }
}