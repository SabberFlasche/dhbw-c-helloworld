#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printLine(int treeHeight, int lineNum) {
    int treeNum = 1 + lineNum * 2;
    int prefixSize = treeHeight - lineNum - 1;

    char *ptr = (char *) malloc(sizeof(char) * (prefixSize + treeNum + 1));
    ptr[treeNum] = '\0';
    memset(&ptr[prefixSize], (int) '*', treeNum);
    memset(ptr, (int) ' ', prefixSize);

    //printf("%s\n", ptr);
    puts(ptr);

    free(ptr);
}

void printTree(int height) {
    for (int i = 0; i < height; i++) {
        printLine(height, i);
    }
    
    printf("%*s\n", height, "|");
    printf("%*s\n", height, "|");
}

int main(int argc, char const *argv[]) {
    int height;

    //printf("Enter Tree Height: ");
    fputs("Enter Tree Height: ", stdout);
    scanf("%i", &height);

    printTree(height);
    return 0;
}
