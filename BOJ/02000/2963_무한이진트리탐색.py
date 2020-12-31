import math

s = input()
X = 1
cnt = 1
for ch in s:
    if ch == 'L':
        X *= 2
    if ch == 'R':
        X = X * 2 + cnt
    elif ch == '*':
        X = X * 5 + cnt
        cnt *= 3
print(X)
