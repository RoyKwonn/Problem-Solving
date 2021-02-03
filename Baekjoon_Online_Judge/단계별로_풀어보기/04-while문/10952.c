//
//  10952.c
//  Algorithm-Baekjoon
//
//  Created by Seokhwan Kwon on 2021/01/20.
//

#include <stdio.h>

int main()
{
    int A, B;
    
    while(1)
    {
        scanf("%d %d", &A, &B);
        if(A == 0 && B == 0) break;
        printf("%d\n", A+B);
        
    }
    
    
    return 0;
}
