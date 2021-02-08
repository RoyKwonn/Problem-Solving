//
//  14502.cpp
//  Problem_solving
//
//  Created by Seokhwan Kwon on 2021/02/08.
//

// 1. 이 문제는 브루트포스(완전탐색)와 BFS/DFS 2가지 알고리즘을 모두 사용해야 한다.
// 2. 0이 있는 지점에서 만들 수 있는 3개의 벽을 다 만들어 본 후에, BFS/DFS를 통해서 바이러스가 있는 지점에서 바이러스를 모두 퍼뜨려 본 후에, 안전 영역의 크기(0의 갯수)를 Count해줘서 최댓값을 찾으면 된다.
// 3. 2)와 같은 작업을 하기 위해서는 맵을 복사하는 과정이 있어야 한다. 원본맵에 그대로 했다가는, 원본 맵을 잃어버릴 수 있기 때문이다.
// 4. 2)에서 말한 '만들 수 있는 3개의 벽을 다 만들어 본 후에'이 과정에서, 조합의 개념이 들어간다. 모든 0중에서 3개를 골라야 하기 때문이다. 이 부분 때문에 나는 Check[]라는 1차원 배열을 사용했고, 이 배열의 Max크기는 64로 설정해주었다. (한 변의 최대길이가 8이므로, 8x8일 때, 0이 들어갈 수 있는 최대 갯수는 64개 이므로)
//      4-1) 입력을 받을 때, 0의 갯수를 모두 Count해 주었다. 0이 있는 지점을 모두 Queue에 넣어주었고 Queue의 Size를 통해서 0의 갯수를 파악하였다.
//      4-2) 조합을 구하고 최종 결과값 까지 구하는 과정을 순서대로 적어보자면..
//          1. 모든 0중에서 3개를 고른다.
//          2. 원본의 맵을 임시 맵(C_MAP)으로 복사한다.
//          3. 고른 3개의 0에 대해서, 그 값을 1로 바꾸어준다. (복사한 맵에서)
//          4. BFS / DFS를 통해서 복사한 맵에서 바이러스를 퍼뜨린다.
//          5. 모두 퍼뜨린 후에, 남아있는 0의 값을 Count하고 이전까지의 최대값과 비교하여 갱신해준다.



#include <iostream>
#include <cstring>
#include <vector>
#include <queue>

#define endl "\n"
#define MAX 8
using namespace std;

int N, M, Space, Answer;    // 지도 사이즈
int MAP[MAX][MAX];          // 현재 지도
int C_MAP[MAX][MAX];
bool Check[MAX * MAX];
bool Visit[MAX][MAX];

int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

vector<pair<int, int>> Empty, Virus;

int Bigger(int A, int B) { if (A > B) return A; return B; }
 
void Input()
{
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> MAP[i][j];
            if (MAP[i][j] == 0) Empty.push_back(make_pair(i, j));
            else if (MAP[i][j] == 2) Virus.push_back(make_pair(i, j));
        }
    }
    Space = Empty.size(); // nCr 에서 n의 개수
}
 
void Copy_MAP()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            C_MAP[i][j] = MAP[i][j];
        }
    }
}
 
void BFS(int a, int b)
{
    queue<pair<int, int>> Q;
    Q.push(make_pair(a, b));
    Visit[a][b] = true;
    
    while (Q.empty() == 0)
    {
        int x = Q.front().first;
        int y = Q.front().second;
        Q.pop();
 
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
 
            if (nx >= 0 && ny >= 0 && nx < N && ny < M)
            {
                if (Visit[nx][ny] == false && C_MAP[nx][ny] == 0)
                {
                    C_MAP[nx][ny] = 2;
                    Visit[nx][ny] = true;
                    Q.push(make_pair(nx, ny));
                }
            }
        }
    }
}
 
int Count_Safe_Area()
{
    int Cnt = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (C_MAP[i][j] == 0) Cnt++;
        }
    }
    return Cnt;
}
 
void Spread_Virus()
{
    int Cnt = 0;
    Copy_MAP();
    
    // memset(void *ptr, int value, size_t num);
    // ptr은 시작메모리 주소, value는 채우고자하는 값, num 채우고자하는 메모리 크기
    memset(Visit, false, sizeof(Visit));
 
    for (int i = 0; i < Space; i++) // 빈공간 전체까지
    {
        if (Cnt == 3) break;
        if (Check[i] == true)
        {
            int x = Empty[i].first;
            int y = Empty[i].second;
            C_MAP[x][y] = 1;
            Cnt++;
        }
    }
 
    for (int i = 0; i < Virus.size(); i++)
    {
        int x = Virus[i].first;
        int y = Virus[i].second;
        BFS(x, y);
    }
 
    int Temp_Answer = Count_Safe_Area();
    Answer = Bigger(Answer, Temp_Answer);
}
 
void Make_Wall(int Idx, int Cnt)  // nCr에서 r을 선택하는 방법
{
    if (Cnt == 3) // 재귀호출이 종료되도록 함
    {
        Spread_Virus();
        return;
    }
 
    // Space는 빈공간의 개수
    for (int i = Idx; i < Space; i++) // 재귀호출과 반복문이 관련됨
    {
        if (Check[i] == true) continue; //
        Check[i] = true;
        Make_Wall(i, Cnt + 1);
        Check[i] = false;
    }
}
 
void Solution()
{
    Make_Wall(0, 0);
}
 
void Solve()
{
    Input();
    Solution();
    cout << Answer << endl;
}

int main(int argc, const char * argv[])
{
    // C와 C++ 또 flush에 대한 Buffer를 설정을 static으로 바꾸어 속도빨라지게 변형하는 방법이다.
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    Solve();
    
    return 0;
}
