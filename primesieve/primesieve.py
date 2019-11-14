# python3 
# Arturas Aleksandrauskas artal938 - TDDD95
import sys
import math

factor = (sys.maxsize+1)*1-1

n, q = map(int,sys.stdin.readline().split())
max_bits = int(math.log(factor,2))
# print(sys.maxsize)
# print(max_bits)
primes = [factor for _ in range(math.ceil(n/max_bits))]

primes[-1] = (1<<((n%max_bits)+1))-1
primes[0] = primes[0] ^ (1<<0)
primes[0] = primes[0] ^ (1<<1)
p = 2

while (p * p <= n):
    if (primes[p//max_bits] & (1 << (p%max_bits))) > 0: 
        for i in range(p * 2, n+1, p): 
            primes[i//max_bits] = primes[i//max_bits] & ~(primes[i//max_bits] & (1<<(i%max_bits)))
    p += 1
tot = 0
#print(primes)
for i in range(n+1):
    if primes[i//max_bits] & (1 << (i%max_bits)) > 0:
        tot += 1
print(tot)
for qi in sys.stdin:
    qi = int(qi)
    if (primes[qi//max_bits] & (1 << qi%max_bits)) > 0:
        print(1)
    else:
        print(0)


