#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

class Employee {
public:
    string id;
    int age;
    string gender;
    int salary;

    Employee(string id, int age, string gender, int salary) {
        this->id = id;
        this->age = age;
        this->gender = gender;
        this->salary = salary;
    }

    bool operator<(const Employee& other) const {
        if (salary != other.salary) {
            return salary < other.salary;
        }
        if (age != other.age) {
            return age < other.age;
        }
        if (gender != other.gender) {
            return gender == "f";
        }
        return id < other.id;
    }
};

vector<Employee> readCSV(string fileName) {
    vector<Employee> employees;
    ifstream file(fileName);
    if (file) {
        string line;
        while (getline(file, line)) {
            stringstream ss(line);
            string id, gender;
            int age, salary;
            getline(ss, id, ',');
            ss >> age;
            ss.ignore();
            getline(ss, gender, ',');
            ss >> salary;
            employees.push_back(Employee(id, age, gender, salary));
        }
    }
    return employees;
}

void printEmployeesBySalary(vector<Employee> employees) {
    sort(employees.begin(), employees.end());

    int currentSalary = -1;
    for (const Employee& employee : employees) {
        if (employee.salary != currentSalary) {
            if (currentSalary != -1) {
                cout << endl;
            }
            currentSalary = employee.salary;
            cout << currentSalary << ": ";
        }
        if (employee.salary == currentSalary) {
            cout << employee.id << ",";
        }
    }
    cout << endl;
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        cout << "Usage: " << argv[0] << " <csv_file_name>" << endl;
        return 1;
    }

    string fileName = argv[1];
    vector<Employee> employees = readCSV(fileName);
    printEmployeesBySalary(employees);

    return 0;
}
