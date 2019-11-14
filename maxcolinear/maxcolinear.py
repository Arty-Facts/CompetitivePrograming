# python3 
# Arturas Aleksandrauskas artal938 - TDDD95
import sys
from collections import defaultdict
def main():
    MAX = 2**32
    scope = 0
    while True:
        n = int(sys.stdin.readline().strip())
        if n == 0:
            break
        points = []
        for _ in range(n):
            x, y = map(int,sys.stdin.readline().split())
            points.append((x,y))
        ans = 0
        c = 0
        for i in range(0,min(n, 65)):
            ox, oy =  points[i]
            count = defaultdict(int)
            c += 1
            for x, y in points[c:]:
                dx = x - ox
                dy = y - oy
                slope = 0
                
                if dx == 0:
                    if dy < 0:
                        slope = -MAX
                    else:
                        slope = MAX
                else:
                    slope = dy/dx

                count[slope] += 1

            if len(count) > 0:
                k = max(count, key=lambda x: count[x])
                ans = max(ans, count[k])
        print(ans+1)

if __name__ == "__main__":
    main()