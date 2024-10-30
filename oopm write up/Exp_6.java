import java.util.*;
class Employee {
    private String eName;
    private int eId;
    private double eSalary;
    public Employee(String eName, int eId, double eSalary) {
        this.eName = eName;
        this.eId = eId;
        this.eSalary = eSalary;
    }

    public String getEName() {
        return eName;
    }

    public int getEId() {
        return eId;
    }

    public double getESalary() {
        return eSalary;
    }

    public void displayEmployee() {

        System.out.println("E-Name: " + eName + ", E-Id: " + eId + ", E-Salary: " + eSalary);

    }
}
class EmployeeManager {
    private Vector<Employee> employees;

    public EmployeeManager() {
        employees = new Vector<>();
    }

    public void create(int n) {
        Scanner sc = new Scanner(System.in);
        for (int i = 0; i < n; i++) {
            System.out.print("Enter Employee Name: ");
            String name = sc.next();
            System.out.print("Enter Employee Id: ");
            int id = sc.nextInt();
            System.out.print("Enter Employee Salary: ");
            double salary = sc.nextDouble();
            Employee employee = new Employee(name, id, salary);
            insert(employee);
        }
    }

    public void insert(Employee emp) {
        int i = 0;
        Comparator<Employee> salaryComparator = new Comparator<Employee>() {

            public int compare(Employee e1, Employee e2) {
                return Double.compare(e2.getESalary(), e1.getESalary());
            }
        };
        while (i < employees.size() &&
                salaryComparator.compare(employees.get(i), emp) < 0) {

            i++;
        }
        employees.add(i, emp);
    }

    public void deleteByEName(String name) {
        boolean found = false;
        for (int i = 0; i < employees.size(); i++) {
            if (employees.get(i).getEName().equals(name)) {
                employees.removeElementAt(i);
                System.out.println("Employee with name " + name + "deleted.");

                found = true;
                break;
            }
        }
        if (!found) {
            System.out.println("Employee with name " + name + " notfound.");
        }
    }

    public void deleteByEId(int id) {
        boolean found = false;
        for (int i = 0; i < employees.size(); i++) {
            if (employees.get(i).getEId() == id) {
                employees.removeElementAt(i);
                System.out.println("Employee with ID " + id + "deleted.");
                found = true;
                break;
            }
        }
        if (!found) {
            System.out.println("Employee with ID " + id + " not found.");
        }
    }

    public void displayAll() {

        if (employees.isEmpty()) {
            System.out.println("No employees to display.");
        } else {
            System.out.println("Displaying employees (highest paidfirst):");

            for (Employee emp : employees) {
                emp.displayEmployee();
            }
        }
    }
}

public class Exp_6 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        EmployeeManager manager = new EmployeeManager();
        int choice = -1;
        while (choice != 0) {
            System.out.println("\nMenu:");
            System.out.println("1. Create Employee(s)");
            System.out.println("2. Display All Employees");
            System.out.println("3. Delete Employee by Name");
            System.out.println("4. Delete Employee by ID");
            System.out.println("0. Exit");
            System.out.print("Enter your choice: ");
            choice = sc.nextInt();
            switch (choice) {
                case 1:
                    System.out.print("Enter the number of Employees to create: ");

                    int n = sc.nextInt();
                    manager.create(n);
                    break;
                case 2:
                    manager.displayAll();
                    break;
                case 3:
                    System.out.print("Enter Employee name to delete: ");
                    String nameToDelete = sc.next();
                    manager.deleteByEName(nameToDelete);
                    break;
                case 4:
                    System.out.print("Enter Employee ID to delete: ");
                    int idToDelete = sc.nextInt();
                    manager.deleteByEId(idToDelete);
                    break;
                case 0:
                    System.out.println("Exiting the program.");
                    break;
                default:
                    System.out.println("Invalid choice! Please select a valid option.");
            }
        }
        sc.close();
    }
}