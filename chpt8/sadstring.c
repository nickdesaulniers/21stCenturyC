// Runs the sys command strings, which prints the strings in constant memory
// in a given binary.  The first "strings " is not shown prossibly because
// of a compile time optimaztion?
#include <stdio.h>  //snprintf
#include <string.h> //strlen
#include <stdlib.h> //malloc, free, system

void get_strings (char* const in) {
  char* cmd;
  int len = strlen("strings ") + strlen(in) + 1;
  cmd = malloc(len);
  snprintf(cmd, len, "strings %s", in);
  if (system(cmd)) printf("something went wrong running %s.\n", cmd);
  free(cmd);
}

int main (int argc, char** argv) {
  get_strings(argv[0]);
}
