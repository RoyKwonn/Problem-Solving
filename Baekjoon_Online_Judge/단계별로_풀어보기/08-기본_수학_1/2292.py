n = int(input())
bee_house = 1
cnt = 1
while n > bee_house:
    bee_house += 6 * cnt
    cnt += 1
print(cnt)