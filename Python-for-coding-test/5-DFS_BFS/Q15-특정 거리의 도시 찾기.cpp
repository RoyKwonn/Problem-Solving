//  Created by Seokhwan Kwon

// 실제로 테스트 사이트에서 실행시킬땐 #include 중에서 아래 주석처리한것만 포함
// #include <bits/stdc++.h>


#include <iostream>
#include <string.h>
#include <vector>
#include <queue>

using namespace std;

int main(void)
{
    int visited[300001];

    int N, M, K, X; // 첫째 줄에 도시의 개수 N, 도로의 개수 M, 거리 정보 K, 출발 도시의 번호 X
    scanf("%d %d %d %d", &N, &M, &K, &X);

    vector<vector<int>> arr(N+1);
    int s, d;

    for(int i = 0; i < M; i++)
    {
        scanf("%d %d", &s, &d);
        arr[s].push_back(d);
    }

    vector<int> result;
    queue<pair<int, int>> q;
    q.push({ X, 0}); // 시작지점, 깊이 0
    visited[X] = 1;

    while(!q.empty())
    {
        int curNum = q.front().first;
        int curDepth = q.front().second;
        q.pop();

        if(curDepth == K) // 거리와 방문 깊이가 같으면 정답
        {
            result.push_back(curNum);
        }
        for(int i = 0; i < (signed)arr[curNum].size(); i++)
        {
            int nextNum = arr[curNum][i];

            if (!visited[nextNum])
            {
                visited[nextNum] = 1;
                q.push({nextNum, curDepth + 1});
            }
        }
    }


    if(result.size() == 0) // 정답이 없으면 -1 출력
    {
        printf("-1\n");
        return 0;
    }

    sort(result.begin(), result.end()); // 정렬

    for(auto a : result)
        printf("%d\n", a);


    return 0;
}
