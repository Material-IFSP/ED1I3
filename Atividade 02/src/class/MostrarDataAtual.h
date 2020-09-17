#include <stdio.h>
#include <stdlib.h>
#include <iostream>

#include "./Data.h"

using namespace std;

#ifndef GETDATAATUAL
#define GETDATAATUAL

extern Date getDataAtual()
{
  time_t tempo = time(NULL);

  struct tm *aTime  = localtime(&tempo);

  int DiaAtual = aTime->tm_mday;
  int MesAtual = aTime->tm_mon + 1;
  int AnoAtual = aTime->tm_year + 1900;

  return Date(DiaAtual, MesAtual, AnoAtual);
}

#endif
