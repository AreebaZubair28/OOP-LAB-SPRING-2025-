#include "iostream"
#include "string"
#include "cstring"
using namespace std;

class Activity{

public:
   virtual void calculateCaloriesBurned() = 0;

};

class Running : public Activity{
   double distance, time;

public:
   Running(double d, double t) : distance(d), time(t) {}

   void calculateCaloriesBurned()
   { double weight;
     cout<<"Enter weight: ";  cin>>weight;

     double t = time/60;

     double calories = (distance/t) * weight * t;
     cout<<"Burned Calories: "<<calories<<endl;
   }
};

class cycling : public Activity{
   double speed, time;

public:
   cycling(double d, double t) : speed(d), time(t) {}

   void calculateCaloriesBurned()
   { double weight;
     cout<<"Enter weight: ";  cin>>weight;

     double calories = speed * weight * time;
     cout<<"Burned Calories: "<<calories<<endl;
   }
};

int main()
{
    Running r(8,20);
    r.calculateCaloriesBurned();

    cycling c(30,2.5);
    c.calculateCaloriesBurned();

}
