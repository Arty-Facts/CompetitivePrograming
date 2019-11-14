# python3
# Arturas Aleksandrauskas artal938 - TDDD95
import sys
from functools import cmp_to_key
import math

def calc(tower):
    res = tower[0]
    for i in range(2, min(5, len(tower)+1)):
        c = tower[-(i-1)]
        n = tower[-i]
        tower[-i] = res = n**c
    return res

def comp(lhs, rhs):
    lhs = calc(lhs[1]) 
    rhs = calc(rhs[1]) 
    if lhs < rhs:
        return -1
    elif lhs > rhs:
        return 1
    else:
        return 0

def mangel(tower):
    for i in range(2, len(tower)+1):
        c = tower[-(i-1)]
        n = tower[-i]
        if n**c > 100:
            return tower[:len(tower)-(i-2)]
        tower[-i] =  n**c
    return tower[:1]

def main():
    n = int(sys.stdin.readline().strip())
    towers = []
    for _ in range(n):
        text = sys.stdin.readline().strip()
        tower = list(map(int, text.split("^")))
        if 1 in tower:
            tower = tower[:tower.index(1)]
        tower = mangel(tower)
        towers.append((text, tower))

    towers = sorted(towers, key=cmp_to_key(comp))
    print("Case 1:")
    for text, value in towers:
        print(text, value)

def main2():
    n = int(sys.stdin.readline().strip())
    towers = []
    for _ in range(n):
        text = sys.stdin.readline().strip()
        tower = list(map(int, text.split("^")))
        for i in range(2, len(tower)+1):
            c = tower[-(i-1)]
            n = tower[-i]
            tower[-i] =  n**c
        towers.append((text, tower[0]))

    towers = sorted(towers, key=lambda x:x[1])
    print("Case 1:")
    for text, value in towers:
        print(text, value)

if __name__ == "__main__":
    main2()
