# python3 
# Arturas Aleksandrauskas artal938 - TDDD95
import sys
# http://mathworld.wolfram.com/PolygonArea.html
def main():
    while True:
        t = int(sys.stdin.readline().strip())
        if t == 0:
            break
        first_x, first_y = map(int,sys.stdin.readline().split())
        privios_x, privios_y = first_x, first_y 
        ans = 0
        for _ in range(t-1):
            x, y = map(int,sys.stdin.readline().split())
            ans += privios_x*y - privios_y*x
            privios_x, privios_y = x, y 
        ans += privios_x*first_y - privios_y*first_x
        if ans < 0:
            print("CW",-ans/2)
        else:
            print("CCW",ans/2)
            

if __name__ == "__main__":
    main()