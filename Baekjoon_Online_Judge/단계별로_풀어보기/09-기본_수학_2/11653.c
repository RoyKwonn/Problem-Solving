//
//  11653.c
//  Algorithm-Baekjoon
//
//  Created by Seokhwan Kwon on 2021/01/26.
//

#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    
    for(int i = 2; i * i <= n; i++) // i는 소인수분해하기위한 가장 작은수로 유지함
    {
        if(n%i == 0)
        {
            printf("%d\n", i);
            n /= i;  // 나머지를 유지해준다.
            -- i; // i로 한번더 나누어볼 수 있도록 함
        }
    }
    
    if(n>1) // 나머지가 1보다 작을경우는 입렵값이 1일경우인데,,, 그러면 소인수 분해가 안되므로 작성해준다.
        printf("%d\n", n); // 위에서 나누고 최종 나머지임
    
}
