//
//  10869.c
//  Algorithm-Baekjoon
//
//  Created by Seokhwan Kwon on 2021/01/16.
//

#include <stdio.h>

int main()
{
    int A, B;
    
    while(1)
    {
        scanf("%d", &A);
        if (A >= 1 && A <= 10000) break;
        printf("error\n");
    }
    
    while(1)
    {
        scanf("%d", &B);
        if (B >= 1 && B <= 10000) break;
        printf("error\n");
    }
    
    printf("%d\n", A+B);
    printf("%d\n", A-B);
    printf("%d\n", A*B);
    printf("%d\n", A/B);
    printf("%d\n", A%B);
    
    return 0;
}
