A = int(input())
B = int(input())

result = int(A * (B % 10))
print(result)

result = int(A * ((B % 100) - (B % 10)) / 10)
print(result)

result = int(A * ((B % 1000) - (B % 100)) / 100)
print(result)

print(int(A * B))
