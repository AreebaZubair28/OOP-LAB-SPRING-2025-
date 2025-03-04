#include "iostream"
using namespace std;

class Vehicle{
    string brand;
    int speed;

public:
    Vehicle(string n, int s) : brand(n), speed(s) {}
    void displayDetails()
    {   cout<<"Brand: "<<brand<<endl;
        cout<<"Speed: "<<speed<<" km/hr"<<endl;
    }
};

class Car : public Vehicle{
   int seats;

public:
   Car(string n, int s, int seat) : Vehicle(n,s) , seats(seat) {}
   
   void displayDetails()
   {  Vehicle :: displayDetails();
      cout<<"Seating Capacity: "<<seats<<endl;
   }
};

class ElectricCar: public Car{
    int batteryLife;

public:
    ElectricCar(string n, int s, int seat, int b) : Car(n,s,seat) , batteryLife(b) {}
    
    void displayDetails()
    {  Car :: displayDetails();
       cout<<"Battery Life: "<<batteryLife<<endl;
    }
};

int main()
{ 
  ElectricCar e("car",20,4,5);
  e.displayDetails();
}
