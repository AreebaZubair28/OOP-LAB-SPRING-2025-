#include <iostream>
using namespace std;

class Device{
   int deviceID;
   bool status;
   
public:
  Device(int id, bool s) : deviceID(id) ,status(s) {}
  
  void display()
  { cout<<"Id: "<<deviceID<<endl<<"Status: "<<status<<endl;
  }
};

class SmartPhone : virtual public Device{
    float screenSize;
    
public:
  SmartPhone(int id, bool s, float sc) : Device(id,s), screenSize(sc) {}
  
  void display()
  { cout<<"Screen Size: "<<screenSize<<endl;
  }
};

class SmartWatch : virtual public Device{
    bool heartRateMonitor;
    
public:
  SmartWatch(int id, bool s, bool h) : Device(id,s), heartRateMonitor(h) {}
  
  void display()
  { cout<<"Heart Rate Monitor: "<<heartRateMonitor<<endl;
  }
};

class SmartWearable : public SmartPhone, public SmartWatch{
    int stepCounter;
    
public:
   SmartWearable(int id, bool s, float sc, bool h) : Device(id,s), SmartPhone(id,s,sc), SmartWatch(id,s,h) {}
   
   void display()
   {   Device :: display();
       SmartPhone :: display();
       SmartWatch :: display();
   }
};

int main() {
    SmartWearable sw(1020,true,15,false);
    sw.display();

    return 0;
}
