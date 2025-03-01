import math
from functools import reduce

def get_divisors(n):
    divisors = []
    for i in range(1, int(math.sqrt(n)) + 1):
        if n % i == 0:
            divisors.append(i)
            if i != n // i:
                divisors.append(n // i)
    return sorted(divisors)

def binary_search(arr, target):
    left, right = 0, len(arr) - 1
    while left <= right:
        mid = (left + right) // 2
        if arr[mid] >= target:
            right = mid - 1
        else:
            left = mid + 1
    return left

def count_valid_x(A, B):

    gcd_a = reduce(math.gcd, A)

    lcm_b = reduce(lambda x, y: x * y // math.gcd(x, y), B)

    if lcm_b > gcd_a:
        return 0

    divisors = get_divisors(gcd_a)

    start_idx = binary_search(divisors, lcm_b)

    count = 0
    for i in range(start_idx, len(divisors)):
        if divisors[i] % lcm_b == 0:
            count += 1
            
    return count

N, M = map(int, input().split())
A = list(map(int, input().split()))
B = list(map(int, input().split()))
ans = count_valid_x(A, B)
print(ans)
