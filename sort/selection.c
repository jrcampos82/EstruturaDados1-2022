#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// augusto
#define TAM 8

void selection(int vetor[]);
void swap(int *a, int *b);
void print(int array[]);

int main()
{
  int data[] = {0, 2, 7, 0, 9, 3, 8, 0};
  print(data);
  selection(data);
}

void selection(int vetor[])
{

  for (int i = 0; i < TAM; i++)
  {
    int menor = i; // armazenando apenas o indice
    for (int j = i; j < TAM; j++)
    {
      if (vetor[j] < vetor[menor])
      {
        menor = j;
      }
    }
    swap(&vetor[i], &vetor[menor]);
  }
}
// trocar elementos
void swap(int *a, int *b)
{
  int aux = *a;
  *a = *b;
  *b = aux;
}

void print(int array[])
{
  for (int i = 0; i < TAM; i++)
  {
    printf("%d\t", array[i]);
  }
  printf("\n");
}