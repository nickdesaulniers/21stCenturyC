// Structs gets copied, but setting one array to the other creates an alias
#include <assert.h>

int main () {
  int abc[] = { 1, 2, 3 };
  int* copy = abc;
  copy[0] = 3;
  // The original changed when the copy did
  assert(abc[0] == 3);
}