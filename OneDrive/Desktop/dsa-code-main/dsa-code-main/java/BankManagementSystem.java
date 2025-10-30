import java.util.*;

// Abstraction
abstract class Account {
    private static int counter = 1000;
    protected String accountNumber;
    protected double balance;

    public Account(double initialDeposit) {
        this.accountNumber = "ACCT" + (++counter);
        this.balance = initialDeposit;
    }

    public String getAccountNumber() {
        return accountNumber;
    }

    public double getBalance() {
        return balance;
    }

    public abstract void deposit(double amount);
    public abstract void withdraw(double amount);

    @Override
    public String toString() {
        return "Account Number: " + accountNumber + ", Balance: $" + balance;
    }
}

// Inheritance and Polymorphism (overriding)
class SavingsAccount extends Account {
    private double interestRate = 0.04;

    public SavingsAccount(double deposit) {
        super(deposit);
    }

    @Override
    public void deposit(double amount) {
        balance += amount + (amount * interestRate);
    }

    @Override
    public void withdraw(double amount) {
        if (amount <= balance) {
            balance -= amount;
        } else {
            System.out.println("Insufficient balance.");
        }
    }
}

class CurrentAccount extends Account {
    private double overdraftLimit = 500;

    public CurrentAccount(double deposit) {
        super(deposit);
    }

    @Override
    public void deposit(double amount) {
        balance += amount;
    }

    @Override
    public void withdraw(double amount) {
        if (balance + overdraftLimit >= amount) {
            balance -= amount;
        } else {
            System.out.println("Overdraft limit exceeded.");
        }
    }
}

// Encapsulation
class Customer {
    private String customerId;
    private String name;
    private List<Account> accounts;

    public Customer(String customerId, String name) {
        this.customerId = customerId;
        this.name = name;
        this.accounts = new ArrayList<>();
    }

    public String getCustomerId() {
        return customerId;
    }

    public String getName() {
        return name;
    }

    public void addAccount(Account account) {
        accounts.add(account);
    }

    public List<Account> getAccounts() {
        return accounts;
    }

    @Override
    public String toString() {
        return "Customer ID: " + customerId + ", Name: " + name;
    }
}

// Aggregation - Bank has Customers
class Bank {
    private String name;
    private Map<String, Customer> customers;

    public Bank(String name) {
        this.name = name;
        this.customers = new HashMap<>();
    }

    public void addCustomer(Customer customer) {
        customers.put(customer.getCustomerId(), customer);
    }

    public Customer getCustomer(String id) {
        return customers.get(id);
    }

    public void displayAllCustomers() {
        for (Customer c : customers.values()) {
            System.out.println(c);
            for (Account a : c.getAccounts()) {
                System.out.println("  -> " + a);
            }
        }
    }
}

// Main Class
public class BankManagementSystem {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        Bank bank = new Bank("Global Bank");

        Customer c1 = new Customer("C101", "Alice");
        Account a1 = new SavingsAccount(1000);
        Account a2 = new CurrentAccount(2000);
        c1.addAccount(a1);
        c1.addAccount(a2);

        Customer c2 = new Customer("C102", "Bob");
        Account a3 = new SavingsAccount(1500);
        c2.addAccount(a3);

        bank.addCustomer(c1);
        bank.addCustomer(c2);

        // Polymorphism (method overriding at runtime)
        a1.deposit(500);   // Applies interest
        a2.withdraw(2500); // Uses overdraft
        a3.withdraw(300);  // Simple savings withdrawal

        bank.displayAllCustomers();

        scanner.close();
    }
}
