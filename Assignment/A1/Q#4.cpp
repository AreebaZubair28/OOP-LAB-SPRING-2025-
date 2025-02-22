#include "iostream"
#include "string"
using namespace std;

class Bus{
  int route;
  const float Fees = 39000;
  string stops[3];
  int IdOfAssignedStudent[10];
  int count = 0;

public:
  Bus(int r) : route(r) {}

  string getstops(int i)  { return stops[i]; }
  float getFees()         { return Fees;     }
  int getRoute()          { return route;    }

  void AddStops(string s[3])
  { for(int i=0; i<3; i++)
    {   stops[i] = s[i];
    }
  }

  void AddStudent(int id)
  {  IdOfAssignedStudent[count++] = id;
  }

  void Display()
  { cout<<"-----------------\n";
    cout<<"Route: "<<route<<endl;
    cout<<"Stops: "<<endl;
    for(int i=0; i<3; i++)
    {  cout<<i+1<<"- "<<stops[i]<<endl;
    }
  }

  void AssignedStudent()
  { cout<<"List of Id(s) Student Assigned for Route "<<route<<endl;
    for(int i=0; i<count; i++)
    { cout<<IdOfAssignedStudent[i]<<endl;
    }
  }
};


class Student{
    int studentId;
    int route;
    float TransportFees;
    string stop;
    bool card;
    bool attendance;
    Bus *bus[3];
    int count = 0;
    int flag = 0;

public:
   Student() :  card(false), attendance(false) {}
    
   bool getCard()  { return card; }
   void AddBus(Bus *b)
   {  bus[flag++] = b;
   }
   void AvailableBus()
   {  cout<<"List Of Available Routes: "<<endl;
      for(int i=0; i<3; i++)
      {  bus[i]->Display();
      }
   }

   void Registration()
   {  int routeFound = 0;
      int stopFound = 0;
      cout<<"Id: ";     cin>>studentId;
      cout<<"Stop: ";   cin>>stop;
      cout<<"Route: ";  cin>>route;

      for(int i=0; i<3; i++)
      { if(route == bus[i]->getRoute()) 
        {   routeFound = 1;
            count = i;   
        }
      }

      if(routeFound)
      { for(int i=0; i<3; i++)
        {   if(stop == bus[count]->getstops(i))
            {  stopFound = 1;
            }
        }

        if(stopFound)
        { bus[count]->AddStudent(studentId);
          cout<<"You have registered successfully!\n";
          SemesterTransportPayment();
          TapCard(true);
        }else{
          cout<<"Route "<<route<<" don't pickup student from "<<stop<<"\n\n\n";
        }
      }else{
            cout<<"There is no bus with route "<<route<<"\n\n\n";
      }  
   }

   void SemesterTransportPayment()
   {  TransportFees = bus[count]->getFees();
      card = true;
      cout<<"You have successfully paid your Transport Fees: "<<TransportFees<<endl;
   }

   void TapCard(bool tap)
   {  if(tap)
      { attendance = true;
      }
      cout<<"Your Attendace has been marked!\n\n\n";
   }

   void display()
   { cout<<"Id: "<<studentId<<endl;
     cout<<"Route: "<<route<<endl;
     cout<<"Stop: "<<stop<<endl;
     cout<<"Semester Fees: "<<TransportFees<<endl;
   }
};

int main()
{   string arr1[3] = {"Rabia City", "Sadar", "Abbas Town"};
    string arr2[3] = {"Power House", "UP-More", "Nagan"};
    string arr3[3] = {"Saleem Centre", "2-Min", "4k stop"};
    Bus b1(1),  b2(2), b3(3);
    b1.AddStops(arr1);
    b2.AddStops(arr2);
    b3.AddStops(arr3);

    Student s1, s2, s3;
    
    s1.AddBus(&b1);  s1.AddBus(&b2);  s1.AddBus(&b3);
    s2.AddBus(&b1);  s2.AddBus(&b2);  s2.AddBus(&b3);
    s3.AddBus(&b1);  s3.AddBus(&b2);  s3.AddBus(&b3);

    s1.AvailableBus();
    cout<<"-----------------\n\n";
    cout<<"Registration of Student 1\n";
    s1.Registration();
    cout<<"Registration of Student 2\n";
    s2.Registration();  
    cout<<"Registration of Student 3\n";
    s3.Registration();

    if(s1.getCard())
    {   cout<<"-----------------------------------\n";
        cout<<"Details of Student 1: "<<endl;
        s1.display();
    }
    
    if(s2.getCard())
    {   cout<<"-----------------------------------\n";
        cout<<"Details of Student 2: "<<endl;
        s2.display();
    }

    if(s3.getCard())
    {   cout<<"-----------------------------------\n";
        cout<<"Details of Student 3: "<<endl;
        s3.display();
    }
    
    cout<<"-----------------------------------\n";
}
