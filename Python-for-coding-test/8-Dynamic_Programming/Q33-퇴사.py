n = int(input())
t = []
p = []
dp = []
for i in range(n):
    x, y = map(int, input().split())
    t.append(x)
    p.append(y)
    dp.append(y)
dp.append(0) # 맨끝에 추가해주는게 포인트
for i in range(n - 1, -1, -1):
    if t[i] + i > n: # 기한에서 오버되는 부분
        dp[i] = dp[i + 1]
    else:  #기한 안에 가능하다면
        dp[i] = max(dp[i + 1], p[i] + dp[i + t[i]])
print(dp[0])