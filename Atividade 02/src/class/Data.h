#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>

using namespace std;

#ifndef DATE_H
#define DATE_H

class Date
{
private:
  int dia;
  int mes;
  int ano;

public:
  Date(int dia, int mes, int ano)
  {
    this->dia = dia;
    this->mes = mes;
    this->ano = ano;
  }

  Date ()
  {
    this->dia = 0;
    this->mes = 0;
    this->ano = 0;
  }

  int getDia()
  {
    return this->dia;
  }

  int getMes()
  {
    return this->mes;
  }

  int getAno()
  {
    return this->ano;
  }

  string getDate()
  {
    return to_string(this->dia) + "/" + to_string(this->mes) + "/" + to_string(this->ano);
  }

  Date *getProxDia()
  {
    int DiasMes[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    Date *proxDia = new Date(this->dia, this->mes, this->ano);

    if (proxDia->ano % 4 == 0)
    {
      DiasMes[1]++;
    }

    proxDia->dia++;
    if (proxDia->dia > DiasMes[proxDia->mes - 1])
    {
      proxDia->dia = 1;
      if (++proxDia->mes > 12)
      {
        proxDia->mes = 1;
        proxDia->ano++;
      }
    }

    return proxDia;
  }
};

#endif
