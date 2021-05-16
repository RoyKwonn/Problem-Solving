n = int(input()) # 맵크기
k = int(input()) # 사과

# 맵
board=[[0]*(n+1) for i in range(n+1)]

# 사과 정보
for _ in range(k):
    x, y = map(int, input().split())
    board[x][y] = 1

oper = [input().split() for _ in range(int(input()))]

snake = [(1,1)]    # snake 몸

# 끝나는 경우 -> 맵 밖에 나감 or 자신의 몸에 닿음
# 뱀은 처음에 오른쪽을 향한다.

direction = [(0,1), (1,0), (0,-1), (-1,0)] # 동남서북
direction_f = 0
score = 0	# 시간
x, y = 1, 1

while True:
    score+=1
    # 다음 x,y
    x += direction[direction_f][0]
    y += direction[direction_f][1]
    if 1 <= x <= n and 1 <= y <= n:
        snake.append((x, y)) # 몸길이 늘림
        for i in snake[:-1]: # 자기 몸과 부딪힌경우
            if (x, y) == i:
                print(score)
                exit(0)
        if board[x][y] == 0: # 그냥 통로임-> 꼬리 삭제
            snake.pop(0)
        if board[x][y] == 1:
            board[x][y] = 0
    else:   # 맵을 나간 경우
        print(score)
        break

    if oper and score == int(oper[0][0]):
        if oper[0][1] == 'D': # 오른쪽 90
            direction_f = direction_f+1 if direction_f < 3 else 0
            oper.pop(0)
        elif oper[0][1] == 'L': # 왼쪽 90
            direction_f = direction_f - 1 if direction_f > 0 else 3
            oper.pop(0)