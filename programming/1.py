def f1():
    for i in range(2000, 3201):
        if i % 7 == 0 and i % 5 != 0:
            print(i, ",", end="")

    # Sol

    l = []
    for i in range(2000, 3201):
        if (i % 7 == 0) and (i % 5 != 0):
            l.append(str(i))

    print(','.join(l))


def f2():
    def fact(x):
        if x == 0:
            return 1
        else:
            return x * fact(x - 1)
    data = int(input())
    print(fact(data))


import math
value = math.factorial(995)
print(value)
