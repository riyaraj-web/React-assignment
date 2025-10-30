def max_of_two_numbers(a, b):
    return a if a > b else b

print(max_of_two_numbers(max_of_two_numbers(10, 20), max_of_two_numbers(-5, -10)))