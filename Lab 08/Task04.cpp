#include "iostream"
using namespace std;

class Currecy{
    int amount;

public:
    Currecy(int data = 0) : amount(data) {}

    Currecy operator+(Currecy& obj)
    {  Currecy temp = amount + obj.amount;
       return temp;
    }

    Currecy operator-(Currecy& obj)
    {  return amount - obj.amount; 
    }

    Currecy operator-()             
    {  return Currecy(-amount);        
    }

    Currecy& operator+=(Currecy& obj)
    {  amount += obj.amount;
    }

    Currecy& operator-=(Currecy& obj)
    {  amount -= obj.amount;
    }

    friend ostream& operator<<(ostream& os, Currecy& obj);
};

ostream& operator<<(ostream& os, Currecy& obj)
{
    os << obj.amount;
    return os;
}

int main()
{
    Currecy c1(50), c2, c3(10);

    c2 = c1;

    cout<<"Amount of Currency 1: "<<c1<<endl;
    cout<<"Amount of Currency 2: "<<c2<<endl;
    cout<<"Amount of Currency 3: "<<c3<<endl;

    c2 = c1 + c3; 
    cout<<"Amount of Currency 2 after addition: "<<c2<<endl;
   
    c2 = c1 - c3;
    cout<<"Amount of Currency 2 after subtraction: "<<c2<<endl;
   
    c2 = -c2;
    cout<<"Amount of Currency 2 after: "<<c2<<endl;

    c2+=c1;
    cout<<"Amount of Currency 2 after adding c1: "<<c2<<endl;

    c2-=c1;
    cout<<"Amount of Currency 2 after subtracting c1: "<<c2<<endl;

}
