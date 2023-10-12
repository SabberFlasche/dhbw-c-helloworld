#include <stdio.h>

int main() {
   printf("Hello World!\n");
   int a;
   scanf("%d", &a);
   switch (a){
      case 0:
         printf("You chose 0");
         break;
      case 1:
         printf("You chose 1");
         break;
      case 2:
         printf("You chose 2");
         break;
      default:
         printf("Unkown selection!");
         break;
   }
   printf("\n");
   printf("%d\n", a);
}