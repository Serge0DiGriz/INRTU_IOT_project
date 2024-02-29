nom = (1, 2, 5, 10)
money = [int(i) for i in input("Кол-во монет (1р. 2р. 5р. 10р.): ").strip().split()]
n = sum([a*money[i] for i, a in enumerate(nom)])
print(f"{n}р.")
F = [money[:] for i in range(n+1)]
F[0] = [0, 0, 0, 0]

for k in range(1, n+1):
    x, minF = -1, sum(F[k])
    for i, a in enumerate(nom):
        if (k-a >= 0)and(money[i]-F[k-a][i] > 0)and\
           (k-a == sum([b*F[k-a][j] for j,b in enumerate(nom)])):
            newF = sum(F[k-a])+1
            if (newF < minF):
                minF = newF
                x = (i, a)
    if (x == -1):
        for i, a in enumerate(nom[1:]):
            for j in range(1, a):
                if (k-a+j >= 0)and(money[i+1]-F[k-a+j][i+1] > 0):
                    newF = sum(F[k-a+j])+1
                    if (newF < minF):
                        minF = newF
                        x = (i+1, a-j)

    if (x != -1):
        i, a = x
        F[k] = F[k-a][:]
        F[k][i] += 1
                        

for k in range(n+1):
    print(f"{k}р.", F[k])

input()
