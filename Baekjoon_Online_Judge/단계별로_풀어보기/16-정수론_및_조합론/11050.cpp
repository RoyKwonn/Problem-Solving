//
//  11050.cpp
//  Problem_solving
//
//  Created by Seokhwan Kwon on 2021/02/07.
//

#include <iostream>
using namespace std;


int factorial(int n)
{
    int res = 1;
    
    for(int i = n; i > 0; i--)
    {
        res *= i;
    }
    return res;
}


// 이항계수란,  (a + b)^{n}일때, a^{r}b^{n-r}의 계수를 구하는 것
int main(int argc, const char * argv[])
{
    ios_base::sync_with_stdio(false);
    
    int N, K;
    int ans;
    cin >> N >> K;
    
    ans = factorial(N)/(factorial(K) * factorial(N-K));
    cout << ans;
    
    return 0;
}
