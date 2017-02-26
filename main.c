#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"
#include "matrix.h"

int main() {
  int i;
  
  screen s;
  color c;

  clear_screen(s);
  
  c.red = 200;
  c.blue = 150;
  c.green = 0;
  
  struct matrix *edges;
  struct matrix *identity;
  struct matrix *transform;
  
  edges = new_matrix(4, 4);
  identity = new_matrix(4, 4);
  transform = new_matrix(4, 4);

  printf("4x4 Identity Matrix:\n");
  ident(identity);
  print_matrix(identity);
  printf("\n");

  // set edge matrix 
  add_edge(edges, 0, 250, 0, 250, 500, 0);
  add_edge(edges, 250, 500, 0, 500, 250, 0);
  add_edge(edges, 500, 250, 0, 250, 0, 0);
  add_edge(edges, 250, 0, 0, 0, 250, 0);

  printf("Edge Matrix:\n");
  print_matrix(edges);
  printf("\n");

  // identity multiply
  printf("Identity Matrix * Edge Matrix:\n");
  matrix_mult(identity, edges);
  print_matrix(edges);
  // draw edge matrix
  draw_lines(edges, s, c);
  printf("Edge matrix drawn...\n\n");

  // scalar multiply 
  printf("Scalar Multiplication: 0.75 * Edge Matrix:\n");
  scalar_mult(0.95, edges);
  print_matrix(edges);
  // draw edge matrix
  draw_lines(edges, s, c);
  printf("New edge matrix drawn...\n\n");
  printf("Doing this again a few times...\n");
  for ( i = 0; i < 20; i++ ) {
    scalar_mult(0.95, edges);
    c.red -= 9;
    draw_lines(edges, s, c);
  }
  printf("New edge matrices drawn...\n\n");
  
  // set transformation matrix 
  ident(transform);
  transform->m[0][0] = 1.05;  
  transform->m[1][1] = 1.1;
    
  printf("4x4 Transformation Matrix:\n");
  print_matrix(transform);
  printf("\n");

  c.green = 100;
  
  // matrix multiply
  printf("Transformation Matrix * Edge Matrix:\n");
  matrix_mult(transform, edges);
  print_matrix(edges);
  // draw edge matrix
  draw_lines(edges, s, c);
  printf("New edge matrix drawn...\n\n");
  printf("Doing this again a few times...\n");
  for ( i = 0; i < 10; i++ ) {
    matrix_mult(transform, edges);
    c.green += 15;
    draw_lines(edges, s, c);
  }
  printf("New edge matrices drawn...\n\n");
  
  printf("Displaying image...\n");
  display(s);
  save_extension(s, "matrix.png");
  
  free_matrix( edges );
  free_matrix(identity);
  free_matrix(transform);
}  
