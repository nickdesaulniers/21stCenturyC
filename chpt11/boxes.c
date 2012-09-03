// Using designated initializers to specify a structure
#include <stdio.h>

typedef struct {
  char* name;
  int left, right, up, down;
} direction_s;

void this_row (direction_s d);
void draw_box (direction_s d);

int main () {
  // Anything not specified is initialized to 0
  direction_s D = {
    .name = "left",
    .left = 1
  };
  draw_box(D);
  
  // You can mix the undesignated style (name) with designated
  // undesignated values go in order of the struct fields.
  // Also notice how we need a compound literal (typecast), that way
  // we can use an anonymous struct and not need a temp var.
  D = (direction_s) {
    "upper right",
    .up = 1,
    .right = 1
  };
  draw_box(D);
  
  // Empty literal initializes everything to 0
  draw_box((direction_s){});
  
  // without compound literals you'd have a multiline declaration like:
  direction_s A;
  A.name = "old fashioned";
  A.left = 1;
  A.right = 0;
  A.up = 1;
  A.down = 0;
}

void this_row (direction_s d) {
  printf(d.left ? "*..\n" : d.right ? "..*\n" : ".*.\n");
}

void draw_box (direction_s d) {
  printf("%s:\n", (d.name ? d.name : "a box"));
  d.up               ? this_row(d) : printf("...\n");
  (!d.up && !d.down) ? this_row(d) : printf("...\n");
  d.down             ? this_row(d) : printf("...\n");
  printf("\n");
}