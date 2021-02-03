//
//  2439.c
//  Algorithm-Baekjoon
//
//  Created by Seokhwan Kwon on 2021/01/20.
//

#include <stdio.h>

int main()
{
    int T;
    
    scanf("%d", &T);
    
    for(int i = 0; i < T; i++)
    {
        for(int j = 1; j < T-i; j++)
            printf(" ");
        for(int j = 0; j <= i; j++)
            printf("*");
        printf("\n");
    }
    
    return 0;
}
