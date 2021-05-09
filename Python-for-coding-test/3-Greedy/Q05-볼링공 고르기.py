### =======================================
# 이거 문제 이해가 안감 combinations로 왜 안풀림?
### =============+=========================

# A, B 두사람은 서로 무게가 다른 볼링공
# 볼링공의 총 개수 N
from itertools import combinations

n = 5
m = 3

data = [1, 3, 2, 3, 2]

resComb = list(combinations(data, 2))
result = []
for x in resComb:
    if(x[0] + x[1] <= m):
        result.append(x)

print(result)
