import sys
input = sys.stdin.readline

## 집합 개념으로 이해하면 쉽다.

# 특정 원소가 속한 집합을 찾기
def find_parent(parent, x):
    # 루트 노드가 아니라면, 루트 노드를 찾을 때까지 재귀적으로 호출
    if parent[x] != x:
        parent[x] = find_parent(parent, parent[x])
    return parent[x]

# 두 원소가 속한 집합을 합치기
def union_parent(parent, a, b):
    a = find_parent(parent, a)
    b = find_parent(parent, b)
    if a < b:
        parent[b] = a
    else:
        parent[a] = b


n, m = map(int, input().split())
parent = [0] * (n + 1) # 부모 테이블

# 순환이 발생할 수도 있지만 일단 두개를 합친다.
for i in range(n):
    data = list(map(int, input().split()))
    for j in range(n):
        if data[j] == 1:
            union_parent(parent, i+1, j+1)

plan = list(map(int, input().split()))

result = True
for i in range(m-1):
    if find_parent(parent, plan[i] != find_parent(parent, plan[i+1])): # 부모 노드가 다르면 연결되지 않았다는 뜻이다.
        result = False

if result:
    print("YES")
else:
    print("NO")