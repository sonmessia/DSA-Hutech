def find_fractions(x, y):
    for a in range(1, 10**6):  # Set an upper bound for a reasonable search
        numerator = x * a - y
        denominator = y * a
        if numerator > 0 and denominator % numerator == 0:  # Ensure b is an integer
            b = denominator // numerator
            if a < b:  # Ensure distinct fractions
                return (a, b)
    return -1  # No valid fractions found

# Example Usage
x, y = map(int, input("Enter x and y: ").split())
result = find_fractions(x, y)

if result == -1:
    print(-1)
else:
    print(f"1/{result[0]} + 1/{result[1]} = {x}/{y}")
