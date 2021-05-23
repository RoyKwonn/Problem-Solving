# BFS 사용
# 각 바이러스는 낮은 번호부터 증식한다.
# 번호가 낮은 것부터 Queue에 넣어야한다.

# 이미 어떠한 바이러스가 존재한다면
# 그곳에는 바이러스가 들어갈 수 없다

# ---------------------------------------------------------------------

from sys import stdin
from collections import deque

move = [[-1,0],[1,0],[0,-1],[0,1]] # 좌 하 우 상 (왜 풀이들은 이 순서들로 살펴보는 것인가?)
N, K = map(int, stdin.readline().split())
board = [list(map(int,stdin.readline().split())) for _ in range(N)] # 전체 보드 정보를 담는 리스트


# 바이러스 위치에 대한 내용 입력 후 s, x, y를 입력받는다.
# S초 뒤에 (x, y)에 존재하는 바이러스의 종류를 출력하는 것
# 만약 바이러스가 존재하지않는다면 0 출력
S, X, Y = map(int, stdin.readline().split())



q = []
for i in range(N):
    for j in range(N):
        if board[i][j] != 0:
            q.append([board[i][j], i, j, 0])

q.sort()
q = deque(q)
X -= 1
Y -= 1

while q:
    virus, x, y, time = q.popleft()
    if time == S:
        break
    else:
        for [dx, dy] in move:
            if 0 <= x + dx < N and 0 <= y + dy < N and board[x + dx][y + dy] == 0:
                board[x + dx][y + dy] = virus
                q.append([virus, x + dx, y + dy, time + 1])

print(board[X][Y])
