# python3 
# Arturas Aleksandrauskas artal938 - TDDD95
import sys, re

def main():
    p = int(sys.stdin.readline())
    x = list(map(int, sys.stdin.readline().split()))
    it = 3
    #print(x)
    while it > -1:
        #print(x)
        if x[0] + 5*x[1] + 10*x[2] +25*x[3] == p:
            print(sum(x))
            return
        elif x[0] + 5*x[1] + 10*x[2] +25*x[3] > p:
            x[it] -= 1
            if x[it] == 0:
                it -= 1
        elif x[0] + 5*x[1] + 10*x[2] +25*x[3] < p:
            x[it+1] += 1
            if x[it] == 0:
                x[it] += 1
                it -= 1
    print("Impossible")
            
				
if __name__ == "__main__":
    main()
