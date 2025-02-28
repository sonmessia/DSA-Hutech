def solve(a: list, b: list) -> int:
    i , j = len(a) - 1, len(b) - 1
    tmp = 0
    ans = ""
    while i >= 0 and j >= 0:
        num1 = int(a[i])
        num2 = int(b[j])
        total = num1 + num2 + tmp
        tmp = total // 10
        ans += str(total % 10)
        i -= 1
        j -= 1
    while i >= 0:
        total = int(a[i]) + tmp
        tmp = total // 10
        ans += str(total % 10)
        i -= 1
    while j >= 0:
        total = int(b[j]) + tmp
        tmp = total // 10
        ans += str(total % 10)
        j -= 1
    if tmp > 0:
        ans += str(tmp)
    return "".join(ans[::-1]) if ans != "" else "0"

n, m = map(int, input().split())
a = list(map(int, input().split()))
b = list(map(int, input().split()))

print(solve(a, b))