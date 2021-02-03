//
//  3052.c
//  Algorithm-Baekjoon
//
//  Created by Seokhwan Kwon on 2021/01/20.
//


#include <stdio.h>
#define MAX 42

int check_value(int i)
{
    if(i >= 0 && i < 1000)
        return 1;
    
    printf("error! you should input again.\n");
    return 0;
}

int main()
{
    int a[10] = {0};
    int r[MAX] = {0};
    int temp;
    
    for(int i = 0; i < 10; i++)
    {
        while(1)
        {
            scanf("%d", &a[i]);
            if(check_value(a[i])) break;
        }
        temp = a[i] % 42;
        
        r[temp] += 1;
    }
    
    // 초기화
    temp = 0;
    
    for(int i = 0; i < MAX; i++)
    {
        if(r[i] != 0)
            temp += 1; // 서로 다른 갯수 카운트
    }
    
    printf("%d", temp);
    
    return 0;
}
