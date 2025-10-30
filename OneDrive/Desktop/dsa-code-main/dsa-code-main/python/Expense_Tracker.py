import csv
from datetime import datetime
import os

FILE_NAME = "expenses.csv"
CATEGORIES = ["Food", "Transport", "Entertainment", "Bills", "Others"]

# ---------------------------------------------------------
# Function to initialize CSV file if not exists
# ---------------------------------------------------------
def initialize_file():
    if not os.path.exists(FILE_NAME):
        with open(FILE_NAME, "w", newline="") as file:
            writer = csv.writer(file)
            writer.writerow(["Date", "Category", "Amount", "Description"])


# ---------------------------------------------------------
# Function to add a new expense
# ---------------------------------------------------------
def add_expense():
    date_input = input("Enter date (YYYY-MM-DD) [Leave empty for today]: ").strip()
    if date_input == "":
        date_input = datetime.today().strftime("%Y-%m-%d")
    try:
        datetime.strptime(date_input, "%Y-%m-%d")
    except ValueError:
        print("Invalid date format! Use YYYY-MM-DD.")
        return

    print("Categories:", ", ".join(CATEGORIES))
    category = input("Enter category: ").strip().title()
    if category not in CATEGORIES:
        print("Invalid category! Defaulting to 'Others'.")
        category = "Others"

    try:
        amount = float(input("Enter amount: ").strip())
    except ValueError:
        print("Invalid amount! Must be a number.")
        return

    description = input("Enter description (optional): ").strip()

    with open(FILE_NAME, "a", newline="") as file:
        writer = csv.writer(file)
        writer.writerow([date_input, category, amount, description])

    print("Expense added successfully!\n")


# ---------------------------------------------------------
# Function to view all expenses
# ---------------------------------------------------------
def view_expenses():
    if not os.path.exists(FILE_NAME):
        print("No expenses recorded yet.")
        return

    print("\nAll Expenses:\n")
    total = 0
    with open(FILE_NAME, "r") as file:
        reader = csv.DictReader(file)
        for row in reader:
            print(f"{row['Date']} | {row['Category']} | ${row['Amount']} | {row['Description']}")
            total += float(row['Amount'])
    print(f"\nTotal Spent: ${total:.2f}\n")


# ---------------------------------------------------------
# Function to view expenses filtered by category
# ---------------------------------------------------------
def view_by_category():
    category = input("Enter category to filter: ").strip().title()
    if category not in CATEGORIES:
        print("Invalid category! Showing 'Others' instead.")
        category = "Others"

    total = 0
    found = False
    print(f"\nExpenses for category: {category}\n")
    with open(FILE_NAME, "r") as file:
        reader = csv.DictReader(file)
        for row in reader:
            if row["Category"] == category:
                print(f"{row['Date']} | ${row['Amount']} | {row['Description']}")
                total += float(row["Amount"])
                found = True

    if not found:
        print("No expenses found for this category.")
    else:
        print(f"\nTotal Spent in {category}: ${total:.2f}\n")


# ---------------------------------------------------------
# Main Menu
# ---------------------------------------------------------
def main():
    initialize_file()
    while True:
        print("===== Expense Tracker Menu =====")
        print("1. Add Expense")
        print("2. View All Expenses")
        print("3. View Expenses by Category")
        print("4. Exit")
        choice = input("Enter your choice: ").strip()

        if choice == "1":
            add_expense()
        elif choice == "2":
            view_expenses()
        elif choice == "3":
            view_by_category()
        elif choice == "4":
            print("Exiting... Goodbye!")
            break
        else:
            print("Invalid choice! Please select 1-4.\n")


if __name__ == "__main__":
    main()
