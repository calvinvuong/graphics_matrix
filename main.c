#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"
#include "matrix.h"

int main() {
  srand(time(NULL));
  
  screen s;
  struct matrix *edges;
  struct matrix *identity;
  struct matrix *transform;
  
  edges = new_matrix(4, 6);
  identity = new_matrix(4, 4);
  transform = new_matrix(4, 4);

  printf("4x4 Identity Matrix:\n");
  ident(identity);
  print_matrix(identity);
  printf("\n");

  // set matrix to random values
  int i, j;
  for ( i = 0; i < 4; i++ ) {
    for ( j = 0; j < 6; j++ ) {
      edges->m[i][j] = (double) (rand() % 13);
    }
  }

  printf("Edge Matrix of Random Values:\n");
  print_matrix(edges);
  printf("\n");

  
  // set transformation matrix to random values
  for ( i = 0; i < 4; i++ ) {
    for ( j = 0; j < 4; j++ ) {
      transform->m[i][j] = (double) (rand() % 13);
    }
  }

  printf("4x4 Transformation Matrix of Random Values:\n");
  print_matrix(transform);
  printf("\n");
  
  printf("Transformation Matrix * Edge Matrix:\n");
  matrix_mult(transform, edges);
  print_matrix(edges);
  printf("\n");

  printf("Identity Matrix * (Transformed) Edge Matrix:\n");
  matrix_mult(identity, edges);
  print_matrix(edges);
  printf("\n");

  printf("Scalar Multiplication: 4.2 * (Transformed) Edge Matrix:\n");
  scalar_mult(4.2, edges);
  print_matrix(edges);
  printf("\n");

  free_matrix( edges );
  free_matrix(identity);
  free_matrix(transform);
}  
