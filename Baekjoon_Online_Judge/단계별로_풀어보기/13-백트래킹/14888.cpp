//
//  14888.cpp
//  Problem_solving
//
//  Created by Seokhwan Kwon on 2021/02/04.
//

// 식의 계산은 연산자 우선순위를 무시하고 앞에서부터 진행해야한다.
// 나눗셈은 정수의 몫만 취한다.
// 음수를 양수로 나눌 때는 C++14의 기준을 따른다. (즉, 양수로 바꾼뒤 몫을 취하고, 그 몫을 음수로 바꾼 것과 같다.


#include <iostream>
using namespace std;

int N;              // 수의 개수
int operands[11];   // 수열 (크기 : 2 <= N <=11)
int operators[4];   // 연산자의 개수 ( +, 0, X, /)


// (-10억 <= 출력 <= 10억)이라는 조건이 있다.
int MIN = 1000000001;
int MAX = -1000000001;


// 재귀적 호출을 위하여 래퍼런스를 받는다.
void get_answer(int result, int idx)
{
    if(idx == N) // 현재 인덱스가 마지막 수에 도달했다면,
    {
        if(result > MAX)
            MAX = result;
        if(result < MIN)
            MIN = result;
        return;
    }
    
    for(int i = 0; i < 4; i++)
    {
        // operator값이 있는 경우
        if(operators[i] > 0)
        {
            // 연산자 하나 사용했으므로
            operators[i]--;
            
            if(i == 0)
                get_answer(result + operands[idx], idx + 1);
            else if(i == 1)
                get_answer(result - operands[idx], idx + 1);
            else if(i == 2)
                get_answer(result * operands[idx], idx + 1);
            else if(i == 3)
                get_answer(result / operands[idx], idx + 1);
            // 위의 재귀호출이 끝났으므로 연산자 사용한 것을 복구하여준다.
            operators[i] ++;
        }
            
    }
    return;
}

int main(int argc, const char * argv[])
{
    ios_base::sync_with_stdio(0);

    cin >> N; // 입력할 총 개수
    
    for(int i = 0; i < N; i++)
    {
        // 값 하나하나 읽어온다.
        cin >> operands[i];
    }
    
    for(int i = 0; i < 4; i++)
    {
        // 사용할 연산자의 개수를 받아온다.
        cin >> operators[i];
    }
    
    get_answer(operands[0], 1);
    cout << MAX << "\n";
    cout << MIN;
    
    return 0;
}
