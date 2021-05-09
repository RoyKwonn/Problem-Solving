# n개의 동전을 가지고 있습니다.
# n개의 동전을 이용하여 만들 수 없는 양의 정수 최소값

from itertools import permutations

n = 5
data = [3, 2, 1, 1, 9]
data.sort()

target = 1
for i in data:
    # 만들 수 없는 금액
    if target < i:
        break
    target += i

print(target)