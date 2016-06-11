#!/usr/bin/env python
import sys
import math

def sum2(n):
    t = n * (n + 1) * (2 * n + 1)
    return t / 6

def main():
    ans = 0
    n = int(sys.argv[1])
    l = int(math.sqrt(n))
    for j in range(1, l + 1):
        f = sum2(n / j)
        g = sum2(j)
        t = j * j * (n / j - (j - 1))
        #print f, g, t
        ans += (f - g + t)
    print ans % 1000000000

main()
