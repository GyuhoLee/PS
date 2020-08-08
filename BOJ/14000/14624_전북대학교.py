N = int(input())
if N % 2 == 0 :
    print("I LOVE CBNU")
else:
    print("*" * N)
    j = 1
    print(" " * int((N - 1) / 2) + "*")
    for i in range(int((N - 1) / 2 - 1), -1, -1):
        print(" " * i + "*" + " " * j + "*")
        j = j + 2
        
