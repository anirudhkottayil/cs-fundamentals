#ifndef TREE_H
#define TREE_H

#include <stddef.h>

typedef struct Node {
  int val;
  struct Node* right_child;
  struct Node* left_child;
} Node;

typedef struct Tree {
  size_t height;
  int balanced;
  int valid_bst;
  size_t size;
  struct Node* root;
} Tree;

Tree* create_tree();
int insert_node(Tree* tree, int val);
int is_empty(Tree* tree);
int remove_node(Tree* tree, int val);
int contains(Tree* tree, int val);
int find_min(Tree* tree, int* res);
int find_max(Tree* tree, int* res);
int floor(Tree* tree, int* res);
int ceiling(Tree* tree, int* res);
void in_order(Tree* tree);
void pre_order(Tree* tree);
void post_order(Tree* tree);
void level_order(Tree* tree); // using a queue
void lowest_common_ancestor(Tree* tree, int a, int b, int* res);
void destroy_tree(Tree* tree);

#endif
