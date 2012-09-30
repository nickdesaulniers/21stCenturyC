// Variadic macros work a little nicer than variable lenght functions
#include <stdio.h>

// Dont leave spaces between pseudo function name and '('
#define forloop(i, loop_max, ...) for (int i = 0; i < loop_max; i++) \
                                    {__VA_ARGS__}

int main () {
  int sum = 0;
  forloop(i, 10,
    sum += i;
    printf("sum to %i: %i\n", i, sum);
  );
}