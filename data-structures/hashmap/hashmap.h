#ifndef HASHMAP_H
#define HASHMAP_H

#include <stddef.h>
#define HM_SUCCESS 0
#define HM_FAIL 1
#define HM_MEM_FAIL -1

typedef struct Pair{
  int key;
  char* val;
  struct Pair* next;
} Pair;

typedef struct {
  size_t size;
  size_t capacity;
  Pair** arr;  
} HashMap;

HashMap* create_hashmap(size_t capacity);
int insert(int key, char* val, HashMap* hashmap);
int get(int key, HashMap* hashmap, char** res);
int remove_pair(int key, HashMap* hashmap);
int contains(int key, HashMap* hashmap);
void destroy_map(HashMap* hashmap);
double load_factor(size_t size, size_t capacity);
void print_map(HashMap* hashmap);

#endif
