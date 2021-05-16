# 현재 점수 N의 자릿수를 반으로 나누어서 왼쪽 부분의 각 자릿수의 합과 오른쪽 부분의 각 자릿수의 합을 더한 값이 동일한 상황을 의미합니다.

data = input()
left = 0
right = 0

# 짝수 길이인 경우
if len(data) % 2 == 0:
    for i in range(0, len(data)//2):
        left += int(data[i])
    for i in range(len(data)//2, len(data)):
        right += int(data[i])

    if left == right:
        print('LUCKY')
    else:
        print('READY')
else:
    print('ERROR')