#include <stdio.h>
#include <iostream>
#include <stdlib.h>

#ifndef CLEAR
#define CLEAR

extern void clear()
{
#if defined(_WIN32) || defined(_WIN64)
  system("cls");
#else
  system("clear");
#endif
}
#endif
