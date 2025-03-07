import math
from functools import reduce

def lcm(a, b):
    return a * b // math.gcd(a, b)

def count_valid_x(A, B):
    lcm_b = reduce(lcm, B)
    
    gcd_a = reduce(math.gcd, A)

    count = 0
    for x in range(lcm_b, gcd_a + 1, lcm_b):
        if gcd_a % x == 0:
            count += 1

    return count

N, M = map(int, input().split())
A = list(map(int, input().split()))
B = list(map(int, input().split()))

print(count_valid_x(A, B))
