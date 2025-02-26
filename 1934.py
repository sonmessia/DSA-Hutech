




string, q = map(str ,input().split())
q = int(q)
dp = [[0 for _ in range(len(string) + 1)] for _ in range(26)]
for i in range(1, len(string) + 1):
    for j in range(26):
        dp[j][i] = dp[j][i - 1]
    dp[ord(string[i - 1]) - 97][i] += 1
    
while q:
    