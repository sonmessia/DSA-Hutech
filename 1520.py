import math
N, A, B = map(int, input().split())
W = list(map(int, input().split()))

dp = [0] * (N + 1)
dp[0] = min(math.ceil(A/W[0]), math.ceil(B/W[0]))
for i in range(1, N):
    dp[i] = min(math.ceil(A/W[i]), math.ceil(B/W[i])) + dp[i-1]
print(dp[N-1])