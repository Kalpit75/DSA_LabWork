#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main() {

    // Dynamically allocate memory for an integer
    int *num = (int *)malloc(sizeof(int));
    *num = 42;
    printf("Integer: %d\n", *num);

    // Dynamically allocate memory for a character
    char *ch = (char *)malloc(sizeof(char));
    *ch = 'A';
    printf("Character: %c\n", *ch);
    
    // Dynamically allocate memory for a string
    char *str = (char *)malloc(sizeof(char) * 10);
    strcpy(str, "Hello");
    printf("String: %s\n", str);
    
    // Free the dynamically allocated memory
    free(num);
    free(ch);
    free(str);
    return 0;
}
