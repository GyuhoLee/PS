N = int(input())

for i in range (0, N):
    print(" " * (N - 1 - i) + "*" * (i * 2 + 1))
