#include <iostream>
#include <string>
using namespace std;


class AbstractEmployee {
public:
    virtual void AskForPromotion() = 0;
};



// Cyclomatic Complexity = 2
// Cognitive Complexity  = 1
bool IsEligibleForPromotion(int yearsOfExperience) {
    return yearsOfExperience >= 5;
}



// Cyclomatic Complexity = 2
// Cognitive Complexity  = 1
bool CanAddEmployee(int currentCount, int maxEmployees) {
    return currentCount < maxEmployees;
}

class Employee : public AbstractEmployee {
protected:
    string Role;
    int    YearsOfExperience;
private:
    string Name;
    string Company;
    int    Age;
    double BaseSalary;
    string PerformanceReview;

public:
    // Getters & Setters
    void   setName(string name)                   { Name = name; }
    string getName()                              { return Name; }
    void   setCompany(string company)             { Company = company; }
    string getCompany()                           { return Company; }
    void   setAge(int age)                        { Age = age; }
    int    getAge()                               { return Age; }
    void   setRole(string role)                   { Role = role; }
    string getRole()                              { return Role; }
    void   setYearsOfExperience(int years)        { YearsOfExperience = years; }
    int    getYearsOfExperience()                 { return YearsOfExperience; }
    void   setBaseSalary(double salary)           { BaseSalary = salary; }
    double getBaseSalary()                        { return BaseSalary; }
    void   setPerformanceReview(string review)    { PerformanceReview = review; }
    string getPerformanceReview()                 { return PerformanceReview; }

    Employee(string name = "", string company = "", int age = 0,
             string role = "", int yearsOfExperience = 0,
             double baseSalary = 0.0, string performanceReview = "")
        : Name(name), Company(company), Age(age), Role(role),
          YearsOfExperience(yearsOfExperience), BaseSalary(baseSalary),
          PerformanceReview(performanceReview) {}



    // Cyclomatic Complexity = 1
    // Cognitive Complexity  = 0
    void introduceYourself() {
        cout << "Name               : " << Name              << endl;
        cout << "Company            : " << Company           << endl;
        cout << "Age                : " << Age               << endl;
        cout << "Role               : " << Role              << endl;
        cout << "Years Of Experience: " << YearsOfExperience << endl;
        cout << "Base Salary        : " << BaseSalary        << endl;
        cout << "Performance Review : " << PerformanceReview << endl;
    }



    // Cyclomatic Complexity = 2
    // Cognitive Complexity  = 1
    void AskForPromotion() {
        if (IsEligibleForPromotion(YearsOfExperience))
            cout << Name << " is promoted!\n" << endl;
        else
            cout << Name << " is not promoted! Gain more experience.\n" << endl;
    }
};

class EmployeeManagement {
private:
    static const int MAX_EMPLOYEES = 7;
    Employee employees[MAX_EMPLOYEES];
    int      employeeCount;



    // Cyclomatic Complexity = 3
    // Cognitive Complexity  = 3
    int findEmployeeIndex(const string& name) {
        for (int i = 0; i < employeeCount; i++) {
            if (employees[i].getName() == name)
                return i;
        }
        return -1;
    }



    // Cyclomatic Complexity = 2
    // Cognitive Complexity  = 1
    void shiftEmployeesLeft(int idx) {
        for (int j = idx; j < employeeCount - 1; j++)
            employees[j] = employees[j + 1];
    }

public:
    EmployeeManagement() : employeeCount(0) {}



    // Cyclomatic Complexity = 2
    // Cognitive Complexity  = 1
    void addEmployee(string name, string company, int age, string role,
                     int yearsOfExperience, double baseSalary,
                     string performanceReview) {
        if (!CanAddEmployee(employeeCount, MAX_EMPLOYEES)) {
            cout << "Employee list is full. Cannot add more employees.\n";
            return;
        }
        employees[employeeCount++] = Employee(name, company, age, role,
                                              yearsOfExperience, baseSalary,
                                              performanceReview);
        cout << "Employee added successfully!\n";
    }



