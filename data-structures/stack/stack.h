#ifndef STACK_H
#define STACK_H

typedef struct Node {
  int value;
  struct Node* prev;
} Node;

typedef struct Stack {
  Node* top;
  int size;
} Stack;

void push(Stack* s, int value);
int pop(Stack* s);
int peek(Stack* s);
void free_stack(Stack* s);
Stack* create_stack();
#endif
