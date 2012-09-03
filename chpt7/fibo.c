#include <stdio.h>

// References to static variables stick around
// Static values are initialized before main starts so they need to be
// initialized to constants
long long int fibonacci () {
  static long long int first = 0;
  static long long int second = 1;
  long long int out = first + second;
  first = second;
  second = out;
  return out;
}

int main () {
  for (int i = 0; i < 50; i++)
    printf("%lli\n", fibonacci());
}