    // Cyclomatic Complexity = 3
    // Cognitive Complexity  = 2
    void removeEmployee(const string& name) {
        int idx = findEmployeeIndex(name);
        if (idx == -1) {
            cout << "Employee not found.\n";
            return;
        }
        shiftEmployeesLeft(idx);
        employeeCount--;
        cout << "\nEmployee list after removal:-\n";
    }



    // Cyclomatic Complexity = 3
    // Cognitive Complexity  = 2
    void updateEmployee(const string& name, string newRole, int newAge,
                        int newYearsOfExperience, double newBaseSalary,
                        string newPerformanceReview) {
        int idx = findEmployeeIndex(name);
        if (idx == -1) {
            cout << "Employee not found.\n";
            return;
        }
        employees[idx].setRole(newRole);
        employees[idx].setAge(newAge);
        employees[idx].setYearsOfExperience(newYearsOfExperience);
        employees[idx].setBaseSalary(newBaseSalary);
        employees[idx].setPerformanceReview(newPerformanceReview);
        cout << "\nUpdated the Employee List:-\n";
    }



    // Cyclomatic Complexity = 3
    // Cognitive Complexity  = 2
    void viewEmployees() {
        if (employeeCount == 0) {
            cout << "No employees to display.\n";
            return;
        }
        cout << "\nEmployee List:\n";
        cout << "======================================\n";
        for (int i = 0; i < employeeCount; i++) {
            cout << "Employee " << i + 1 << ":\n";
            employees[i].introduceYourself();
            cout << "--------------------------------------\n";
        }
    }



    // Cyclomatic Complexity = 3
    // Cognitive Complexity  = 2
    void calculatePayroll(const string& name,
                          double bonus      = 0.0,
                          double deductions = 0.0) {
        int idx = findEmployeeIndex(name);
        if (idx == -1) {
            cout << "Employee not found.\n";
            return;
        }
        double finalSalary = employees[idx].getBaseSalary() + bonus - deductions;
        cout << "\nPayroll for " << name << ":\n";
        cout << "--------------------------------------\n";
        cout << "Base Salary  : " << employees[idx].getBaseSalary() << endl;
        cout << "Bonus        : " << bonus      << endl;
        cout << "Deductions   : " << deductions << endl;
        cout << "Final Salary : " << finalSalary << endl;
        cout << "--------------------------------------\n";
    }



    // Cyclomatic Complexity = 3
    // Cognitive Complexity  = 2
    void generateReport() {
        if (employeeCount == 0) {
            cout << "No employees to display in the report.\n";
            return;
        }
        cout << "\nGenerating Employee Report:\n";
        cout << "--------------------------------------\n";
        for (int i = 0; i < employeeCount; i++) {
            cout << "Name               : " << employees[i].getName()              << endl;
            cout << "Role               : " << employees[i].getRole()              << endl;
            cout << "Salary             : " << employees[i].getBaseSalary()        << endl;
            cout << "Performance Review : " << employees[i].getPerformanceReview() << endl;
            cout << "--------------------------------------\n";
        }
    }

    int       getEmployeeCount()      { return employeeCount; }
    Employee& getEmployee(int index)  { return employees[index]; }
};



int main() {
    EmployeeManagement management;

    management.addEmployee("Abdullah", "Codistan", 25, "Senior Developer", 7, 80000, "Excellent");
    management.addEmployee("Usman",    "Codistan", 21, "JR Developer",     3, 50000, "Good");
    management.addEmployee("Zayam",    "Codistan", 19, "Intern",           1,  1000, "N/A");

    management.viewEmployees();

    management.updateEmployee("Zayam", "Mid-Level Developer", 21, 4, 55000, "Very Good");
    management.viewEmployees();

    management.removeEmployee("Zayam");
    management.viewEmployees();

    management.calculatePayroll("Usman", 5000, 2000);
    management.generateReport();

    for (int i = 0; i < management.getEmployeeCount(); i++)
        management.getEmployee(i).AskForPromotion();

    // Testing with Bilal (added after removal of Zayam)
    management.addEmployee("Bilal", "Codistan", 30, "Team Lead", 8, 95000, "Outstanding");
    management.generateReport();
    management.getEmployee(management.getEmployeeCount() - 1).AskForPromotion();

    return 0;
}
