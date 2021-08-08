#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

int n;
char board[6][6];
vector<pii> spaces;
int spaces_size;
vector<pii> teachers;
bool answer = false;

bool is_safe(pii teacher) {
    for (int i = 0; i < 4; i++) {
        int x = teacher.first;
        int y = teacher.second;
        while (true) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= n) break;
            if (board[nx][ny] == 'O') break;
            if (board[nx][ny] == 'S') return false;
            x = nx;
            y = ny;
        }
    }
    return true;
}

void combination(vector<pii> space, int pos, int remain) {
    space.push_back(spaces[pos]);

    if (remain <= 0) {
        for (auto& p : space) {
            board[p.first][p.second] = 'O';
        }
        answer = true;
        for (auto& teacher : teachers) {
            if (!is_safe(teacher)) {
                answer = false;
                break;
            }
        }
        for (auto& p : space) {
            board[p.first][p.second] = 'X';
        }
    }
    else {
        for (int i = pos + 1; i <= spaces_size - remain; i++) {
            combination(space, i, remain - 1);
            if (answer == true) break;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
            if (board[i][j] == 'X') {
                spaces.push_back({i, j});
            }
            if (board[i][j] == 'T') {
                teachers.push_back({i, j});
            }
        }
    }

    spaces_size = spaces.size();

    for (int i = 0; i <= spaces_size - 3; i++) {
        combination(vector<pii>(), i, 2);
        if (answer == true) break;
    }

    if (answer == true) {
        cout << "YES\n";
    }
    else {
        cout << "NO\n";
    }

    return 0;
}