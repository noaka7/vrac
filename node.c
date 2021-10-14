#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

// do not modify Node
typedef struct Node {
  int value;
  struct Node *left;
  struct Node *right;
} Node;

Node *find(Node *node, int v) {
  Node *n = node;
  while (1) {
    if (NULL == n) {
      return NULL;
    } else if (v < n->value) {
      n = n->left;
    } else if (v > n->value) {
      n = n->right;
    } else {
      return n;
    }
  }
}

void insert(Node **node, int v) {
  if (NULL == *node) {
    *node = (Node *)malloc(sizeof(Node));
    assert(NULL != *node);
    (*node)->value = v;
    (*node)->left = NULL;
    (*node)->right = NULL;
  } else if (v < (*node)->value) {
    insert(&((*node)->left), v);
  } else if (v > (*node)->value) {
    insert(&((*node)->right), v);
  }
}

void free_node(Node *node) {
  if (NULL != node) {
    free(node->left);
    free(node->right);
    free(node);
  }
}

void traversal(Node *node) {
  if (NULL != node) {
    traversal(node->left);
    printf("%d ", node->value);
    traversal(node->right);
  }
}

int main() {
  /* * * * * * /
         9
        / \
       7   13
      / \    \
     5   8   17
    / \     /
   2   6   16
  / * * * * * */
  Node *small = NULL;
  insert(&small, 9);
  insert(&small, 7);
  insert(&small, 13);
  insert(&small, 5);
  insert(&small, 8);
  insert(&small, 17);
  insert(&small, 2);
  insert(&small, 6);
  insert(&small, 16);

  Node *n1 = find(small, 8); // 8
  if (n1 != NULL) {
    printf("%d\n", n1->value);
  } else {
    printf("NULL\n");
  }

  // Node *n2 = find(large, 0); // 0
  // if (n2 != NULL) {
  //   printf("%d\n", n2->value);
  // } else {
  //   printf("NULL\n");
  // }

  free_node(small);

  return 0;
}
