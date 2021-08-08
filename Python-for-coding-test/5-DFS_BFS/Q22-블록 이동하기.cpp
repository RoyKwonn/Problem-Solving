#include <bits/stdc++.h>
using namespace std;

const int dx[] = { -1, 0, 1, 0 };
const int dy[] = { 0, 1, 0, -1 };
const int ddx[] = { 0, 1 };
const int ddy[] = { 1, 0 };

int N;
int conv(int a, int b, int c) {
    return a * 200 + b * 2 + c;
}
bool check(int x, int y, vector<vector<int>>& board) {
    return x >= 0 && x < N && y >= 0 && y < N && board[x][y] == 0;
}
int solution(vector<vector<int>> board) {
    N = board.size();
    bool visit[100][100][2]{}; // 0-가로, 1-세로
    visit[0][0][0] = 1;

    queue<int> Q;
    Q.push(conv(0, 0, 0));

    int ans = 0;
    while (!Q.empty()) {
        int szQ = Q.size();
        while (szQ--) {
            int x, y, d, K = Q.front(); Q.pop();
            x = K / 200;
            y = K % 200 / 2;
            d = K % 2;

            int x2 = x + ddx[d];
            int y2 = y + ddy[d];

            if (x == N - 1 && y == N - 1 ||
                x2 == N - 1 && y2 == N - 1) return ans;

            for (int i = 0; i < 4; ++i) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                int nx2 = x2 + dx[i];
                int ny2 = y2 + dy[i];
                if (!check(nx, ny, board) || !check(nx2, ny2, board)) continue;

                // 단순 이동
                if (!visit[nx][ny][d]) {
                    visit[nx][ny][d] = 1;
                    Q.push(conv(nx, ny, d));
                }
            }

            // 회전 이동
            if (d == 0) {
                if (check(x - 1, y, board) && check(x2 - 1, y2, board)) {
                    if (!visit[x - 1][y][1]) {
                        Q.push(conv(x - 1, y, 1));
                        visit[x - 1][y][1] = 1;
                    }
                    if (!visit[x - 1][y + 1][1]) {
                        Q.push(conv(x - 1, y + 1, 1));
                        visit[x - 1][y + 1][1] = 1;
                    }
                }
                if (check(x + 1, y, board) && check(x2 + 1, y2, board)) {
                    if (!visit[x][y][1]) {
                        Q.push(conv(x, y, 1));
                        visit[x][y][1] = 1;
                    }
                    if (!visit[x][y + 1][1]) {
                        Q.push(conv(x, y + 1, 1));
                        visit[x][y + 1][1] = 1;
                    }
                }
            }
            else {
                if (check(x, y + 1, board) && check(x2, y2 + 1, board)) {
                    if (!visit[x][y][0]) {
                        Q.push(conv(x, y, 0));
                        visit[x][y][0] = 1;
                    }
                    if (!visit[x + 1][y][0]) {
                        Q.push(conv(x + 1, y, 0));
                        visit[x + 1][y][0] = 1;
                    }
                }
                if (check(x, y - 1, board) && check(x2, y2 - 1, board)) {
                    if (!visit[x][y - 1][0]) {
                        Q.push(conv(x, y - 1, 0));
                        visit[x][y - 1][0] = 1;
                    }
                    if (!visit[x + 1][y - 1][0]) {
                        Q.push(conv(x + 1, y - 1, 0));
                        visit[x + 1][y - 1][0] = 1;
                    }
                }
            }
        }

        ++ans;
    }

    return -1;
}
