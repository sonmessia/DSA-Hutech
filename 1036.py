import math
from itertools import combinations

def distance(p1, p2):
    return math.sqrt((p1[0] - p2[0]) ** 2 + (p1[1] - p2[1]) ** 2)

def convex_hull(points):
    points = sorted(points)
    lower = []
    for p in points:
        while len(lower) >= 2 and cross(lower[-2], lower[-1], p) <= 0:
            lower.pop()
        lower.append(p)
    upper = []
    for p in reversed(points):
        while len(upper) >= 2 and cross(upper[-2], upper[-1], p) <= 0:
            upper.pop()
        upper.append(p)
    return lower[:-1] + upper[:-1]

def cross(o, a, b):
    return (a[0] - o[0]) * (b[1] - o[1]) - (a[1] - o[1]) * (b[0] - o[0])

def smallest_perimeter(points, K):
    hull = convex_hull(points)
    n = len(hull)
    if K > n:
        return float('inf')
    min_perimeter = float('inf')
    for comb in combinations(hull, K):
        perimeter = sum(distance(comb[i], comb[(i + 1) % K]) for i in range(K))
        min_perimeter = min(min_perimeter, perimeter)
    return min_perimeter

N, K = map(int, input().split())
points = [tuple(map(int, input().split())) for _ in range(N)]

result = smallest_perimeter(points, K)
print(f"{result:.4f}")