T = int(input())
for _ in range(T):
    N = int(input())
    NN = str(N ** 2)
    N = str(N)
    if N == NN[-(len(N)):]:
        print("YES")
    else:
        print("NO")
