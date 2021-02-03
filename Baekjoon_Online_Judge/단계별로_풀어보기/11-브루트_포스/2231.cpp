//
//  2231.cpp
//  Algorithm-Baekjoon
//
//  Created by Seokhwan Kwon on 2021/01/29.
//

#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    long N;
    cin >> N;
    
    long M = N;
    int digit = 0;
    
    // 숫자의 자리수
    while(M)
    {
        M /= 10;
        digit++;
    }
    
    // 분해합은 최소 N - 9 * digit 부터 시작
    long begin = N - 9 * digit;
    char str[10];
    long sum = 0;
    bool find = false;
    
    for(long i = begin; i <= N; ++i)
    {
        sprintf(str, "%ld", i); // i를 %ld형태로 문자열 s에 저장
        sum = i;
        for(int j = 0; j < strlen(str); ++j)
            sum += str[j] - '0'; // 윗자리부터 순서대로 더하기
        if(sum == N)
        {
            find = true;
            cout << i << "\n";
            break;
        }
    }
    
    // 찾지 못한 경우
    if(find == false)
        cout << "0\n";
    
    return 0;
}
