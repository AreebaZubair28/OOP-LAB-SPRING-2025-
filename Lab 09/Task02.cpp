#include "iostream"
using namespace std;

class SmartDevice{
public:
   virtual void turnOn() = 0;
   virtual void turnOff() = 0;
   virtual bool getStatus() = 0;
};

class LightBulb : public SmartDevice{
    bool isOn;
    int brightness;
public:
    LightBulb(bool isOn, int b) : isOn(isOn), brightness(b) {}

    void turnOn()
    {  if(isOn)
       {  cout<<"Light Bulb is already On\n";
       }else{
          isOn = 1;
          cout<<"Light Bulb has On\n";
       }   
    }

    void turnOff()
    { if(!isOn)
       {  cout<<"Light Bulb is already Off\n";
       }else{
          isOn = 0;
          cout<<"Light Bulb has Off\n";
       }   
    }

    bool getStatus()  { return isOn; }
};

class Thermostat : public SmartDevice{
    bool isOn;
    double temperature;
public:
    Thermostat(bool isOn, double t) : isOn(isOn), temperature(t) {}

    void turnOn()
    {  if(isOn)
       {  cout<<"Thermostat is already On\n";
       }else{
          isOn = 1;
          cout<<"Thermostat has On\n";
       }   
    }

    void turnOff()
    { if(!isOn)
       {  cout<<"Thermostat is already Off\n";
       }else{
          isOn = 0;
          cout<<"Thermostat has Off\n";
       }   
    }
    bool getStatus()  { return isOn; }
};

int main()
{
    LightBulb l(0,20);
    Thermostat t(1,50);

    l.turnOff();
    l.turnOn();
    cout<<endl;
    bool isOn1 = l.getStatus();


    t.turnOn();
    t.turnOff();
    cout<<endl;
    bool isOn2 = t.getStatus();

    cout<<"Status of Bulb: "<<isOn1<<endl;
    cout<<"Status of Thermostat: "<<isOn2<<endl<<endl;
}

