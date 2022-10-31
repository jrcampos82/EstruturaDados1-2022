// ARQUIVO DE IMPLEMENTACOES
#include "float_vector.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// MINHA TAD
struct float_vector
{
  int capacity; // num max de elementos
  int size;     // qto atual elementos
  float *data;  // vetor de floats
};

bool _isFull(const FloatVector *vector)
{
  return vector->size == vector->capacity;
}

/**
 * @brief Cria (aloca) um vetor de floats com uma dada capacidade.
 *
 * @param capacity Capacidade do vetor.
 * @return FloatVector* Um vetor de floats alocado/criado.
 */
FloatVector *create(int tam)
{
  FloatVector *vet = (FloatVector *)calloc(1, sizeof(FloatVector));
  vet->capacity = tam;
  vet->size = 0;
  vet->data = (float *)calloc(vet->capacity, sizeof(float));

  return vet;
}

/**
 * @brief Cria (aloca) um vetor de floats com uma dada capacidade.
 *
 * @param **vet_ref A referencia da nossa TAD.
 * @return .
 */
void destroy(FloatVector **vet_ref)
{
  FloatVector *vet = *vet_ref;
  free(vet->data);
  free(vet);
  *vet_ref = NULL;
}

int size(const FloatVector *vector)
{
  return vector->size;
}

int capacity(const FloatVector *vector)
{
  return vector->capacity;
}

float at(const FloatVector *vector, int pos)
{
  if (pos < 0 || pos >= vector->size)
  {
    fprintf(stderr, "Error: Invalid position!\n");
    fprintf(stderr, "Index [%d] is out of bounds\n", pos);
    exit(EXIT_FAILURE);
  }

  return vector->data[pos];
}

float get(const FloatVector *vector, int index)
{
  return vector->data[index];
}

void append(FloatVector *vector, float n)
{
  if (_isFull(vector))
  {
    // error
    fprintf(stderr, "Error in append\nVector is full!");
    exit(EXIT_FAILURE); // stdlib.h
  }
  vector->data[vector->size++] = n;
  // inserir
}