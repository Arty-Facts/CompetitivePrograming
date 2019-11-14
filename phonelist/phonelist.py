# python3 
# Arturas Aleksandrauskas artal938 - TDDD95
import sys, re
from collections import defaultdict
def solve(freq):
    for s in list(freq):
            for i, c in enumerate(s):
                #print(s[:i])
                if s[:i] in freq:
                    return True
    return False

def main():
    read = True
    t = int(sys.stdin.readline())
    for _ in range(t):
        freq = set()
        n = int(sys.stdin.readline())
        for _ in range(n):
            s = sys.stdin.readline()
            s = s.strip()
            yes = False
            #print(s)
            freq.add(s)
        yes = solve(freq)
                    
        if yes:
            print("NO")
        else:
            print("YES")
        
            
				
if __name__ == "__main__":
    main()
