# python3 
# Arturas Aleksandrauskas artal938 - TDDD95
import sys
from itertools import permutations 

def manhatan(f, t):
    return abs(f[0] - t[0]) + abs(f[1] - t[1])

def calc_dist(start, pappers, min_d):
    tmp = start
    dist = 0
    for p in pappers:
        dist += manhatan(tmp, p)
        tmp = p
        if dist > min_d:
            return dist
    dist += manhatan(tmp, start)   
    return dist

def main():
    tests = int(sys.stdin.readline().strip())
    for _ in range(tests):
        maxX, maxY = map(int, sys.stdin.readline().split())
        startX, startY = map(int,sys.stdin.readline().split())
        pappers = []
        p = int(sys.stdin.readline().strip())
        for _ in range(p):
            x, y = map(int, sys.stdin.readline().split())
            pappers.append((x,y))
        dist = 400
        for perm in permutations(pappers):
            dist = min(dist, calc_dist((startX, startY), perm, dist))
        print(dist)
				
if __name__ == "__main__":
    main()
