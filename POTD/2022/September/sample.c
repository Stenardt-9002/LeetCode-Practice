#include<stdio.h>

void main()
{
    int n ;
    scanf("%d",&n);
    for (int i1 = 0; i1 < n-1; i1++)
        printf("*\n");

    for (int i1 = 0; i1 < n; i1++)
        printf("* ");
    
}
