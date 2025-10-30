n = 11
if n <= 1:
    print(False)
else:
    is_prime = True  # Flag variable
    for i in range(2, int(n**0.5) + 1):
        if n % i == 0:
            is_prime = False
            break
    print(is_prime)