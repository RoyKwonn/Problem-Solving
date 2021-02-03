//
//  1157.c
//  Algorithm-Baekjoon
//
//  Created by Seokhwan Kwon on 2021/01/26.
//

#include <stdio.h>
#define MAX_WORD 1000001

int main()
{
    char str[MAX_WORD];
    int i, max, max_idx = 0;
    int num[26] = {0}; // 알파벳의 개수 26개 (대소문자 구분없이)
    
    scanf("%s", str);
    
    // 'A' == 65, 'a' == 97
    for(i = 0; str[i] != '\0'; i++)
    {
        // 대문자일 경우 소문자로 변환
        if(str[i] < 97)
            str[i] += 32; // 97 - 65 == 32
        num[str[i] - 97]++; // 나타난 문자 개수 증가
    }
    
    max = num[0]; // 비교 초기값
    // find max
    for(i = 1; i < 26; i++)
    {
        if(max < num[i]) // num[i]의 빈도수가 더 클 경우
        {
            max = num[i];
            max_idx = i;
        }
        else if(max == num[i] && num[i] != 0) // 최대가 한개 이상이거나, 한글자입력이라면
        {
            max_idx = -1;
        }
    }
    
    if(max_idx != -1)
        printf("%c", 65 + max_idx); // 대문자로 출력
    else
        printf("?\n");
}


