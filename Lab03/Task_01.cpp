#include "iostream"
using namespace std;

class MarkerPens{
      
    public:
    string brand;
    string color;
    int inklevel;
    bool refillability;

    void input()
    {   cout<<"Brand: ";
        cin>>brand;
        cout<<"Color: ";
        cin>>color;
        cout<<"Ink Level: ";
        cin>>inklevel;
        cout<<"Refillabe: ";
        cin>>refillability;
    }

    void write()
    {   if(inklevel <= 0)
        {   cout<<"Marker is out of ink. Refill it first\n";
            return;
        }

        int amount;
        cout<<"How many levels of ink you wanna used: ";
        cin>>amount;

        if(amount > inklevel)
        {   cout<<"Not enough ink to write how long you want, so writing with remaning ink\n";
            inklevel = 0;
            cout<<"Remaining ink: "<<inklevel<<endl;
        }else{
            inklevel-= amount;
        
            cout<<"Writing............\n";
            cout<<"Ink Level decreased by "<<amount<<endl;
            cout<<"Remaining ink: "<<inklevel<<endl;
            if(inklevel <= 0)
            {   cout<<"Marker is out of ink. Refill it first\n";
                return;
            }
            refillability = true;
        }
    }

    void refil()
    {   if(refillability)
        {  inklevel = 100;
   
           cout<<"Refilling Marker............\n";
           cout<<"Ink Level restored to "<<inklevel<<endl;
           refillability = false;
        }else{
           cout<<"Marker Cannot be refilled\n";
        }
    }

    void displayStatus() {
        cout<<"\nMarker Details:\n";
        cout<<"Brand: "<<brand<<endl;
        cout<<"Color: "<<color<<endl;
        cout<<"Ink Level: "<<inklevel<<endl;
        cout<<"Refillable: "<<(refillability ? "Yes" : "No")<<endl;
    }
};

int main()
{   MarkerPens mp;
    
    cout<<"Marker Tracking System"<<endl;
    mp.input();
    int choise;
    
    do
    {   cout<<"1-Write\n2-Refill\n3-Display\n4-Exit\nEnter your choise: ";
        cin>>choise;

        switch(choise)
        {
            case 1:
              mp.write();
              break;

            case 2:
              mp.refil();
              break;

            case 3:
              mp.displayStatus();
              break;

            case 4:
              cout<<"Thanks\n";
              break;

            default:
             cout<<"Invalid choise\n";
        }

    }while(choise != 4);
}
