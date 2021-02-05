//
//  1546.cpp
//  Problem_solving
//
//  Created by Seokhwan Kwon on 2021/02/05.
//

#include <iostream>
#define MAX 1001

using namespace std;


int main(int argc, const char * argv[])
{
    
    int N; // 입력값
    cin >> N;
    
    int score[MAX] = {0};
    int M = 0; // 최댓값

    for(int i = 0; i < N; i++)
    {
        cin >> score[i];
        if(score[i] > M)  // 최고값이 무엇인지 확인
            M = score[i];
    }
    
    float mean = 0.0;
    
    for(int i = 0; i < N; i++)
    {
        mean += (float)score[i]/M*100; // 저장된 값의 결과를 실수형으로 저장
    }
    
    cout << fixed;
    cout.precision(2); // 소수점 아래 2자리만 출력하도록 설정
    cout << mean/N;
    
    return 0;
}
