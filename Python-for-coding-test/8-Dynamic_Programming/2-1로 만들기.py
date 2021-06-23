x = int(input())
cnt = 0

# 크게 잘라내야 금방 줄어드니 이 순서가 맞다

while x == 1:

    # 5로 나누기
    if x % 5 == 0:
        x = x // 5
        cnt = cnt + 1
    elif (x - 1) % 5 == 0:
        x = (x-1) // 5
        cnt = cnt + 2

    # 3으로 나누기
    elif x % 3 == 0:
        x = x // 3
        cnt = cnt + 1
    elif (x-1) % 3 == 0:
        x = (x-1) // 3
        cnt = cnt + 2

    # 2로 나누기
    elif x % 2 == 0:
        x = x // 2
        cnt = cnt + 1
    elif (x-1) % 2 == 0:
        x = (x-1) // 2
        cnt = cnt + 2

    # 1 빼기
    else:
        x = x - 1
        cnt = cnt + 1

# 연산을 사용하는 최소 횟수
print(cnt)