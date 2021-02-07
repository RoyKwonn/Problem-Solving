T = int(input())

for i in range(T):
    R, S = input().split()
    R = int(R)  # 반복할 횟수
    S = str(S)  # 현재 문자
    for i in range(len(S)):
        print(R * S[i], end='')
