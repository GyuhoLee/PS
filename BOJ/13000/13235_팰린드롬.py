a=input()
if a[:len(a)//2]==a[-1:(len(a)-1)//2:-1]:
    print('true')
else:
    print('false')