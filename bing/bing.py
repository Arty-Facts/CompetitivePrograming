# python3 
# Arturas Aleksandrauskas artal938 - TDDD95
import sys, re
from collections import defaultdict

def main():
    freq = defaultdict(int)
    read = True
    sys.stdin.readline()
    for s in sys.stdin.readlines():
        for i, c in enumerate(s):
            latest = freq[s[:i]]
            freq[s[:i]] += 1
        print( latest)
        
            
				
if __name__ == "__main__":
    main()
