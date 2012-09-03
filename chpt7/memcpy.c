// Copying an array requires memcpy
#include <assert.h>
#include <string.h>

int main () {
  int abc[] = { 0, 1, 2 };
  int* copy1, copy2[3];
  
  // copies the reference to the array
  copy1 = abc;
  // copies the values of the array
  memcpy(copy2, abc, sizeof(int) * 3);
  
  abc[0] = 3;
  assert(copy1[0] == 3);
  assert(copy2[0] == 0);
}