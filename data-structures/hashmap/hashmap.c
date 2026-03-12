#include <stdio.h>
#include "hashmap.h"
#include <stdlib.h>
#include <string.h>

HashMap* create_hashmap(size_t capacity){
  HashMap* hashmap = malloc(sizeof(HashMap));
  if (hashmap == NULL){
    perror("hashmap memory alloc failed");
    return NULL;
  }
  hashmap->size = 0;
  hashmap->capacity = (capacity == 0) ? 4 : capacity;
  hashmap->arr = malloc(hashmap->capacity * sizeof(Pair*));
  if (hashmap->arr == NULL){
    perror("hashmap arr memory alloc failed");
    free(hashmap);
    return NULL;
  }
  for (size_t i = 0; i < hashmap->capacity; i++){
    hashmap->arr[i] = NULL;
  }
  return hashmap;
}
double load_factor(size_t size, size_t capacity){
  return (double)size / capacity;
}
int hashfunc(int key, size_t capacity){
  return abs((int)(key % capacity));
}

int resize_HM(HashMap* hashmap){
  hashmap->capacity = hashmap->capacity * 2;
  Pair** new_arr = malloc(hashmap->capacity* sizeof(Pair*));
  if (new_arr == NULL){
    hashmap->capacity = hashmap->capacity/2;
    return HM_MEM_FAIL;
  }
  Pair** temp_arr = hashmap->arr;
  hashmap->arr = new_arr;
  for (size_t i = 0; i < hashmap->capacity; i++){
    hashmap->arr[i] = NULL;
  }
  hashmap->size = 0;
  for (size_t i = 0; i < hashmap->capacity/2; i++){
    Pair* temp = temp_arr[i];
    Pair* prev;
    while(temp != NULL){
      prev = temp;
      int insert_res = insert(temp->key, temp->val, hashmap);
      temp = temp->next;
      free(prev->val);
      free(prev);
    }
  }
  free(temp_arr);
  return HM_SUCCESS;

}

int insert(int key, char* val, HashMap* hashmap){
  if (load_factor(hashmap->size, hashmap->capacity) >= 0.75){
    if (resize_HM(hashmap) == HM_MEM_FAIL) return HM_MEM_FAIL;
  }
  int index = hashfunc(key, hashmap->capacity);
  Pair* temp = hashmap->arr[index];
  while (temp!= NULL && temp->key != key){
    temp = temp->next;
  }
  if (temp != NULL){
    free(temp->val);
    temp->val = strdup(val);
    return HM_SUCCESS;
  }
  Pair* new_node = malloc(sizeof(Pair));
  if (new_node == NULL){
    perror("Error allocating memory for new node");
    return HM_MEM_FAIL;
  }
  new_node->key = key;
  new_node->val = strdup(val);
  if (new_node->val == NULL){
    free(new_node);
    return HM_MEM_FAIL;
  }
  new_node->next = hashmap->arr[index];
  hashmap->arr[index] = new_node;
  hashmap->size++;
  return HM_SUCCESS;
}

int get(int key, HashMap* hashmap, char** res){
  int index = hashfunc(key, hashmap->capacity);
  Pair* temp = hashmap->arr[index];
  while (temp!= NULL && temp->key != key){
    temp = temp->next;
  }
  if (temp == NULL){
    return HM_FAIL;
  } else {
    *res = temp->val;
    return HM_SUCCESS;
  }
}

int remove_pair(int key, HashMap* hashmap){
  int index = hashfunc(key, hashmap->capacity);
  Pair* temp = hashmap->arr[index];
  Pair* prev;
  while (temp!= NULL && temp->key != key){
    prev = temp;
    temp = temp->next;
  }
  if (temp == NULL){
    return HM_FAIL;
  } else {
    if (temp == hashmap->arr[index]){
      hashmap->arr[index] = temp->next;
    } else {
      prev->next = temp->next;
    }
    free(temp->val);
    free(temp); 
    hashmap->size--;
    return HM_SUCCESS;
  }
}

int contains(int key, HashMap* hashmap){
  int index = hashfunc(key, hashmap->capacity);
  Pair* temp = hashmap->arr[index];
  while (temp!= NULL && temp->key != key){
    temp = temp->next;
  }
  if (temp == NULL){
    return HM_FAIL;
  } else {
    return HM_SUCCESS;
  }
}

void destroy_map(HashMap* hashmap){
  for (size_t i = 0; i < hashmap->capacity; i++){
    Pair* temp = hashmap->arr[i];
    Pair* prev;
    while(temp != NULL){
      prev = temp;
      temp = temp->next;
      free(prev->val);
      free(prev);
    }
  }
  free(hashmap->arr);
  free(hashmap);
}

void print_map(HashMap* hashmap){
  for (size_t i = 0; i < hashmap->capacity; i++){
    printf("Index %zu: ", i);
    Pair* temp = hashmap->arr[i];
    while(temp != NULL){
      printf("[%d, %s]", temp->key, temp->val);
      temp = temp->next;
    }
    printf("\n");

  }
}
