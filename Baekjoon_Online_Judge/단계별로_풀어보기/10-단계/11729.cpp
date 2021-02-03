//
//  11729.cpp
//  Algorithm-Baekjoon
//
//  Created by Seokhwan Kwon on 2021/01/29.
//

#include <iostream>
using namespace std;

void hanoi(int start, int mid, int end, int n)
{
    if(n == 1)
    {
        cout << start << " " << end << "\n";
    }
    else
    {
        hanoi(start, end, mid, n - 1);
        cout << start << " " << end << "\n";
        hanoi(mid, start, end, n - 1);
    }
}

int main()
{
    int n;
    cin >> n;
    cout << (1<<n) - 1 << "\n";  // shift 연산으로 제곱을 나타냄 pow는 쓰면안된다 왜? 실수형으로 계산되기 때문에
    hanoi(1, 2, 3, n);
    
    return 0;
}
