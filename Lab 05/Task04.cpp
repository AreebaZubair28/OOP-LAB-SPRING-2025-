#include "iostream"
#include "string"
using namespace std;

class Battery{
public:
  int capacity;

  Battery(int c) : capacity(c) {}

  void display()
  {
    cout<<"Battery capacity: "<<capacity<<" mAh"<<endl;
    cout<<"-----------------------\n";
  }
};

class SmartPhone{
public:
  string name;
  Battery b;
   SmartPhone(string n,int c) : name(n) , b(c) {}

  void diplay()
  { cout<<"SmartPhone Model: "<<name<<endl;
    b.display();
  }

};

int main()
{
    SmartPhone s1("Iphone 15",4530);
    SmartPhone s2("Galaxy S24",2020);
    s1.diplay();  s2.diplay();
}
