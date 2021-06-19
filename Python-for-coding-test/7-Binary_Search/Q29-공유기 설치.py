import sys

# 입력
N, C = map(int, sys.stdin.readline().rstrip().split())
house = []
for _ in range(N):
    house.append(int(input()))

house.sort()

start = 1       # 좌표값의 최소값
end = house[-1] - house[0]  # 가장 높은 좌표와 가장 낮은 좌표의 차이

result = 0

while(start <= end):
    mid = (start + end) // 2
    old = house[0]
    count = 1

    for i in range(1, len(house)):
        if house[i] >= old+mid: # gap 이상
            count += 1
            old = house[i]

    if count >= C:
        start = mid + 1
        result = mid
    else:
        end = mid - 1

print(result)
