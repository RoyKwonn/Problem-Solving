//
//  1110.c
//  Algorithm-Baekjoon
//
//  Created by Seokhwan Kwon on 2021/01/20.
//

#include <stdio.h>

int main()
{
    int i, j, result, N = 0;
    scanf("%d", &i);
    
    result = i;
    
    do
    {
        j = i%10; // 1의 자리 수
        i = i/10; // 10의 자리 수
        i = j*10 + (i+j)%10;
        N++;
    }while(result != i);
    
    printf("%d\n", N);
    
    return 0;
}
