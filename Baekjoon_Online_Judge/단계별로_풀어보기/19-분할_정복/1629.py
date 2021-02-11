A, B, C = [int(x) for x in input().split()]

def solve(A, B):
    if B%2 != 0:
        return solve(A, B-1) * A
    elif B == 0:
        return 1
    elif B == 1:
        return A
    else:
        result = solve(A, B//2)
        return result ** 2 % C

print(solve(A, B) % C)