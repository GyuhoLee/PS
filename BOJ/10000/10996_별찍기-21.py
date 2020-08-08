N = int(input())

for i in range(N * 2):
    string = ''
    if i % 2 == 0:
        for j in range(N):
            if j % 2 == 0:
                string += '*'
            else:
                string += ' '
    else:
        for j in range(N):
            if j % 2 == 0:
                string += ' '
            else:
                string += '*'
    print(string)
