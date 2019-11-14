# python3 
# Arturas Aleksandrauskas artal938 - TDDD95
import sys
import math


for i, line in enumerate(sys.stdin):
    n = (int(line.strip()))
    print("Case {}: {}".format(i+1, math.ceil(math.log(3, 10)+n*math.log(3/2, 10))))
