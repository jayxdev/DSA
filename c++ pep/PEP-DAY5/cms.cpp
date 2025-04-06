#include <iostream>
#include <string>

class Employee {
protected:
    int id;
    std::string name;

public:
    Employee(int id, const std::string& name) : id(id), name(name) {}
    virtual ~Employee() {}
    virtual double calculateSalary() = 0;

    std::string getName() {
        return name;
    }

    int getId() {
        return id;
    }
};

class FullTimeEmployee : public Employee {
private:
    double fixedSalary;

public:
    FullTimeEmployee(int id, const std::string& name, double fixedSalary)
        : Employee(id, name), fixedSalary(fixedSalary) {}

    double calculateSalary() override {
        return fixedSalary;
    }
};

class PartTimeEmployee : public Employee {
private:
    double hourlyWage;
    int hoursWorked;

public:
    PartTimeEmployee(int id, const std::string& name, double hourlyWage, int hoursWorked)
        : Employee(id, name), hourlyWage(hourlyWage), hoursWorked(hoursWorked) {}

    double calculateSalary() override {
        return hourlyWage * hoursWorked;
    }
};

class CommissionEmployee : public Employee {
private:
    double baseSalary;
    double totalSales;
    double commissionRate;

public:
    CommissionEmployee(int id, const std::string& name, double baseSalary, double totalSales, double commissionRate)
        : Employee(id, name), baseSalary(baseSalary), totalSales(totalSales), commissionRate(commissionRate) {}

    double calculateSalary() override {
        return baseSalary + (totalSales * commissionRate);
    }
};

int main() {
    // Create employee objects and calculate salaries
    FullTimeEmployee fullTimeEmployee(1, "John Doe", 5000.0);
    PartTimeEmployee partTimeEmployee(2, "Jane Smith", 15.0, 40);
    CommissionEmployee commissionEmployee(3, "Mike Johnson", 2000.0, 10000.0, 0.05);

    std::cout << "Full Time Employee Salary: " << fullTimeEmployee.calculateSalary() << std::endl;
    std::cout << "Part Time Employee Salary: " << partTimeEmployee.calculateSalary() << std::endl;
    std::cout << "Commission Employee Salary: " << commissionEmployee.calculateSalary() << std::endl;

    return 0;
}