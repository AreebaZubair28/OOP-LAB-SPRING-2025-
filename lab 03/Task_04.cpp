#include"iostream"
#include "string"
#include "cstring"
using namespace std;

class Laptop{
   
   string brand;
   string model;
   string processor;
   int RAM;
   int storage;
   bool IsOn;

public:

   Laptop(string b, string m, string p, int ram, int strg, bool isOn)
   {   brand = b;
       model = m;
       processor = p;
       RAM = ram;
       storage = strg;
       IsOn = isOn;
   }

   void turnOn()
   {  if(IsOn)
      { cout<<"Laptop is already On\n";
      }else{
        cout<<"Laptop is turning On...........\n";
        cout<<"Welcome.\n";
        IsOn = 1;
      }
   }

   void turnOff()
   {  if(IsOn)
      { cout<<"Laptop is turning Off...........\n";
        cout<<"Turned Off.\n";
        IsOn = 0;
      }else{
         cout<<"Laptop is already Off\n";
      }
   }

   void runnigProgram(string str)
   { if(IsOn)
      { cout<<"Program: "<<str<<" is executing......\n";
        cout<<"Program Executed.\n";
      }else{
        cout<<"Laptop is off, so program cannot br runed. Please turn On your laptop\n";
      }
   }

   void Specification()
   { cout<<"Brand: "<<brand<<endl;
     cout<<"Model: "<<model<<endl;
     cout<<"Processor: "<<processor<<endl;
     cout<<"RAM: "<<RAM<<"GB"<<endl;
     cout<<"Storage: "<<storage<<"GB"<<endl;
     cout<<"---------------------------\n\n";
   }

   void Compare(Laptop other)
   {  cout<<"Comparing............\n";
      cout<<"Brand: "<<brand<<" & Model: "<<model<<"     with"<<endl;
      cout<<"Brand: "<<other.brand<<" & Model: "<<other.model<<endl;

      if(processor == other.processor)
      { cout<<"Both laptops are same w.t.r processor.\n";
      }
      else if(processor > other.processor)
      { cout<<"Processor of Bilal's Laptop is better than Ayesha's.\n";
      }else{
        cout<<"Processor of Ayesha's Laptop is better than Bilal's.\n";
      }

      if(RAM == other.RAM)
      { cout<<"Both laptops are same w.r.t RAM.\n";
      }
      else if(RAM > other.RAM)
      { cout<<"RAM of Bilal's Laptop is better than Ayesha's.\n";
      }else{
        cout<<"RAM of Ayesha's Laptop is better than Bilal's.\n";
      }

      if(storage == other.storage)
      { cout<<"Both laptops are same w.r.t storage.\n";
      }
      else if(storage > other.storage)
      { cout<<"Storage of Bilal's Laptop is better than Ayesha's.\n";
      }else{
        cout<<"Storage of Ayesha's Laptop is better than Bilal's.\n";
      }
   }
};

int main()
{   string str;

    string brand1, model1, processor1;
    int ram1, storage1;
    bool isOn1;
    cout<<"Enter Details of Bilal's laptop: \n";
    cout<<"Enter brand: "; cin>>brand1;
    cout<<"Enter model: "; cin>>model1;
    cout<<"Enter processor: "; cin>>processor1;
    cout<<"Enter ram: "; cin>>ram1;
    cout<<"Enter storage: "; cin>>storage1;
    cout<<"Is laptop ON or OFF(1-yes/0-no)? "; cin>>isOn1;

    string brand2, model2, processor2;
    int ram2, storage2;
    bool isOn2;
    cout<<"Enter Details of Ayesha's laptop: \n";
    cout<<"Enter brand: "; cin>>brand2;
    cout<<"Enter model: "; cin>>model2;
    cout<<"Enter processor: "; cin>>processor2;
    cout<<"Enter ram: "; cin>>ram2;
    cout<<"Enter storage: "; cin>>storage2;
    cout<<"Is laptop ON or OFF(1-yes/0-no)? "; cin>>isOn2;

    Laptop laptop1(brand1,model1,processor1,ram1,storage1,isOn1);
    Laptop laptop2(brand2,model2,processor2,ram2,storage2,isOn2);

    cout<<"\n---------------------------\n";
    cout<<"Details of Bilal's Laptop\n";
    laptop1.Specification();
    cout<<"\n---------------------------\n";
    cout<<"Details of Ayesha's Laptop\n";
    laptop2.Specification();

    laptop1.Compare(laptop2);

    cout<<"Execution of Bilal's Laptop\n";
    laptop1.turnOn();
    cout<<"Enter the program to be executed: ";
    cin>>str;
    laptop1.runnigProgram(str);
    laptop1.turnOff();
    cout<<"\n\n";

    cout<<"Execution of Ayesha's Laptop\n";
    laptop2.turnOn();
    cout<<"Enter the program to be executed: ";
    cin>>str;
    laptop2.runnigProgram(str);
    laptop2.turnOff();
    cout<<"\n\n";
}
