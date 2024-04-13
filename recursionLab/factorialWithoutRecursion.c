#include<stdio.h>

int factorial(int num){
    int result = 1;
    for (int i = 1; i <= num; i++)
    {
        result = result*i; 
    }
    return result; 
}

int main(){
    int num;
    printf("enter a positive number: ");
    scanf("%d", &num);

    printf("factorial of %d is: %d", num, factorial(num));
    return 0;
}