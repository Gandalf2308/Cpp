// import java.util.*;
// // User-defined exception class
// class NumberException extends Exception {
//     public NumberException(String message) {
//         super(message);
//     }
//     @Override
//     public String toString() {
//         return "NumberException: " + getMessage();
//     }
// }
// public class Main {
//     public static void main(String[] args) {
//         Scanner sc = new Scanner(System.in);
//         System.out.print("Enter a number: ");
//         String s = sc.nextLine();
//         try {
//             if (s.contains("3")) {
//                 sc.close();
//                 throw new NumberException("The number contains the digit 3.");
//             } else {
//                 System.out.println("The number is valid and does not contain the digit 3.");
//             }
//         } catch (NumberException e) {
//             System.out.println(e);
//         }
//     }
// }
import java.util.Scanner;
class InsufficientFundsException extends Exception {
    public InsufficientFundsException(String message) {
        super(message);
    }
    @Override
    public String toString() {
        return "InsufficientFundsException: " + getMessage();
    }
}
class BankAccount {
    private double balance;
    public BankAccount() {
        this.balance = 0.00;
    }
    public void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            System.out.println("Deposited: " + amount);
        } else {
            System.out.println("Deposit amount must be positive.");
        }
    }
    public void withdraw(double amount) throws InsufficientFundsException {
        if (amount > balance) {
            throw new InsufficientFundsException("Withdrawal amount exceeds current balance.");
        } else {
            balance -= amount;
            System.out.println("Withdrew: " + amount);
        }
    }
    public double getBalance() {
        return balance;
    }
}

// Main Class
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        BankAccount account = new BankAccount();
        Boolean flag=true;
        int choice;
        while(flag){
            System.out.println("1. Deposit");
            System.out.println("2. Withdraw");
            System.out.println("3. Check Balance");
            System.out.println("4. Exit");
            System.out.print("Enter your choice: ");
            choice = sc.nextInt();
            switch (choice) {
                case 1: 
                    System.out.print("Enter amount to deposit: ");
                    double depositAmount = sc.nextDouble();
                    account.deposit(depositAmount);
                    break;
                case 2: 
                    System.out.print("Enter amount to withdraw: ");
                    double withdrawAmount = sc.nextDouble();
                    try {
                        account.withdraw(withdrawAmount);
                    } catch (InsufficientFundsException e) {
                        System.out.println(e); // Print exception message
                    }
                    break;
                case 3:
                    System.out.println("Current Balance: " + account.getBalance());
                    break;
                case 4:
                    System.out.println("Exiting...");
                    flag=false;
                    break;

                default:
                    System.out.println("Invalid choice! Please try again.");
            }
            if(flag==false) break;
        } 
        sc.close();
    }
}