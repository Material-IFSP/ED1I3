#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>

using namespace std;

#ifndef NUMRANDOMICO
#define NUMRANDOMICO

//*funcção gera numeros randomicos para o usuario;

extern void NumRandomicos(int *array, int tam_array)
{
  
  srand((unsigned)time(0));

  int NumRandom;

  for (int i = 0; i < tam_array; i++)
  {
    NumRandom = (rand() % 35);

    *(array + i) = NumRandom;
  }
}
extern void NumRandomicos2(int *array, int tamMatrizV, int tamMatrizH)
{
  
  srand((unsigned)time(0));

  int NumRandom;

  for (int i = 0; i < tamMatrizV; i++)
  {
    for (int j = 0; j < tamMatrizH; j++)
	
	NumRandom = (rand() % 35);

    *(array + i) = NumRandom;
    
  }
}


#endif
