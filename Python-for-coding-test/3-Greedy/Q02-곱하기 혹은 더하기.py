# 각 자리가 숫자(0부터 9)로만 이루어진 문자열 S가 주어졌을 때,
# 왼쪽부터 오른쪽으로 하나씩

def answer(data):
    result = int(data[0])
    for i in range(1, len(data)):
        result1 = result + int(data[i])
        result2 = result * int(data[i])

        if (result1 < result2):
            result = result2
        else:
            result = result1

    return result

data = "02984"
print(data)
result = answer(data)
print(result)


data = "567"
print(data)
result = answer(data)
print(result)
