A, B, C = input().split()

A = int(A)
B = int(B)
C = int(C)

result = (A+B)%C
print(result)

result = ((A%C) + (B%C))%C
print(result)

result = (A*B)%C
print(result)

result = ((A%C)*(B%C))%C
print(result)
