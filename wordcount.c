#include <ctype.h>
#include "BST.h"

tree_t wordList = NULL; // tạo cây BST để lưu word và tần số của nó

char inputFile[1024];
char outputFile[1024];
/**
Hàm kiểm tra xem kí tự ch có phải là kí tự hợp lệ của 1 từ không?
trả về 1 nếu hợp lệ, ngược lại trả về 0
**/
int isWordChar(char ch) {
   if(('a' <= ch && ch <='z') || ('A' <= ch && ch <='Z') || ('0' <= ch && ch <='9') ) {
      return 1;
   } else 
      return 0;
}

/**
Hàm nhận tham số là tên của file input
- Đọc file theo từng kí tự
- Kiểm tra các kí tự 
- nhận biết các từ và chèn vào cây nhị phân tìm kiếm (sử dụng thư viện BST.h)
**/
void readFile(char* input) {
   FILE* p = fopen(input, "r");
   if(p == NULL) {
      printf("Can't open file %s\n", input);
   } else {
      char ch;
      char tmp[1024] = {0}; // biến lưu tạm các kí tự đọc để lấy word
      int i = 0;
      tree_t nodeTmp = NULL; // biến lưu node trong BST khi tìm kiếm trong cây
      
      while (ch != EOF) {
         ch = fgetc(p);
         if(ch != EOF) {
            // chuẩn hóa từ thành chữ IN HOA bằng cách chuẩn hóa các kí tự thành IN HOA
            tmp[i] = toupper(ch);

            // kiểm tra kí tự vừa đọc được có phải là 1 kí tự ngăn cách không
            if(isWordChar(ch) == 0){

               // nếu i = 0 : chỉ có 1 kí tự đọc được và nó ko phải là 1 kí tự của từ nên bỏ qua
               if(i != 0) {
                  tmp[i] = '\0'; // kết thúc chuỗi để lấy word

                  // chèn word lưu ở tmp vào BST
                  // tìm trong cây -> nếu chưa có -> chèn ngược lại -> tăng biến count của word đó
                  nodeTmp = Search(tmp, wordList);
                  if(nodeTmp == NULL) {
                     Insertnode_t(tmp, &wordList);
                  } else {
                     nodeTmp->count++;
                  }
               }
               i = -1; // vì vòng ngoài lặp với i++ nên gán = -1 để khi đến vòng lặp tiếp theo i = 0
            }
            i++;
         }
      }
      fclose(p);
   }
}


int main( int argc, char *argv[] )  
{
   // kiểm tra đủ tham số hay không
   if( argc == 3 )
   {
      // lưu tên file vào các biến
      strcpy(inputFile,argv[1]); 
      strcpy(outputFile,argv[2]);

      readFile(inputFile);

      // mở file outputFile để ghi
      FILE *p = fopen(outputFile, "w");
      if(p == NULL) {
      printf("Can't open file %s\n", outputFile);
      } else {
         printInorder(wordList, p); // ghi thông tin trong cây vào file có con trỏ là p
      }
   // các trường hợp tham số không hợp lệ
   } else if( argc > 3 ){
      printf("Quá nhiều tham số!\nĐịnh dạng tham số dòng lệnh:\n   ./wordcount tên_file_input tên_file_output\n");
      return 0;
   } else
   {
      printf("Cung cấp thiếu tham số!\nĐịnh dạng tham số dòng lệnh:\n   ./wordcount tên_file_input tên_file_output\n");
      return 0;
   }
   // giải phóng cây
   freetree(wordList);
   return 1; 
}