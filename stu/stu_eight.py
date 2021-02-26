import time, random
start = time.clock()


def conf(state, nextX):
    nexty=len(state)
    for i in range(nexty):
        if abs(state[i]-nextX) in (0, nexty-i):
            return True
    return False


def queens(num=8,state=()):
    for pos in range(num):
        if not conf(state, pos):
            if len(state) == num-1:
                yield (pos,)
            else:
                for res in queens(num, state+(pos,)):
                    yield (pos,)+res


def pretty(sol):
    def line(pos, length=len(sol)):
        return "-"*pos+"X"+"-"*(length-pos-1)
    for pos in sol:
        print(line(pos))

#print(list(queens(8)))


pretty(random.choice(list(queens(8))))
end = time.clock()
print ("\n"+str(end-start))


#while True:
#    com=input('please input com:\n')
#    if not com:
#       break
#    exec(com)
