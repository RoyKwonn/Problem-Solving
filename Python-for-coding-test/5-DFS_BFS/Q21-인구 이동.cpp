//백준_16234_인구이동
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

void borderCheck(int x, int y, int** board, int** visited, vector<int*> &unions, int N, int L, int R) {
    if (x > 0) {
        if (abs(board[y][x] - board[y][x - 1]) >= L && abs(board[y][x] - board[y][x - 1]) <= R && visited[y][x-1]==0) {
            int* tmp = new int[2];
            tmp[0] = x-1;
            tmp[1] = y;
            unions.push_back(tmp);
            visited[y][x-1] = 1;
            borderCheck(x - 1, y, board, visited, unions, N, L, R);
        }
    }
    if (y > 0) {
        if (abs(board[y][x] - board[y-1][x]) >= L && abs(board[y][x] - board[y-1][x]) <= R && visited[y-1][x] == 0) {
            int* tmp = new int[2];
            tmp[0] = x;
            tmp[1] = y-1;
            unions.push_back(tmp);
            visited[y-1][x] = 1;
            borderCheck(x, y-1, board, visited, unions, N, L, R);
        }
    }
    if (x < N - 1) {
        if (abs(board[y][x] - board[y][x + 1]) >= L && abs(board[y][x] - board[y][x + 1]) <= R && visited[y][x + 1] == 0) {
            int* tmp = new int[2];
            tmp[0] = x + 1;
            tmp[1] = y;
            unions.push_back(tmp);
            visited[y][x + 1] = 1;
            borderCheck(x + 1, y, board, visited, unions, N, L, R);
        }
    }
    if (y < N - 1) {
        if (abs(board[y][x] - board[y + 1][x]) >= L && abs(board[y][x] - board[y + 1][x]) <= R && visited[y + 1][x] == 0) {
            int* tmp = new int[2];
            tmp[0] = x;
            tmp[1] = y + 1;
            unions.push_back(tmp);
            visited[y + 1][x] = 1;
            borderCheck(x, y + 1, board, visited, unions, N, L, R);
        }
    }
}
int main(void) {
    //init
    int N, L, R;
    cin >> N >> L >> R;

    int** board = new int*[N];
    int** visited = new int*[N];
    for (int i = 0; i < N; i++) {
        board[i] = new int[N];
        visited[i] = new int[N];
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
            visited[i][j] = 0;
        }
    }

    int flag = 1;
    int day = 0;
    while (flag) {
        int mv_cnt = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (visited[i][j] != 0)
                    continue;
                vector<int*> unions;
                visited[i][j] = 1;
                int* tmp = new int[2];
                tmp[0] = j;
                tmp[1] = i;
                unions.push_back(tmp);
                borderCheck(j, i, board, visited, unions, N, L, R);
                int num_unions = unions.size();
                if (num_unions >= 2) {
                    mv_cnt++;
                    int pop = 0;
                    for (int a = 0; a < num_unions; a++) {
                        pop+=board[unions[a][1]][unions[a][0]];
                    }
                    pop /= num_unions;
                    for (int a = 0; a < num_unions; a++) {
                        board[unions[a][1]][unions[a][0]] = pop;
                        delete[] unions[a];
                    }
                }
            }//end for j
        }//end for i
        if (mv_cnt == 0) {
            flag = 0;
        }else {
            day++;
        }
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                visited[i][j] = 0;
            }
        }
    }//end while


    cout << day << endl;
    return 0;
}
