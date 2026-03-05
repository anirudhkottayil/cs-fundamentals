#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
  int value;
  struct Node* next;
} Node;

Node* create_head(int val){
  Node* ptr = malloc(sizeof(Node));
  ptr->value = val;
  ptr->next = NULL;
  return ptr;
}

Node* create_node(int val, Node* prev){
  Node* ptr = malloc(sizeof(Node));
  ptr->value = val;
  prev->next = ptr;
  ptr->next = NULL;
  return ptr;
}

void insert_node(int val,Node** head, Node* prev, Node* next){
  Node* ptr = malloc(sizeof(Node));
  ptr->value = val;
  if (prev == NULL){
    *head = ptr;
    ptr->next = next;
  } else if (next == NULL){
    prev->next = ptr;
    ptr->next = NULL;
  } else {
    prev->next = ptr;
    ptr->next = next;

  }
}

void delete_node(Node** head, Node* ptr, Node* prev){
  if (ptr->next == NULL){
    if (prev != NULL) prev->next = NULL;
    free(ptr);
  } else if (prev == NULL) { 
    *head = ptr->next;
    free (ptr); 
  } else {
    prev->next = ptr->next;
    free(ptr);

  }
}

void delete_list(Node* head){
  Node* temp = head;
  Node* prev = temp;
  while (temp->next != NULL){
     temp = temp->next;
    free(prev);
    prev = temp;
  }
  free(temp);
}

void print_list(Node* head){
  if (head == NULL) return;
  Node* temp = head;
  while (temp->next != NULL){
    printf("%d\n", temp->value);
    temp = temp->next;
  }
  printf("%d\n", temp->value);

}
int main(){
  Node* head = create_head(0);
  Node* one = create_node(1, head);
  Node* two = create_node(2, one);
  Node* three = create_node(3, two);
  Node* four = create_node(4, three);
  Node* five = create_node(5, four);
  Node* six = create_node(6, five);
  Node* seven = create_node(7, six);
  Node* nine = create_node(9, seven);

  print_list(head);
  insert_node(8,&head, seven, nine);
  print_list(head);
  delete_node(&head, five, four);
  print_list(head);
  delete_list(head);
  return 0;
}
