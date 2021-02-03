//
//  4673.c
//  Algorithm-Baekjoon
//
//  Created by Seokhwan Kwon on 2021/01/26.
//

#include <stdio.h>
#define MAX_NUM 10000

void self_num()
{
    int i, res = 0;
    int arr[MAX_NUM + 1] = {0};
    
    // self_num 찾기
    for(i = 1; i <= MAX_NUM; i++)
    {
        if(i < 10)
        {
            res = i + i;
            arr[res] = 1;
        }
        else if(i < 100)
        {
            res = i + (i/10) + (i%10);
            arr[res] = 1;
        }
        else if(i < 1000)
        {
            res = i + (i/100) + ((i%100)/10) + ((i%100)%10);
            arr[res] = 1;
        }
        else if(i < MAX_NUM)
        {
            res = i + (i/1000) + ((i%1000)/100) + (((i%1000)%100)/10) + (((i%1000)%100)%10);
            if(res <= MAX_NUM)
            {
                arr[res] = 1;
            }
        }
    }
    
    for(i = 1; i <= MAX_NUM; i++)
    {
        if(arr[i] != 1) // 위 방법들로 찾아지지 않은 수만 표시하기
            printf("%d\n", i);
    }
}


int main()
{
    self_num();
    return 0;
}


