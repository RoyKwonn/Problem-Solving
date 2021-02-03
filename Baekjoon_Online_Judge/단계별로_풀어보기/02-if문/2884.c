//
//  2884.c
//  Algorithm-Baekjoon
//
//  Created by Seokhwan Kwon on 2021/01/20.
//

#include <stdio.h>

int main()
{
    int H, M;
    
    while(1)
    {
        scanf("%d %d", &H, &M);
        if(H >= 0 && H < 24 && M >= 0 && M < 60) break;
        
        printf("error\n");
    }
    
    if(M < 45)
    {
        H = (H + 24 - 1) % 24;
        M = (M + 60 - 45) % 60;
    }
    else M -= 45;
    
    printf("%d %d", H, M);
    
    return 0;
}
