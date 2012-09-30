#include <stdio.h>
#include <stdlib.h> // free

void get_strings (char const* in) {
  char* cmd;
  asprintf(&cmd, "strings %s", in);
  system(cmd);
  free(cmd);
}

int main (int argc, char** argv) {
  get_strings(argv[0]);
}
