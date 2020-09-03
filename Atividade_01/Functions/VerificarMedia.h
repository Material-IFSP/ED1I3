#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;


#ifndef VERIFMEDIA
#define VERIFMEDIA

/*
	funcao retorna um ponteiro p/ um
	array contendo os itens maiores
	que a media da matriz de entradaa
*/
int *VerifMaiorMedia(int *numbers, int &quantityOfNumbers, int &av)
{
  int sum = 0;
  int countOfLargers = 0;

  for (int i = 0; i < quantityOfNumbers; i++)
  {
    sum += *(numbers + i);
  }

  int average = sum / quantityOfNumbers;
  int *largers = (int *)malloc(sizeof(int) * quantityOfNumbers);

  for (int i = 0; i < quantityOfNumbers; i++)
  {
    if (*(numbers + i) > average)
    {
      *(largers + countOfLargers) = *(numbers + i);
      countOfLargers++;
    }
  }

  int *treated_largers = (int *)malloc(sizeof(int) * countOfLargers);

  for (int i = 0; i < countOfLargers; i++)
  {
    treated_largers[i] = *(largers + i);
  }

  quantityOfNumbers = countOfLargers;
  av = average;

  return treated_largers;
}

#endif