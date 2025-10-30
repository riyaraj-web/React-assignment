import math

def solve_quadratic(a, b, c):
    discriminant = b**2 - 4*a*c

    if discriminant > 0:
        root1 = (-b + math.sqrt(discriminant)) / (2*a)
        root2 = (-b - math.sqrt(discriminant)) / (2*a)
        return f"Two real roots: {root1}, {root2}"
    elif discriminant == 0:
        root = -b / (2*a)
        return f"One real root: {root}"
    else:
        real = -b / (2*a)
        imaginary = math.sqrt(-discriminant) / (2*a)
        return f"Two complex roots: {real}+{imaginary}i, {real}-{imaginary}i"

a = float(input("Enter a: "))
b = float(input("Enter b: "))
c = float(input("Enter c: "))

print(solve_quadratic(a, b, c))
