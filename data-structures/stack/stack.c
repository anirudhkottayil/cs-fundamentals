#include "stack.h"
#include <stdio.h>
#include <stdlib.h>


int peek(Stack* s){
  if (s->size == 0) {return -1;}
  return s->top->value;
}

int pop(Stack* s){
  if (s->size == 0) {return -1;}
  int val = s->top->value;
  Node* temp = s->top;
  s->top = s->top->prev;
  free(temp);
  s->size--;
  return val;
}
void push(Stack* s, int value){
  Node* new_node = malloc(sizeof(Node));
  new_node->value = value;
  new_node->prev = s->top;
  s->top = new_node;
  s->size++;
}

void free_stack(Stack* s){
  Node* temp;
  while (s->top != NULL){
    temp = s->top;
    s->top = s->top->prev;
    free(temp);
  }
  free(s);
}

Stack* create_stack(){
  Stack* new_stack = malloc(sizeof(Stack));
  new_stack->top = NULL;
  new_stack->size = 0;
  return new_stack;
}
