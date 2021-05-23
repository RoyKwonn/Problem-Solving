# 로봇의 크기는 2x2
# 0은 빈칸, 1은 벽
# 시작위치는 1,1 종료위치는 N,N
# 회전시 4칸이 비어있어야함

from collections import deque

def get_next_pos(pos, board): # 이동가능한 모든 가능성 일아보기
    next_pos = [] # 반환 결과 (이동 가능한 위치들)

    pos = list(pos) # 현재 위치 정보를 리스트로 변환 (집합 → 리스트)
    # 초기 위치
    pos1_x, pos1_y, pos2_x, pos2_y = pos[0][0], pos[0][1], pos[1][0], pos[1][1]

    # (상, 하, 좌, 우)로 이동하는 경우에 대해서 처리
    move = [[-1,0],[1,0],[0,-1],[0,1]]
    for dx, dy in move: # 두개의 점에 대해서 이동한다.
        pos1_next_x, pos1_next_y, pos2_next_x, pos2_next_y = pos1_x + dx, pos1_y + dy, pos2_x + dx, pos2_y + dy
        # 이동하고자 하는 두 칸이 모두 비어 있다면
        if board[pos1_next_x][pos1_next_y] == 0 and board[pos2_next_x][pos2_next_y] == 0:
            next_pos.append({(pos1_next_x, pos1_next_y), (pos2_next_x, pos2_next_y)})

    # 현재 로봇이 가로로 놓여 있는 경우
    if pos1_x == pos2_x:
        for i in [-1, 1]: # 위쪽으로 회전하거나, 아래쪽으로 회전
            if board[pos1_x + i][pos1_y] == 0 and board[pos2_x + i][pos2_y] == 0: # 위쪽 혹은 아래쪽 두 칸이 모두 비어 있다면
                next_pos.append({(pos1_x, pos1_y), (pos1_x + i, pos1_y)})
                next_pos.append({(pos2_x, pos2_y), (pos2_x + i, pos2_y)})

    # 현재 로봇이 세로로 놓여 있는 경우
    elif pos1_y == pos2_y:
        for i in [-1, 1]: # 왼쪽으로 회전하거나, 오른쪽으로 회전
            if board[pos1_x][pos1_y + i] == 0 and board[pos2_x][pos2_y + i] == 0: # 왼쪽 혹은 오른쪽 두 칸이 모두 비어 있다면
                next_pos.append({(pos1_x, pos1_y), (pos1_x, pos1_y + i)})
                next_pos.append({(pos2_x, pos2_y), (pos2_x, pos2_y + i)})

    # 현재 위치에서 이동할 수 있는 위치를 반환
    return next_pos

def solution(board):
    # 1. 맵의 외곽에 벽을 두는 형태로 맵 변형

    # 맵의 크기를 잡는다.
    n = len(board)

    # (n+2) X (n+2) 크기의 맵을 만든 다음 전체 값을 1로 만들어준다.
    new_board = [[1] * (n + 2) for _ in range(n + 2)]

    # 기존 맵을 옮겨준다.
    for i in range(n):
        for j in range(n):
            new_board[i + 1][j + 1] = board[i][j]


    # 너비 우선 탐색(BFS) 수행
    q = deque()
    visited = []

    pos = {(1, 1), (1, 2)} # 시작 위치 설정
    q.append((pos, 0)) # (위치, 비용)

    visited.append(pos) # 방문 처리

    # 큐가 빌 때까지 반복
    while q:
        pos, cost = q.popleft()
        # (n, n) 위치에 로봇이 도달했다면, 최단 거리이므로 반환
        if (n, n) in pos: # 종료조건
            return cost

        # 현재 위치에서 이동할 수 있는 위치 확인
        for next_pos in get_next_pos(pos, new_board): # 이동가능한 위치로 차례대로 이동한다.
            # 아직 방문하지 않은 위치라면 큐에 삽입하고 방문 처리
            if next_pos not in visited: # 방문하지 않은곳이라면 BFS에 맞추어 큐에 저장한다.
                q.append((next_pos, cost + 1)) # 코스트 증가된 상태로 저장하는것이 뽀인트
                visited.append(next_pos) # 방문처리한다.
