//
//  2908.c
//  Algorithm-Baekjoon
//
//  Created by Seokhwan Kwon on 2021/01/26.
//

#include <stdio.h>

int main()
{
    char a[4], b[4]; // 백의자리수와 + NULL == 4
    int i, j;
    
    scanf("%s %s", a, b);
    
    // 뒷자리가 같으면 그다음으로...
    // 두수는 같지 않기때문에 아래처럼 구성
    for(i = 2; i >= 0; i--)
    {
        if(a[i] > b[i])
        {
            // 출력을 거꾸로 하기 위함
            for(j = 2; j >= 0; j--) printf("%c", a[j]);
            break;
        }
        else if(a[i] < b[i])
        {
            for(j = 2; j >= 0; j--) printf("%c", b[j]);
            break;
        }
    }
    
    return 0;
}
