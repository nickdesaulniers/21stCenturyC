#include <stdio.h> // printf
#include <string.h> // memset

typedef struct {
  int b, l, a, h;
} blah;

void print_array (double in[], int in_length) {
  printf("{ ");
  for (int i = 0, len = in_length / sizeof(double); i < len;
    printf("%.2f, ", in[i]), i++);
  printf(" }\n");
}

int main () {
  blah empty_struct = {};
  int empty_array[20] = {};
  
  // But if the array's length is dependant on a variable:
  int length = 21;
  int another_empty_array[length];
  memset(another_empty_array, 0, 21 * sizeof(int));
  
  double sparse_array[7] = {
    [2] = 1.1,
    [5] = 2.2
  };
  print_array(sparse_array, sizeof(sparse_array));
  // => { 0.00, 0.00, 1.10, 0.00, 0.00, 2.20, 0.00,  }
  
  // ex. of "pick up where you left off rule"
  const int len = 7;
  double another_sparse_array[len] = {
    0.1,
    [len - 5] = 1.1,
    // pick up where you left off
    2.2,
    3.3
  };
  print_array(another_sparse_array, sizeof(another_sparse_array));
  // => { 0.10, 0.00, 1.10, 2.20, 3.30, 0.00, 0.00,  }
}