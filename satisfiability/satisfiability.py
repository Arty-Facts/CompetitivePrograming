#python3
#Arturas Aleksandrauskas - artal938 TDDD95
import sys
from random import randint
from collections import defaultdict
import operator
def solve2(expresions, comb):
    t = []
    for e in expresions:
        satisfide = False
        for i, b in e:
            if b == "~":
                satisfide = satisfide or (comb ^ -1) & (1<<i)
            else:
                satisfide = satisfide or comb & (1<<i)

        if not satisfide:
            for i, b in e:
                t.append(i)
            break

    if len(t) > 0:
        #print(t)
        #e = t[randint(0,len(t)-1)]
        #return comb ^ 1 << e[randint(0,len(e)-1)][0]
        return comb ^ 1 << t[randint(0,len(t)-1)]
    return -1

def solve(expresions, comb, n):
    for i in range(2000):
        comb = solve2(expresions, comb)
        #print(comb)
        if comb == -1:
            return True
        if i%150 == 0:
            comb = randint(0,2**n)
    return False


def main():
    tests = sys.stdin.readline()
    for _ in range(int(tests)):
        n, m = map(int, sys.stdin.readline().split())
        expresions = [[]]*m
        for i in range(m):
            expresion = sys.stdin.readline().strip().split(' v ')
            expresion = [(int( i[2:]if i[0] == "~"else i[1:] )-1, i[0]) for i in expresion]
            expresions[i]= expresion
        expresions.sort(key=len)
        if solve(expresions, randint(0,2**n), n):
            print("satisfiable")
        else:
            print("unsatisfiable")
            
if __name__ == "__main__":
    main()
