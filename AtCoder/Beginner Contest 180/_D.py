X, Y, A, B = map(int, input().split())
ans = 0
while X * A < X + B and X < Y:
    ans = ans + 1
    X = X * A
if X >= Y:
    print(ans - 1)
else:
    tmp = Y - X
    ans = ans + (tmp // B)
    if tmp % B == 0:
        ans = ans - 1
    print(ans)
