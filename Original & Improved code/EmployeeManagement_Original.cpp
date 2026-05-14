#include <iostream> 
#include <string> 
using namespace std; 
class AbstractEmployee { 
public: 
virtual void AskForPromotion() = 0; 
}; 
class Employee : public AbstractEmployee { 
protected: 
string Role; 
int YearsOfExperience; 
private: 
string Name; 
string Company; 
int Age; 
double BaseSalary; 
string PerformanceReview; 
 
public: 
 
    void setName(string name) { 
        Name = name; 
    } 
    string getName() { 
        return Name; 
    } 
 
    void setCompany(string company) { 
        Company = company; 
    } 
    string getCompany() { 
        return Company; 
    } 
 
    void setAge(int age) { 
        Age = age; 
    } 
    int getAge() { 
        return Age; 
    } 
 
    void setRole(string role) { 
        Role = role; 
    } 
    string getRole() { 
        return Role; 
    } 
 
    void setYearsOfExperience(int years) { 
        YearsOfExperience = years; 
    } 
    int getYearsOfExperience() { 
        return YearsOfExperience; 
    } 
 
    void setBaseSalary(double salary) { 
        BaseSalary = salary; 
    } 
    double getBaseSalary() { 
        return BaseSalary; 
    } 
 
    void setPerformanceReview(string review) { 
        PerformanceReview = review; 
    } 
    string getPerformanceReview() { 
        return PerformanceReview; 
    } 
 
 
    Employee(string name = "", string company = "", int age = 0, string role 
= "", int yearsOfExperience = 0, double baseSalary = 0.0, string 
performanceReview = "") { 
        Name = name; 
        Company = company; 
        Age = age; 
        Role = role; 
        YearsOfExperience = yearsOfExperience; 
        BaseSalary = baseSalary; 
        PerformanceReview = performanceReview; 
    } 
 
 
    void introduceYourself() { 
        cout << "Name               : " << Name << endl; 
        cout << "Company            : " << Company << endl; 
        cout << "Age                : " << Age << endl; 
        cout << "Role               : " << Role << endl; 
        cout << "Years Of Experience: " << YearsOfExperience << endl; 
        cout << "Base Salary        : " << BaseSalary << endl; 
        cout << "Performance Review : " << PerformanceReview << endl; 
    } 
 
 
    void AskForPromotion() { 
        if (YearsOfExperience >= 5) 
            cout << Name << " is promoted!\n" << endl; 
        else 
            cout << Name << " is not promoted! Gain more experience.\n" << 
endl; 
    } 
}; 
 
class EmployeeManagement { 
private: 
    static const int MAX_EMPLOYEES = 7; 
    Employee employees[MAX_EMPLOYEES]; 
    int employeeCount; 
 
public: 
    EmployeeManagement() { employeeCount = 0; } 
 
    void addEmployee(string name, string company, int age, string role, int 
yearsOfExperience, double baseSalary, string performanceReview) { 
        if (employeeCount < MAX_EMPLOYEES) { 
            employees[employeeCount] = Employee(name, company, age, role, 
yearsOfExperience, baseSalary, performanceReview); 
            employeeCount++; 
            cout << "Employee added successfully!\n"; 
        } else { 
            cout << "Employee list is full. Cannot add more employees.\n"; 
        } 
    } 
 
 
 
    void removeEmployee(string name) { 
        for (int i = 0; i < employeeCount; i++) { 
            if (employees[i].getName() == name) { 
                for (int j = i; j < employeeCount - 1; j++) { 
                    employees[j] = employees[j + 1]; 
                } 
                employeeCount--; 
                cout << "\nEmployee list after removal:-\n"; 
                return; 
            } 
        } 
    } 
 
    void updateEmployee(string name, string newRole, int newAge, int 
newYearsOfExperience, double newBaseSalary, string newPerformanceReview) { 
        for (int i = 0; i < employeeCount; i++) { 
            if (employees[i].getName() == name) { 
                employees[i].setRole(newRole); 
                employees[i].setAge(newAge); 
                employees[i].setYearsOfExperience(newYearsOfExperience); 
                employees[i].setBaseSalary(newBaseSalary); 
                employees[i].setPerformanceReview(newPerformanceReview); 
                cout << "\nUpdated the Employee List:-\n"; 
                return; 
            } 
        } 
        cout << "Employee not found.\n"; 
    } 
 
    void viewEmployees() { 
        if (employeeCount == 0) { 
            cout << "No employees to display.\n"; 
        } else { 
            cout << "\nEmployee List:\n"; 
            cout << "======================================\n"; 
            for (int i = 0; i < employeeCount; i++) { 
                cout << "Employee " << i + 1 << ":\n"; 
                employees[i].introduceYourself(); 
                cout << "--------------------------------------\n"; 
            } 
        } 
    } 
 
    void calculatePayroll(string name, double bonus = 0.0, double deductions 
= 0.0) { 
        for (int i = 0; i < employeeCount; i++) { 
            if (employees[i].getName() == name) { 
                double finalSalary = employees[i].getBaseSalary() + bonus - 
deductions; 
                cout << "\nPayroll for " << name << ":\n"; 
                cout << "--------------------------------------\n"; 
                cout << "Base Salary        : " << 
employees[i].getBaseSalary() << endl; 
                cout << "Bonus              : " << bonus << endl; 
                cout << "Deductions         : " << deductions << endl; 
                cout << "Final Salary       : " << finalSalary << endl; 
                cout << "--------------------------------------\n"; 
                return; 
            } 
        } 
        cout << "Employee not found.\n"; 
    } 
 
 
    int getEmployeeCount() { 
        return employeeCount; 
    } 
 
 
    Employee& getEmployee(int index) { 
        return employees[index]; 
    } 
 
 
 
    void generateReport() { 
        if (employeeCount == 0) { 
            cout << "No employees to display in the report.\n"; 
        } else { 
            cout << "\nGenerating Employee Report:\n"; 
            cout << "--------------------------------------\n"; 
            for (int i = 0; i < employeeCount; i++) { 
                cout << "Name               : " << employees[i].getName() << 
endl; 
                cout << "Role               : " << employees[i].getRole() << 
endl; 
                cout << "Salary             : " << 
employees[i].getBaseSalary() << endl; 
                cout << "Performance Review : " << 
employees[i].getPerformanceReview() << endl; 
                cout << "--------------------------------------\n"; 
            } 
        } 
    } 
}; 
 
 
 
int main() { 
    EmployeeManagement management; 
 
 
    management.addEmployee("Usman", "Codistan", 21, "JR Developer", 3, 50000, 
"Good"); 
    management.addEmployee("Abdullah", "Codistan", 25, "Senior Developer", 7, 
80000, "Excellent"); 
    management.addEmployee("Umer", "Codistan", 19, "Intern", 1, 1000, "N/A"); 
 
    management.viewEmployees(); 
 
    management.updateEmployee("Umer", "Mid-Level Developer", 21, 4, 55000, 
"Very Good"); 
 
    management.viewEmployees(); 
 
    management.removeEmployee("Umer"); 
 
    management.viewEmployees(); 
 
management.calculatePayroll("Usman", 5000, 2000); 
management.generateReport(); 
for (int i = 0; i < management.getEmployeeCount(); i++) { 
management.getEmployee(i).AskForPromotion(); 
} 
return 0; 
} 