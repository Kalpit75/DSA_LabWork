#include<stdio.h>

int factorial(int x){
    
   if(x >=1){
    return x*factorial(x-1);
   } 
   else{
    return 1;
   }
    
}

int main(){
    int num;
    printf("enter a number to calculate factorial: ");
    scanf("%d", &num);
    int result = factorial(num);
    printf("factorial: %d", result);
    return 0;
}