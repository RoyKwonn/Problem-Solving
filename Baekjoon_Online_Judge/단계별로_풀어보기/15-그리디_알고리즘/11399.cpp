//
//  11399.cpp
//  Problem_solving
//
//  Created by Seokhwan Kwon on 2021/02/07.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 줄서는사람 N명
// i번 사람이 돈을 인출하는데 걸리는 시간 P-i-분
// 돈을 인출하는데 최소가 되는 시간
// 경로가 짧은 순으로 정렬하는 그리디 알고리즘

int cmp(int a, int b)
{
    return a < b; // 작은순으로 정렬
}

int main(int argc, const char * argv[])
{
    ios_base::sync_with_stdio(false);
    
    int N;
    cin >> N;
    int sum = 0, ans = 0;
    
    vector<int> v(N);
    
    for(int i = 0; i < N; i++)
    {
        cin >> v[i];
    }
    
    sort(v.begin(), v.end(), cmp); // 정렬로 구현함
    
    for(int i = 0; i < N; i++)
    {
        sum += v[i]; // i번째 사람이 기다려야하는 시간
        ans += sum;  // 총 누적대기시간
    }
    
    cout << ans << "\n";
    
    return 0;
}
