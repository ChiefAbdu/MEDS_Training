
def sqrt(num,precision = 1e-6):
    if num < 0:
        return ValueError("Cannot Return Square Root of Negative Number")
    if num == 1 or num == 0:
        return num
    low = 0
    high = num if num >= 1 else 1

    while (high - low) > precision:
        mid = (low + high) / 2
        if mid * mid < num:
            low = mid
        else:
            high = mid

    return (low + high) / 2
        

print(sqrt(16))
print(sqrt(-10))
print(sqrt(25))
print(sqrt(36))
print(sqrt(44))