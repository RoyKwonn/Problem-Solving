//
//  10872.cpp
//  Algorithm-Baekjoon
//
//  Created by Seokhwan Kwon on 2021/01/29.
//

#include <iostream>
using namespace std;


int factorial(int n)
{
    if(n > 2)
    {
        n *= factorial(n - 1);
    }
    return n;
}

int main()
{
    int num, result = 1;
    cin >> num;
    if(num > 0)
        result = factorial(num);
    cout << result << endl;
    return 0;
}
