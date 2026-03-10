#include "stack.h"
#include <stdio.h>

int main(){
  Stack* s = create_stack();
  push(s, 1);
  push(s, 2);
  push(s, 3);
  int val = peek(s);
  printf("%d\n", val);
  int popped = pop(s);
  printf("%d\n", popped);
  push(s, 4);
  push(s, 5);
  val = peek(s);

  printf("%d\n", val);
  free_stack(s);
  return 0;
}
