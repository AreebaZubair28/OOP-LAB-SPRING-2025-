#include "iostream"
#include "string"
using namespace std;

class Vehicle{
  string model;
  float perDayPrice;
  string eligibility;

public:
  Vehicle(string m, float p, string e) : model(m), perDayPrice(p), eligibility(e) {}

  string getModel()  { return model; }
  string getEligibility()  { return eligibility; }
  float getperDayPrice()  { return perDayPrice; }

  void Display()
  { cout<<"Model: "<<model<<endl;
    cout<<"Rental price per day: "<<perDayPrice<<endl;
    cout<<"Eligibility: "<<eligibility<<endl;
    cout<<"-----------------------------"<<endl;
  }
};

class User{
  int Age;
  string LicenseType; // (e.g., Learner, Intermediate, Full)
  string Contact;
  int userID;
  Vehicle *vehicle[10];
  int count = 0; 

public:
  void AddVehicle(Vehicle *v)
  {  vehicle[count++] = v;
  }

  void Removevehicle(string m, float p, string e)
  { int j = 0;
    for(int i=0; i<count; i++)
    { if(m ==  vehicle[i]->getModel() && e == vehicle[i]->getEligibility() && p == vehicle[i]->getperDayPrice())
      { continue;
      }else{
        vehicle[j++] = vehicle[i];
      }
    }
    count--;
  }
  
  void registration()
  { cout<<"--- Registration ---\n";
    cout<<"User Id: ";
    cin>>userID;
    cout<<"Age: ";
    cin>>Age;
    cout<<"Contact: ";
    cin>>Contact;
    cout<<"License Type (L-Learner, I-Intermediate, F-Full): ";
    cin>>LicenseType;
  }

  void update()
  { cout<<"\n---Update Details---\n";
    cout<<"Age: ";
    cin>>Age;
    cout<<"Contact: ";
    cin>>Contact;
    cout<<"License Type (L-Learner, I-Intermediate, F-Full): ";
    cin>>LicenseType;
  }

  void AvailableVehicles()
  { cout<<"\nList of Available Vehicles\n";
    for(int i=0; i<count; i++)
    {  vehicle[i]->Display();
    }
  }

  void rentVehicle()
  { string model;
    string eligibility;
    float perDayPrice;
    int found = 0;
    cout<<"\nEnter your desired model: ";
    cin.ignore();
    getline(cin,model);

    for(int i=0; i<count; i++)
    { if(model ==  vehicle[i]->getModel())
      { found = 1;
        model ==  vehicle[i]->getModel();
        eligibility = vehicle[i]->getEligibility();
        perDayPrice = vehicle[i]->getperDayPrice();
      }
    }

    if(found)
    { if(LicenseType <= eligibility && Age>=18)
      { cout<<"You can rent "<<model<<" with Per Day Payment of: "<<perDayPrice<<endl;
        Removevehicle(model,perDayPrice,eligibility);
      }else{
        cout<<"Your are not eligible to rent "<<model<<endl;
      }
    }else{
      cout<<model<<" is not found\n";
    }
  }
};

int main()
{ Vehicle v1("Land Cruiser",24000,"F");
  Vehicle v2("Honda Civic",9000,"I");
  Vehicle v3("Suzuki Alto",5500,"L");
    
  User u;
  u.AddVehicle(&v1);  
  u.AddVehicle(&v2);  
  u.AddVehicle(&v3);
  u.registration();
  u.AvailableVehicles();
  u.rentVehicle();
}
