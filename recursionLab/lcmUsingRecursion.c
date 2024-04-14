#include <stdio.h>

int lcm(int n1, int n2) {
    static int lowestcm = 1;    
    if(lowestcm%n1 == 0 && lowestcm%n2 == 0)
    {
        return lowestcm;
    }
    else
    {
        lowestcm++;
        lcm(n1,n2);
        return lowestcm;
    }
}


int main() {
    int n1 , n2 ;
    printf("enter any two numbers: ");
    scanf("%d%d", &n1, &n2);
    printf("L.C.M of %d and %d is %d.", n1, n2, lcm(n1, n2));
    return 0;
}