# 맨 처음에는 첫번째 열의 어느 행에서든 출발할 수 있습니다.
# 이후 m번에 걸쳐서 매번 오른쪽 위, 오른쪽, 오른쪽 아래 3가지 중 하나의 위치로 이동해야 합니다.
# 채굴자가 얻을 수 있는 금의 최대 크기를 출력하는 프로그램


import sys

# 테스트 케이스
T = int(input())

for _ in range(T):

    # 입력
    n, m = map(int, sys.stdin.readline().rstrip().split())
    array = list(map(int, sys.stdin.readline().rstrip().split()))

    # DP 설정
    dp = []
    idx = 0
    for i in range(n):
        dp.append(array[idx:idx + m])
        idx += m


    # 다이나믹 프로그래밍 진행
    for j in range(1, m):
        for i in range(n):
            # 왼쪽 위에서 오는 경우
            if i == 0:
                left_up = 0
            else:
                left_up = dp[i - 1][j - 1]

            # 왼쪽 아래에서 오는 경우
            if i == n - 1:
                left_down = 0
            else:
                left_down = dp[i + 1][j - 1]

            # 왼쪽에서 오는 경우
            left = dp[i][j - 1]
            dp[i][j] = dp[i][j] + max(left_up, left_down, left)

    result = 0
    for i in range(n):
        result = max(result, dp[i][m - 1])
    print(result)