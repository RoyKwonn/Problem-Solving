//
//  9498.c
//  Algorithm-Baekjoon
//
//  Created by Seokhwan Kwon on 2021/01/20.
//

#include <stdio.h>

int main()
{
    int i;
    
    scanf("%d", &i);
    
    if(i <= 100 && i >= 90) printf("A");
    else if(i < 90 && i >= 80) printf("B");
    else if(i < 80 && i >= 70) printf("C");
    else if(i < 70 && i >= 60) printf("D");
    else printf("F");
    
    return 0;
}
