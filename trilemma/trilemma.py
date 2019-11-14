# python3 
# Arturas Aleksandrauskas artal938 - TDDD95
import sys


def main():
    t = int(sys.stdin.readline().strip())
    dist = lambda f,s: ((f[0]-s[0])**2 + (f[1]-s[1])**2 )#**(1/2) #rowding error
    for i in range(t):
        print("Case #{}:".format(i+1), end=" ")
        x1, y1, x2, y2, x3, y3 = map(int,sys.stdin.readline().split())
        v = (x1-x2, y1-y2)
        u = (x1-x3, y1-y3)
        area_ish =  (v[0]*u[1]) - (v[1]*u[0])

        if area_ish == 0 :
            print("not a triangle")
            continue
        a, b, c = sorted([dist((x1,y1),(x2,y2)), dist((x1,y1),(x3,y3)),dist((x2,y2),(x3,y3))])

        if a == b or b == c:
            print("isosceles", end=" ")
        else:
            print("scalene", end=" ")
        # a^2 + b^2 = c^2
        if a + b == c:
            print("right triangle")
        elif a + b < c:
            print("obtuse triangle")
        elif a + b > c:
            print("acute triangle")
        else:
            raise "nooooo!!!"

if __name__ == "__main__":
    main()