def is_zig_zag_number(n):
    digits = list(map(int, str(n)))
    
    if len(digits) == 1:
        return False
    
    if len(digits) == 2:
        return digits[0] != digits[1]
    
    # Check if first pattern is increasing or decreasing
    increasing = digits[0] < digits[1]
    
    for i in range(1, len(digits)):
        if increasing:
            if digits[i-1] >= digits[i]:
                return False
        else:
            if digits[i-1] <= digits[i]:
                return False
        increasing = not increasing
        
    return True

def generate_zig_zag_numbers(left, right):
    numbers = []
    for i in range(left, right + 1):
        if is_zig_zag_number(i):
            numbers.append(i)
    return numbers

A = int(input())
B = int(input())
m = int(input())

zig_zag_number = generate_zig_zag_numbers(A, B)
# print(zig_zag_number)
cnt = 0
for i in zig_zag_number:
    if i % m == 0:
        cnt = (cnt + 1) % 10000
print(cnt)
