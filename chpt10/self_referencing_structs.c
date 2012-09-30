#include <stddef.h> // NULL

// Here the anonymous struct with these fields is a person struct
typedef struct {
  char* name;
  int age;
} person;

// while the code compiles without the first person_node, using it latter gives
// a -Wincompatible-pointer-types warning
typedef struct person_node {
  person* person;
  //person_node* next_person; // -> error: must use 'struct' tag to refer to type 'person_node'
  struct person_node* next_person;
} person_node;

int main () {
  person nick = { .name = "Nick", .age = 22 };
  person rayray = { .name = "Rayray", .age = 21 };
  
  person_node rpn = { .person = &rayray, .next_person = NULL };
  person_node npn = { .person = &nick, .next_person = &rpn };
}