# 벽 3개 세우는 경우의 수
# 0은 빈칸, 1은 벽, 2는 바이러스가 있는 곳

from sys import stdin

n, m = map(int, stdin.readline().split())
data = [list(map(int, stdin.readline().split())) for _ in range(n)]
temp = [[0]*m for _ in range(n)]

# 4 방향 (좌하우상)
dx, dy = [-1, 0, 1, 0], [0, 1, 0, -1]

result = 0

# dfs로 virus 확산
def virus(x, y):
    for i in range(4):
        nx = x + dx[i]
        ny = y + dy[i]
        if 0 <= nx < n and 0 <= ny < m:
            if not temp[nx][ny]: # 0 빈공간일 경우
                temp[nx][ny] = 2
                virus(nx,ny)

def getScore():
    score = 0
    for i in range(n):
        for j in range(m):
            if not temp[i][j]: # 빈공간의 갯수를 카운트 한다.
                score += 1
    return score

# dfs로 울타리 설치 + 안전영역 계산
def setWall(count):
    global result
    # 울타리가 3개 설치된 경우
    if count == 3:
        for i in range(n):
            for j in range(m):
                temp[i][j] = data[i][j]
        # spread
        for i in range(n):
            for j in range(m):
                if temp[i][j] == 2: # 맵에 만약 바이러스가 있다면
                    virus(i,j) # dfs로 최대한 퍼트린다.
        result = max(result, getScore()) # 가장 큰값을 result에 저장한다.
        return

    # 빈 공간에 울타리 설치
    for i in range(n):
        for j in range(m):
            if not data[i][j]:  # 0인경우 빈공간인경우
                data[i][j] = 1 # 벽 설치
                count += 1
                setWall(count)
                data[i][j] = 0 # 원상 복구
                count -= 1

setWall(0)
print(result)

