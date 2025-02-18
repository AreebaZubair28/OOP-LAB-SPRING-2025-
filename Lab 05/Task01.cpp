#include "iostream"
#include "string"
using namespace std;

class Car
{
public:
    int *reg_num;
    string *model;
    string owner_name;

    Car(string name, int num, string mod)
    {   owner_name = name;
        model = new string(mod);
        reg_num = new int(num);
    }

    Car(const Car &other)
    {
        reg_num = other.reg_num;
        model = other.model;
    }
     
    ~Car() {
        delete reg_num;
        delete model;
    }

    Car changeOwner(string newOwner) {
        Car newCar = *this;  // Calls copy constructor
        newCar.owner_name = newOwner;
        return newCar;
    }

    void display()
    {   cout<<endl;
        cout << "Owner Name: " << owner_name << endl;
        cout << "Registration Number: " <<*reg_num<< endl;
        cout << "Model: " << *model << endl;
        cout<<"\n------------------------"<<endl;
    }
};

int main()
{
    Car c1("Areeba", 1001, "Honda");
    Car c2 = c1.changeOwner("Aqsa");
    Car c3 = c1.changeOwner("Fatima");

    c1.display();
    c2.display();
    c3.display();
}
