N = int(input())
ans = 0
for _ in range(N):
    P = int(input())
    ans += int(str(P)[:-1]) ** (P % 10)
print(ans)