
import sys

n = int(input())

dp = []
for i in range(n):
    dp.append(list(map(int, sys.stdin.readline().rstrip().split())))

for i in range(1, n):
    length = len(dp[i])
    for j in range(length):
        if j == 0:
            left = 0
        else:
            left = dp[i-1][j-1]

        if j == length - 1:
            right = 0
        else:
            right = dp[i-1][j]

        dp[i][j] = dp[i][j] + max(left, right)

result = 0
for i in range(len(dp[n-1])):
    result = max(result, dp[n-1][i])

print(result)