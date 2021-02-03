//
//  10430.c
//  Algorithm-Baekjoon
//
//  Created by Seokhwan Kwon on 2021/01/16.
//

#include <stdio.h>

int input_value()
{
    int i;
    while(1)
    {
        scanf("%d", &i);
        if(i >= 2 && i <= 10000) break;
        printf("error\n");
    }
    
    return i;
}

int main()
{
    int A, B, C;
    
    A = input_value();
    B = input_value();
    C = input_value();
    
    printf("%d\n", (A+B)%C);
    printf("%d\n", ((A%C) + (B%C))%C);
    printf("%d\n", (A*B)%C);
    printf("%d\n", ((A%C) * (B%C))%C);
    
    
    return 0;
}

