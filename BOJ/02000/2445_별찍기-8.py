N = int(input())


for i in range (N - 2, -1, -1):
    print("*" * (N - 1 - i) + " " * (i * 2 + 2) + "*" * (N - 1 - i))

print("*" * (N * 2))

for i in range (0, N - 1):
    print("*" * (N - 1 - i) + " " * (i * 2 + 2) + "*" * (N - 1 - i))
