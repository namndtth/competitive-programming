t = int(input())
while (t):
    n = int(input())
    half = n // 2
    
    total1 = 0
    total2 = 0

    for i in range(1, n + 1):
        total1 += pow(2, i)

    for i in range(half, n):
        total2 += pow(2, i)

    t = t - 1
    print(total1 - 2 * total2)