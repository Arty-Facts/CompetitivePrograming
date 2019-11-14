# python3 
# Arturas Aleksandrauskas artal938 - TDDD95
import sys

def zeros_counter(number):
    ans, pos , rest = 0, 1, 0
    while number > 0:
        digit = number%10
        number //= 10
        if digit == 0:
            ans += (number-1) * pos + 1 + rest
        else:
            ans += number*pos
        rest += pos*digit
        pos *= 10
    return ans

# def g(n, r = 0, p = 1):
#     if n < 10:
#         return 0
#     d = n%10
#     n //= 10
#     if d == 0:
#         return 10 * g(n-1, r, p*10) + n + r 
#     else:
#         return 10 * g(n, r + d*p, p*10 ) + n


def main():
    while True:
        m, n = map(int,sys.stdin.readline().split())
        if m < 0:
            break

        ans = zeros_counter(n)
        #print("ans", ans)
        ans -= zeros_counter(m)
        #print("-ans", ans)
        ans += str(m).count("0")
        #print("+ans", ans)

        print(ans)

if __name__ == "__main__":
    main()