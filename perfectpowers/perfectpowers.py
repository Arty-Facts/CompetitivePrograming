#!/usr/bin/python3
import sys

def calc_p(b, x):
    p = 1
    prod = b
    while(x > prod):
        prod *= b
        p += 1
    if prod == x:
        return p
    return 0

def main():
    for x in sys.stdin:
        x = int(x)
        neg = False
        if(x < 0):
            neg = True
            x = abs(x)

        if not x:
            break
        p = 0
        for b in range(2, x+1):
            if (x%b == 0):
                p = calc_p(b, x)
                if(p == 0):
                    continue

                if not neg: 
                    print(p)
                    break
                else:
                    if(p%2 != 0):
                        print(p)
                        break
                    p = 0
            if(b*b > x):
                break

        if(p == 0):
            print(1)
                
main()  