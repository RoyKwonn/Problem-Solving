//
//  11066.cpp
//  Problem_solving
//
//  Created by Seokhwan Kwon on 2021/02/20.
//

#include<iostream>
#include <algorithm>
using namespace std;

int INF = 1000000007;
int dp[501][501];
int cost[501];
int sum[501];
int T, K, i;

int main()
{
    cin >> T;    // 2
    while (T--)
    {
        cin >> K;  // 4
        for (i = 1; i <= K; ++i)
        {
            cin >> cost[i];  // 40 30 30 50
            sum[i] = sum[i - 1] + cost[i];  // 파일 합치기
        }
        

        for (int d = 1; d < K; ++d)
        {
            for (int tx = 1; tx + d <= K; ++tx)
            {
                int ty = tx + d;
                dp[tx][ty] = INF;
                
                for (int mid = tx; mid < ty; ++mid)
                    dp[tx][ty] = min(dp[tx][ty], dp[tx][mid] + dp[mid + 1][ty] + sum[ty] - sum[tx - 1]);
            }
        }
 
        cout << dp[1][K] << endl;
    }
    
    return 0;
}

