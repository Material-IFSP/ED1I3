#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <time.h>

#include "MostrarDataAtual.h"
#include "./Data.h"

using namespace std;

#ifndef CONTATO
#define CONTATO

class Contato
{
private:
  string email;
  string nome;
  string telefone;
  Date dtnasc;

public:
  Contato(string nome, string email, string telefone, Date dtnasc)
  {
    this->nome = nome;
    this->email = email;
    this->telefone = telefone;
    this->dtnasc = dtnasc;
  }

  Contato()
  {
    this->nome = "";
    this->email = "";
    this->telefone = "";
    this->dtnasc = Date();
  }

  string getNome()
  {
    return this->nome;
  }

  string getEmail()
  {
    return this->email;
  }

  string getTelefone()
  {
    return this->telefone;
  }

  Date getDtNasc()
  {
    return this->dtnasc;
  }

  int getIdade()
  {
    Date hoje = getDataAtual();

    int idade = hoje.getAno() - this->dtnasc.getAno();

    if (this->dtnasc.getMes() <= hoje.getMes())
    {
      if (this->dtnasc.getDia() < hoje.getDia())
      {
        idade--;
      }
    }

    return idade;
  }
};

#endif
