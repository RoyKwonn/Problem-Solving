
import sys

n = int(input())
array = list(map(int, sys.stdin.readline().rstrip().split()))

# N명의 병사가 무작위로 나열
# 각 병사는 전투력 보유
# 오름차순
# 뒤쪽에 있는 병사보다 높아야 한다
# 남아있는 병사의 수가 최대가 되도록 하기 위한 열외해야하는 병사의 수

dp = [1] * (n)

for i in range(1, n):
    for j in range(0, i):
        if array[j] > array[i]:
            dp[i] = max(dp[i], dp[j] + 1)

print(n - max(dp))


