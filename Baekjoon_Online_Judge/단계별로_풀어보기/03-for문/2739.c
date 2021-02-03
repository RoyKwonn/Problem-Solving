//
//  2739.c
//  Algorithm-Baekjoon
//
//  Created by Seokhwan Kwon on 2021/01/20.
//

#include <stdio.h>

int main()
{
    int N;
    
    scanf("%d", &N);
    
    for(int i = 1; i < 10; i++)
        printf("%d * %d = %d\n", N, i, N*i);
    
    return 0;
}
