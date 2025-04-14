#include "iostream"
using namespace std;

class Vehicle{
protected:
   string model;
   double rate;

public:
   Vehicle(string m, double r) : model(m), rate(r) {}

   virtual double getDailyRate() = 0;
   virtual void DisplayDetails() = 0;
};

class Car : public Vehicle{
public:
    Car(string m, double r) : Vehicle(m,r) {}

    double getDailyRate() { return rate; }

    void DisplayDetails()
    {   cout<<"Model Of Car: "<<model<<endl;
        cout<<"Daily Rate: "<<rate<<endl;
    }
};

class Bike : public Vehicle{
public:
    Bike(string m, double r) : Vehicle(m,r) {}

    double getDailyRate() { return rate; }

    void DisplayDetails()
    {   cout<<"Model of Bike: "<<model<<endl;
        cout<<"Daily Rate: "<<rate<<endl;
    }
};

int main()
{   
    Car c("Civics",24000);
    Vehicle* v = &c;
    v->getDailyRate();
    v->DisplayDetails();

    Bike b("Honda",12000);
    v = &b;
    v->getDailyRate();
    v->DisplayDetails();
}

