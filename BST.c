#include "BST.h"
/**
Hàm sử dụng đệ quy để tìm từ "word" có trong cây (Root) hay không
Trả về NULL nếu không tìm thấy
Ngược lại trả về node chứa "word"
**/
tree_t Search(char* word, tree_t Root) {
    if (Root == NULL)
        return NULL;           // Không tìm thấy
    else if ( strcmp(Root->word, word) == 0)  //tìm thấy
        return Root;
    else if (strcmp(Root->word, word) < 0) 
        return Search(word, Root->right);
    else {
        return Search(word, Root->left);
    }
    }

/**
Hàm chèn một node với từ là "newWord" và count gán bằng 1 vào cây Root
**/
void Insertnode_t(char* newWord, tree_t *Root) {
  if (*Root == NULL) {
    *Root = (node_t *)malloc(sizeof(node_t));
    strcpy((*Root)->word, newWord);
    (*Root)->count = 1;
    (*Root)->left = NULL;
    (*Root)->right = NULL;
  } else if (strcmp(newWord, (*Root)->word) < 0)
    Insertnode_t(newWord, &((*Root)->left));
  else if (strcmp(newWord, (*Root)->word) > 0)
    Insertnode_t(newWord, &((*Root)->right));
}

/**
Hàm in thông tin các từ và tần số vào file được trỏ bởi p theo định dạng:
word count
**/
void printInorder(tree_t root, FILE* p) 
{ 
    if (root == NULL) return; 
    printInorder(root->left, p); 
    fprintf(p,"%s %d\n", root->word, root->count);
    printInorder(root->right,p); 
} 


/**
Hàm giải phóng bộ nhớ của cây
**/
void freetree(tree_t tree) {
    if (tree != NULL) {
        freetree(tree->left);
        freetree(tree->right);
        free((void *)tree);
    }
}
