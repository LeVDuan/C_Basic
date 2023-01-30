#include "BSTree.h"

int main(){
  char choice;
  treeType root;
  makeNullTree(&root);
  elementType sv1, sv2, sv3;
  strcpy(sv1.username, "ANh DM");
  strcpy(sv2.username, "NHUNG LT");
  strcpy(sv3.username, "DUAN LV");


  while(1){
    printf("           ---MENU---\n"
	   "|1.   \n"
	   "|2.                   \n"
	   "|3.             \n"
	   "|4.        \n"
	   "|5.        \n"
	   "|6. Quit.           |\n");

    __fpurge(stdin);
    printf("Input your choice: ");
    scanf("%c", &choice);

    while(choice > '6' || choice < '1'){
      __fpurge(stdin);
      printf("Ivalid! Input your choice: ");
      scanf("%c", &choice);
    }
    
    switch(choice){
    case '1':{
      insertNode(sv1, &root);
      insertNode(sv2, &root);
      insertNode(sv3, &root);
      break;
    }

    case '2':{
      inOrderPrint(root);
      break;
    }

    case '3':{
      deleteNode("Duan LV", &root);
      break;
    }

    case '4':{

      break;
    }

    case '5':{

      break;
    }

    case '6':{
      exit(1);
      break;
    }
    }
  }
  return 0;
}
