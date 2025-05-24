def countOfWitch(arr: list, S: int) -> int:
    n = len(arr)
    count = 0
    left, right = 0, n - 1
    
    while left < right:
        if arr[left] + arr[right] > S:
            count += right - left
            right -= 1
        else:
            left += 1
    return count

if __name__ == "__main__":
    input = __import__('sys').stdin.readline
    while True:
        n, S = map(int, input().split())
        if n == 0 and S == 0:
            break
        arr = [0] * n
        for i in range(n):
            arr[i] = int(input())
        arr.sort()
        print(countOfWitch(arr, S))
