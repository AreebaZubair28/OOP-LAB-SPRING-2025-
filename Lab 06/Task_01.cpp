#include "iostream"
using namespace std;

class Employee{
    string name;
    float salary;

    public:
    Employee(string n, float s) : name(n), salary(s) {}

    void display()
    {   cout<<"Employee Name: "<<name<<endl;
        cout<<"Employee Salary: "<<salary<<endl;
    }
};

class Manager : public Employee{
    float bonus;

    public:
    Manager(string n, float s, float b) : Employee(n,s), bonus(b) {}

    void display()
    {   Employee :: display();
        cout<<"Manager Bonus: "<<bonus<<endl;
    }
};

int main()
{  Manager m("Areeba",12000,1200);
   m.display();
}
