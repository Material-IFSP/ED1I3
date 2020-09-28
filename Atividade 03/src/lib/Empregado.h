#include <iostream>
using namespace std;

#ifndef EMPREGADO_H
#define EMPREGADO_H

class Empregado
{
private:
  int prontuario;
  string nome;
  double salario;

public:
  Empregado()
  {
    this->prontuario = 0;
    this->nome = "";
    this->salario = 0;
  }

  Empregado(int prontuario, string nome, double salario)
  {
    this->prontuario = prontuario;
    this->nome = nome;
    this->salario = salario;
  }

  int getProntuario()
  {
    return this->prontuario;
  }

  string getNome()
  {
    return this->nome;
  }

  double getSalario()
  {
    return this->salario;
  }

  void setProntuario(int prontuario)
  {
    this->prontuario = prontuario;
  }

  void setNome(string nome)
  {
    this->nome = nome;
  }

  bool setSalario(double novoValor)
  {
    if (novoValor < 0)
    {
      return false;
    }

    this->salario = novoValor;

    return true;
  }
};

#endif
