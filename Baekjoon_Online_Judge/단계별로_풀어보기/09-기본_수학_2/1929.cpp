//
//  1929.cpp
//  Problem_solving
//
//  Created by Seokhwan Kwon on 2021/02/09.
//

#include <iostream>
#include <cmath>
using namespace std;

int number = 1000000;
int primeNum[1000001];

void primeNumberSieve()
{
    for (int i = 2; i <= number; i++)
    {
        primeNum[i] = i;
    }

    for (int i = 2; i <= sqrt(number); i++)
    {
   
        if (primeNum[i] == 0)
            continue;
  
        for (int j = i * i; j <= number; j += i)
            primeNum[j] = 0;
    }
}

int main()
{
    int M, N;
    cin >> M >> N;
    primeNumberSieve();
    for (int i = M; i <= N; i++)
    {
        if (primeNum[i] != 0)
            cout << primeNum[i] << '\n';
    }
    return 0;
}
