//
//  11720.c
//  Algorithm-Baekjoon
//
//  Created by Seokhwan Kwon on 2021/01/26.
//

#include <stdio.h>

int main()
{
    int N = 0, sum = 0, i;
    char num[100] = {0};
    
    scanf("%d", &N);
    scanf("%s", num);
    
    for(i = 0; i < N; i++)
    {
        sum += num[i] - '0';
    }
    
    printf("%d", sum);
    
    return 0;
}
