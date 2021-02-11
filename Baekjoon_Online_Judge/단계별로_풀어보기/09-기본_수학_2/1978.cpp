//
//  1978.cpp
//  Problem_solving
//
//  Created by Seokhwan Kwon on 2021/02/09.
//

#include <iostream>
#include <cmath>
using namespace std;

int main(int argc, const char * argv[])
{
    int num;
    cin >> num;
    
    int count = num;
    int input[100] = {0, };
    
    for(int i = 0; i < num; i++){
        cin >> input[i];
        if(input[i] == 1)
            count--;
    }
    
    for(int i = 0; i < num; i++)
    {
        // 에라토스테네스의 접근법
        /*
         주어진 자연수 N이 소수이기 위한 필요 충분조건은 N이 N의 제곱근보다 크지 않은 어떤 소수로도 나눠지지 않는다.
         수가 수를 나누면 몫이 발생하게 되는데 몫과 나누는 수, 둘 중 하나는 반드시 sqrt(N)이하기 때문이다.
         */
        for(int j = 2; j <= sqrt(input[i]); j++)
        {
            if(input[i] % j == 0)
            {
                count--;
                break;
            }
        }
    }
    cout << count;

    return 0;
}
