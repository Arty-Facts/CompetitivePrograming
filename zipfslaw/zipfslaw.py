# python3 
# Arturas Aleksandrauskas artal938 - TDDD95
import sys, re
from collections import defaultdict

def main():
    freq = defaultdict(int)
    read = True
    for s in sys.stdin.readlines():
        s = s.strip()
        if read:
            if len(s) > 0:
                read = False
                n = int(s)
        else:
            if (s == ''):
                continue
            elif(s == 'EndOfText'):
                f = False
                for k, v in sorted(freq.items()):
                    if v == n:
                        f = True
                        print(k)
                if not f:
                    print("There is no such word.")
                freq = defaultdict(int)
                read = True
                print()
            else:
                for word in re.compile('[^a-zA-Z]').split(s):
                    freq[str.lower(word)] += 1
            
				
if __name__ == "__main__":
    main()
