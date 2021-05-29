from sys import stdin

n = int(input())
house = list(map(int, stdin.readline().split()))
house.sort()

print(house[(n - 1) // 2])
