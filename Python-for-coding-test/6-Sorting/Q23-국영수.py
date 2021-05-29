from sys import stdin

n = int(input())

data = []

for _ in range(n):
    temp = list(stdin.readline().split())
    data.append([temp[0], int(temp[1]), int(temp[2]), int(temp[3])]) # 이름, 국, 영, 수


data.sort(key=lambda student: (-student[1], student[2], -student[3], student[0]))

for x in data:
    print(x[0])