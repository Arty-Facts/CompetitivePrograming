# python3 
# Arturas Aleksandrauskas artal938 - TDDD95
import sys, re

def main():
    n = int(sys.stdin.readline())
    if(n==1):
        print(f"{1.0:0.6f}")
        return 
    opt = 0
    res = 0
    for j in range(n,2*n-3+n):
        #print("J", (2*n-j+1))
        tmp = 1
        for i in range(j,2*n-3+n):
            tmp *= i
        #print("temp", tmp)
        opt += tmp * (2*n-j+1)
        res += tmp

    #print("opt",opt)
    #print("res",res)
    print(f"{opt/res:0.6f}")
    

        
            
				
if __name__ == "__main__":
    main()
