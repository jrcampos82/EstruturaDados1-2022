#include "sort.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *a, int *b)
{
  int aux = *a;
  *a = *b;
  *b = aux;
}

void bubble(int vector[], int size)
{
  for (int i = 0; i < size - 1; i++)
  {
    for (int j = 0; j < size - 1; j++)
    {

      if (vector[j] > vector[j + 1])
      {
        swap(&vector[j], &vector[j + 1]);
      }
    }
  }
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

void printVector(int array[])
{
  for (int i = 0; i < TAM; i++)
  {
    printf("%d\t", array[i]);
  }
  printf("\n");
}
/**
 * @brief Ordena o vetor usando o método mergesort
 * complexidade O(n log n)
 *
 * @param arr O vetor a ser ordenado
 * @param inicio indice do primeiro elemento
 * @param fim indice do último elemento
 * @return .
 */
void mergeSort(int arr[], int inicio, int fim)
{
  if (inicio < fim)
  {

    int meio = inicio + (fim - inicio) / 2;
    mergeSort(arr, inicio, meio);
    mergeSort(arr, meio + 1, fim);
    merge(arr, inicio, meio, fim);
  }
}

void merge(int arr[], int inicio, int meio, int fim)
{
  int n1 = meio - inicio + 1;
  int n2 = fim - meio;

  int L[n1];
  int R[n2];

  for (int i = 0; i < n1; i++)
  {
    L[i] = arr[inicio + i];
  }
  for (int i = 0; i < n2; i++)
  {
    R[i] = arr[meio + 1 + i]; // pensar ....
  }

  int i = 0, j = 0, k = inicio;
  while (i < n1 && j < n2)
  {
    if (L[i] <= R[j])
    {
      arr[k] = L[i];
      i++;
    }
    else
    {
      arr[k] = R[j];
      j++;
    }
    k++;
  }

  while (j < n2)
  {
    arr[k] = R[j];
    j++;
    k++;
  }

  while (i < n1)
  {
    arr[k] = L[i];
    i++;
    k++;
  }
}
int random_number(int lower, int upper)
{
  int num = (rand() %
             (upper - lower + 1)) +
            lower;
  return num;
}