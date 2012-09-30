// Need to typecast a literal of literals
// eg. int x = 12; my_func({ 1, 2, 3, x });
// should be:
// int x = 12; my_func((int) { 1, 2, 3, x });
#include <math.h> // NAN
#include <stdio.h>

double sum (double in[]) {
  double out = 0;
  for (int i = 0; !isnan(in[i]); i++) out += in[i];
  return out;
}

int main () {
  // Without compound literals we have to declare input on its own line
  double list[] = { 1.1, 2.2, 3.3, NAN };
  printf("sum: %g\n", sum(list));
  // With compound literals we can do a one liner (dont forget the cast)
  printf("sum: %g\n", sum((double[]) { 1.1, 2.2, 3.3, NAN }));
}

// I would call this anonymous literal