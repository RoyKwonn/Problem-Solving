import heapq

n = int(input())
data = []

for _ in range(n):
    heapq.heappush(data, int(input()))

ans = 0

if n == 1:
    print(0)
else:
    while True:
        if len(data) == 2:
            ans += sum(data)
            break
        tmp = heapq.heappop(data) + heapq.heappop(data)
        ans += tmp
        heapq.heappush(data, tmp)
    print(ans)