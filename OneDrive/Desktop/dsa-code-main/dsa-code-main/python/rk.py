num = int(input("Enter a number: ")) # getting input to reverse it

rev_num = 0 # initial variable with 0 

# while loop until num is not 0

while num != 0:

digit = num % 10 # finding the remainder

rev_num = rev_num * 10 + digit

num //= 10 

print(f"Reversed Number Is: {rev_num}") # printing the results