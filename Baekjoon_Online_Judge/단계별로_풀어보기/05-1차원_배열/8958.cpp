//
//  8958.cpp
//  Problem_solving
//
//  Created by Seokhwan Kwon on 2021/02/05.
//

#include <iostream>
#include <cstring>
using namespace std;

int main(int argc, const char * argv[])
{
    // 필자는 입출력이 여러개라서 2차원 동적배열로 풀어보려 했다가
    // 범례가 1차원 배열이라 아래처럼 풀었다.
    
    
    int N;
    cin >> N; // 입력받는 수
    
    char s[81]; // 저장할 문자열
    
    int score;
    int count;
    
    for(int i = 0; i < N; i++)
    {
        score =0;
        count =0;
        cin >> s;
        for(int j = 0; j < strlen(s); j++)
        {
            if(s[j] == 'O'){
                score += ++count; // count를 먼저 증가하고 socre에 더해주기
            } else {
                count = 0;
            }
        }
        cout << score << "\n";
    }
    
    
    return 0;
}
