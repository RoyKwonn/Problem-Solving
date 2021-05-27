from sys import stdin

n, k = map(int, stdin.readline().split())

a = list(map(int, stdin.readline().split()))
b = list(map(int, stdin.readline().split()))

a.sort()
b.sort(reverse=True)

for i in range(n):
    if a[i] <= b[i] and k > 0:
        a[i], b[i] = b[i], a[i]
        k -= 1
    elif k == 0:
        break

result = 0
for x in a:
    result += x

print(result)