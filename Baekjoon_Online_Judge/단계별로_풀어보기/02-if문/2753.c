//
//  2753.c
//  Algorithm-Baekjoon
//
//  Created by Seokhwan Kwon on 2021/01/20.
//

#include <stdio.h>

int main()
{
    int i;
    
    scanf("%d", &i);
    
    if((i%4 == 0) && (i%100 != 0) || (i%400 == 0))
        printf("1");
    else printf("0");
    
    return 0;
}

