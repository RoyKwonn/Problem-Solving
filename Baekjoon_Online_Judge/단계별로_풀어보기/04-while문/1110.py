origin = int(input())
n = origin
count = 0

while count == 0 or n != origin:
    s = sum([int(i) for i in str(n)])
    n = int((n%10)*10 + s%10)
    count += 1

print(count)