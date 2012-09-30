#include <math.h> // NAN
#include <stdio.h>

double sum_array (double in[]) {
  double out = 0;
  for (int i = 0; !isnan(in[i]); i++) out += in[i];
  return out;
}

// This variadic macro uses a compound literal to allways append a NAN to the
// end of the list.  This way we dont need to keep adding NAN or even use an
// array for that matter.
#define sum(...) sum_array((double []) { __VA_ARGS__, NAN })

int main () {
  double two_and_two = sum(2, 2);
  printf(" 2 + 2      = %g\n", two_and_two);
  printf("(2 + 2) * 3 = %g\n", sum(two_and_two, two_and_two, two_and_two));
  printf("sum(asst)   = %g\n", sum(3.1415, two_and_two, 3, 8, 98.4));
}