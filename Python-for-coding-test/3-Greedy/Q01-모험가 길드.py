# N명의 모험가를 대상으로 공포도가 X인 모험가는 반드시 X명 이상으로 구성한 모험가 그룹에 참여해야 여행을 떠날 수 있다.
# 최대 몇개의 그룹을 만들 수 있을까?

n = 5
data = [2, 3, 1, 2, 2]
result = 0

print(n)
data.sort(reverse=True)
print(data)

count = 0
n = 0

while(n < len(data)):
    n += data[n]
    count += 1

print(count)
