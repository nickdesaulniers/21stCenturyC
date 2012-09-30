#include <stdio.h>

typedef char* string;

#define Foreach_string(iterator, ...) \
  for (string* iterator = (char*[]) { __VA_ARGS__, NULL }; *iterator; iterator++)

int main () {
  string str = "thread";
  Foreach_string(i, "yarn", str, "rope") {
    printf("%s\n", *i);
  }
}