T = int(input())
for t in range(T):
    words = list(map(str, input().split()))
    sounds = set()
    while True:
        sound = list(map(str, input().split()))
        if sound[1] == 'does':
            break
        sounds.add(sound[2])
    for word in words:
        if word in sounds:
            continue
        print(word, end=' ')