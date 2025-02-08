#include "iostream"
#include "string"
#include "cstring"
using namespace std;

class Planner{

public:
   string arr[12][30] = {};

   void Add(int month, int day, string task)
   {   arr[month-1][day-1] = task;
       cout<<"Task added successfully!\n";

   }

   void Remove(int month, int day,string str)
   {   if(arr[month-1][day-1] == str)
       {  cout<<"Task can't be removed since no task was assigned\n";
       }else{
          arr[month-1][day-1] = str;
          cout<<"Task removed successfully!\n";
       }
      
   }

   void Update()
   {    int m, d;
        string task;
        cout<<"Enter month: ";
        cin>>m;
        cout<<"Enter day: ";
        cin>>d;
        cout<<"Enter Task: ";
        cin>>task;
 
        arr[m-1][d-1] = task;
        cout<<"Task updated successfully!\n";
   }

   void Display()
   {   cout<<"------------------------\n";
       for(int i=0; i<12; i++)
       {   cout<<"Month: "<<i+1<<endl;
           for(int j=0; j<30; j++)
           {  if(arr[i][j] == "no")
              { continue;
              }else{
                 cout<<"Day "<<j+1<<": "<<arr[i][j]<<endl;
              }
           }
       }
   }

   void input(string str)
   {   for(int i=0; i<12; i++)
       {   for(int j=0; j<30; j++)
           {  arr[i][j] = str;
           }
       }
   }
};

int main()
{   Planner p;
    int num = 0;
    int m, d;
    string task;
    string str = "no";

    int choise;
    p.input(str);
    
    do
    {   cout<<"1-Add\n2-Remove\n3-Update\n4-Display\n5-Exit\nEnter your choise: ";
        cin>>choise;

        switch(choise)
        {
            case 1:
              cout<<"Enter month: ";
              cin>>m;
              cout<<"Enter day: ";
              cin>>d;
              cout<<"Enter Task: ";
              cin>>task;
              p.Add(m,d,task);
              num++;
              break;

            case 2:
              if(num == 0)
              { cout<<"Task can't be removed since no task exits\n";
              }else{
                cout<<"Enter month: ";
                cin>>m;
                cout<<"Enter day: ";
                cin>>d;
                p.Remove(m,d,str);
                num--;
              }
              break;
            
            case 3:
              p.Update();
              break;

            case 4:
              p.Display();
              break;

            case 5:
              cout<<"Thanks\n";
              break;

            default:
             cout<<"Invalid choise\n";
        }

    }while(choise != 5);
}
