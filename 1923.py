from functools import reduce
import math
def lcm(x, y):
    return x * y // math.gcd(x, y)

def get_divisor(n: int) -> list:
    divisors = []
    for i in range(1, int(n ** 0.5) + 1):
        if n % i == 0:
            divisors.append(i)
            if i != n // i:
                divisors.append(n // i)
    return sorted(divisors)

def binary_search(arr: list, target: int) -> int:
    low, high = 0, len(arr) - 1
    while low <= high:
        mid = (low + high) // 2
        if arr[mid] >= target:
            high = mid - 1
        else:
            low = mid + 1
    return low
def solve(A: list, B: list) -> int:
    gcd_a = reduce(math.gcd, A)
    lcm_b = reduce(lambda x, y: lcm(x, y), B)
    cnt = 0
    divisors = get_divisor(gcd_a)
    
    startIndex = binary_search(divisors, lcm_b)
    
    for i in range(startIndex, len(divisors)):
        if divisors[i] % lcm_b == 0:
            cnt += 1
    return cnt

N, M = map(int, input().split())
A = list(map(int, input().split()))
B = list(map(int, input().split()))
print(solve(A, B))
