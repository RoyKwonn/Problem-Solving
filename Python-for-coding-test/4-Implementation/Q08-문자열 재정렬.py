data = input()
result = []
num = 0

for i in data:
    if i.isalpha():
        result.append(i)
        # print(result)
    else:
        num += int(i)

tmp = ""
result.sort()
for i in result:
    tmp += i

print(tmp + str(num))