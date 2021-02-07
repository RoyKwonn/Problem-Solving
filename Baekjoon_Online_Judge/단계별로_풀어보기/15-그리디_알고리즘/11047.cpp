//
//  11047.cpp
//  Problem_solving
//
//  Created by Seokhwan Kwon on 2021/02/07.
//

#include <iostream>
#include <vector>
#include <algorithm>

#define N_MAX 10
#define K_MAX 100000000
using namespace std;


int cmp(int a, int b)
{
    return a > b;
}


int main(int argc, const char * argv[])
{
    ios_base::sync_with_stdio(false);
    
    int N, K;  // N은 동전의 종류, K는 결과 가격
    int ans = 0;
    
    cin >> N >> K;
    vector<int> v(N);
    // 배열로 풀었을땐, 속도가 느리다고 나왔는데
    // 백터로 풀으니 속도가 훨씬 빨라졌다.
    
    for(int i = 0; i < N; i++)
    {
        cin >> v[i];
    }
    
    sort(v.begin(), v.end(), cmp);
    
    for(int i = 0; i < N; i++)
    {
        while(K - v[i] >= 0){
            K -= v[i];
            ans++;
        }
    }
    
    cout << ans << "\n";
    return 0;
}
