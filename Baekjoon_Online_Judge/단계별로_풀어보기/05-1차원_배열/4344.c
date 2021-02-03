//
//  4344.c
//  Algorithm-Baekjoon
//
//  Created by Seokhwan Kwon on 2021/01/20.
//

#include <stdio.h>

int main()
{
    int count;
    int n;
    int score[1000], sum = 0;
    int over = 0;
    
    double avg = 0.00;
    
    
    scanf("%d", &count); // [입력1] 전체 실행 횟수
    
    for(int i = 0; i < count; i++)
    {
        sum = 0;
        scanf("%d", &n);    // [입력2] 평균을 계산하기 위한
        
        for(int j = 0; j < n; j++) // 시그마
        {
            scanf("%d", &score[j]);
            sum += score[j];
        }
        
        avg = (double)sum/n; // [출력] 평균
        
        over = 0;
        for(int j = 0; j < n; j++)
        {
            if(avg < score[j])
                over++;
        }
        printf("%.3f%%\n", (double)over*100/n);
        
    }
    
    return 0;
}
