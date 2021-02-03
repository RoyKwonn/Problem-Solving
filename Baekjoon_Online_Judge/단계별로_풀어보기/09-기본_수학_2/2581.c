//
//  2581.c
//  Algorithm-Baekjoon
//
//  Created by Seokhwan Kwon on 2021/01/26.
//

#include <stdio.h>

int main()
{
    int M, N, i, j;
    int min = 10001, flag, sum = 0;
    
    scanf("%d", &M);
    scanf("%d", &N);
    
    for(i = M; i <= N; i++)
    {
        flag = 0;
        if(i == 1)
            continue;
        for(j = 2; j < i; j++) // 2부터 i까지 하나하나 나누어진다면 소수가 아니므로 flag를 1으로 설정한다.
        {
            if(i % j == 0) flag = 1;
        }
        
        if(flag == 0)
        {
            if(sum == 0) // 첫번째 소수를 따로 뽑아낸다.
                min = i;
            sum += i; // 소수들의 합을 구하기
        }
    }
    
    if(sum == 0)
        printf("-1\n");
    else
        printf("%d\n%d\n", sum, min);
    
    return 0;
}
