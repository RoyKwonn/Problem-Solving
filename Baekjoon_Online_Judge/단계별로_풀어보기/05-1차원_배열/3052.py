inp = [int(input()) for _ in range(10)]
rest = [i % 42 for i in inp]
print(len(set(rest)))