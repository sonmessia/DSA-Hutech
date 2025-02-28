def solve(s: str) -> int:
    i, j = 0, len(s) - 1
    cnt = 0
    while i < j:
        if s[i] != s[j]:
            cnt += min(abs(ord(s[i]) - ord(s[j])), 26 - abs(ord(s[i]) - ord(s[j])))
        i += 1
        j -= 1
    return cnt
s: str = input()
print(solve(s))