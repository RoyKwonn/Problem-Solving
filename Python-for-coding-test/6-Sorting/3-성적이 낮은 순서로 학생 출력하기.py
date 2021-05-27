n = int(input())

data = []
for _ in range(n):
    temp = input().split()
    data.append([temp[0], int(temp[1])])

## 방법 1
def setting(array):
    return array[1]

data.sort(key=setting)

## 방법 2
# data = sorted(data, key=lambda student: student[1])

for i in data:
    print(i[0], end=' ')