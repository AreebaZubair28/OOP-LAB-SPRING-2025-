#include "iostream"
using namespace std;

class TeaMug{
    
    string brand;
    string color;
    bool capacity;
    int CurrentFillLevel;


public:
    TeaMug(string b, string c, int fill, bool ca)
    {
        brand = b;
        color = c;
        CurrentFillLevel = fill;
        capacity = ca;
    }

    void sip()
    {   if(CurrentFillLevel <= 0 )
        {
            cout<<"Mug is empty. It's time for a fresh cup\n";
            return;
        }

        int numOfSip;
        cout<<"How many sips have you taken: ";
        cin>>numOfSip;

        if(numOfSip > CurrentFillLevel)
        {   cout<<"Your mug is running out of tea. Have the remaing one\n";
            CurrentFillLevel = 0;
            cout<<"Remaing Capacity: "<<CurrentFillLevel<<endl;
        }else{
            cout<<"Drinking-------------------\n";
            CurrentFillLevel-=numOfSip;
            cout<<"Current fill level decreased by "<<numOfSip<<endl;
            cout<<"Remaing Capacity: "<<CurrentFillLevel<<endl;
        }
        capacity = 1;
    }

    void refill()
    {  if(capacity)
       {   CurrentFillLevel = 100;
           cout<<"Refilling Mug-------------------\n";
           cout<<"Mug has refilled"<<endl;
           capacity = 0;
       }else{
            cout<<"Mug can't be refilled\n";
       }
    }

    void DisplayStatus()
    {   cout<<"\nMug Details:\n";
        cout<<"Brand: "<<brand<<endl;
        cout<<"Color: "<<color<<endl;
        cout<<"Current Fill Level: "<<CurrentFillLevel<<endl;
        cout<<"Capacity: "<<(capacity ? "Yes" : "No")<<endl;
    }
};

int main()
{   string brand;
    string color;
    bool capacity;
    int CurrentFillLevel;

    cout<<"Brand: ";
    cin>>brand;
    cout<<"Color: ";
    cin>>color;
    cout<<"Current Fill Level: ";
    cin>>CurrentFillLevel;
    cout<<"Capacity(1-yes/0-No): ";
    cin>>capacity;

    TeaMug mug(brand,color,CurrentFillLevel,capacity);

    int choise;
    do
    {   cout<<"1-Sip\n2-Refill\n3-Display\n4-Exit\nEnter your choise: ";
        cin>>choise;

        switch(choise)
        {
            case 1:
              mug.sip();
              break;

            case 2:
              mug.refill();
              break;

            case 3:
              mug.DisplayStatus();
              break;

            case 4:
              cout<<"Thanks\n";
              break;

            default:
             cout<<"Invalid choise\n";
        }

    }while(choise != 4);
}
