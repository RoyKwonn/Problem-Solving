//
//  2562.c
//  Algorithm-Baekjoon
//
//  Created by Seokhwan Kwon on 2021/01/20.
//


#include <stdio.h>

int main()
{
    int a[9] = {0};
    int max = 0;
    
    for(int i = 0; i < 9; i++)
    {
        while(1)
        {
            scanf("%d", &a[i]);
            if(a[i] < 100 && a[i] > 0) break;
        }
    }
    
    for(int i = 1; i < 9; i++)
    {
        if(a[max] < a[i]) max = i;
    }
    
    printf("%d \n%d",a[max], max + 1);
    
    return 0;
}

