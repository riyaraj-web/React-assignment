# define a factorial function

def factorial(num):

if num == 0: # return 1 if num is 0

return 1

return num * factorial(num - 1) # return factorial of num 

ans = int(input("Enter a number to find factorial: ")) # getting input to find factorial

print(f"The Factorial of {ans} is {factorial(ans)}") # printing factorial of a number

