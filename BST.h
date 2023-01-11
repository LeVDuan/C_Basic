#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node_s {
    char word[1024]; // giới hạn 1 từ 1024 kí tự
    int count;       // tần số của word
    struct node_s *left;
    struct node_s *right;
} node_t;

typedef node_t *tree_t;

tree_t Search(char* word, tree_t Root);
void Insertnode_t(char* newWord, tree_t *pRoot);
void printInorder(tree_t root, FILE *p);
void freetree(tree_t tree);