#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#pragma region Main 1

void printLine(char *ptr, int treeHeight, int lineNum) {
    int treeNum = 1 + lineNum * 2;
    int prefixSize = treeHeight - lineNum - 1;

    memset(&ptr[prefixSize], (int) '*', treeNum);
    memset(ptr, (int) ' ', prefixSize);

    //printf("%s\n", ptr);
    puts(ptr);
}

void printTree(int height) {
    int lineWidth = height + height;
    char *ptr = (char *) malloc(sizeof(char) * (height + height));
    ptr[lineWidth - 1] = '\0';

    for (int i = 0; i < height; i++) {
        printLine(ptr, height, i);
    }

    free(ptr);
    
    printf("%*s\n", height, "|");
    printf("%*s\n", height, "|");
}

int main1(int height) {
    printTree(height);
    return 0;
}

#pragma endregion

#pragma region Main 2

void draw_tree(int hoehe);
void print_char(char c, int n);

int main2(int height) {
    draw_tree(height);
    return 0;
}

void draw_tree(int hoehe) {
    for (int i = 1; i <= hoehe; i++) {
        // Die oberste Zeile im Baum hat links (und rechts) noch Platz für
        // hoehe-1 weitere Sterne. In der zweiten sind es hoehe-2 usw. bis
        // die letzte Zeile keine Leerzeichen mehr hat.
        print_char(' ', hoehe - i);

        // Der Baum hat in jeder Zeile eine ungerade Anzahl von Sternen.
        // In der obersten Zeile gibt es einen Stern, dann sind es 3, dann 5 usw.
        print_char('*', 2 * i - 1);

        //printf("\n");
        puts("");
    }

    for (int i = 0; i < 2; i++) { // Höhe des Stamms = 2 Zeilen
        print_char(' ', hoehe - 1);
        printf("|\n");
    }
}

// Gibt das Zeichen `c` n mal aus.
void print_char(char c, int n) {
    while(n--) {
        printf("%c", c);
    }
}

#pragma endregion

int main(int argc, char const *argv[]) {
    int height;

    fputs("Enter Tree Height: ", stdout);
    scanf("%i", &height);

    clock_t begin1 = clock();

    main1(height);

    clock_t end1 = clock();
    double time_spent1 = (double)(end1 - begin1) / CLOCKS_PER_SEC;
    

    clock_t begin2 = clock();

    main2(height);

    clock_t end2 = clock();
    double time_spent2 = (double)(end2 - begin2) / CLOCKS_PER_SEC;

    printf("Tree 1: %f\n", time_spent1);
    printf("Tree 2: %f\n", time_spent2);

    return 0;
}

