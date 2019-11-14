# python3 
# Arturas Aleksandrauskas artal938 - TDDD95
import sys

def is_happy(number):
    seen_numbers = set()
    while number > 1 and (number not in seen_numbers):
        seen_numbers.add(number)
        number = sum(map(lambda x: int(x)**2 , list(str(number))))
    return number == 1

def happy_primes(n):
    prime = [True for i in range(n+1)] 
    prime[1] = False
    prime[0] = False
    p = 2
    while (p * p <= n): 
        if (prime[p] == True): 
            for i in range(p * 2, n+1, p): 
                prime[i] = False
        p += 1

    for i, p in enumerate(prime):
        if p and not is_happy(i):
            prime[i] = False
    return prime

def main():
    happy = happy_primes(10000)
    tests = int(sys.stdin.readline().strip())
    for _ in range(tests):
        k, m = map(int,sys.stdin.readline().split())
        if happy[m]:
            print(k,m,"YES")
        else:
            print(k,m,"NO")

if __name__ == "__main__":
    main()