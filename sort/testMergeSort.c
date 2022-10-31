#include "sort.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main()
{
  srand(time(NULL));
  int vetor[] = {6, 2, 7, 0, 9, 3, 8, 1};

  int vetor2[TAM];

  for (int i = 0; i < TAM; i++)
  {
    vetor2[i] = random_number(10, 50);
  }

  printVector(vetor2);
  mergeSort(vetor2, 0, TAM - 1);
  printVector(vetor2);
}