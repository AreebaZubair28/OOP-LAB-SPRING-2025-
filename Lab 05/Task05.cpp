#include "iostream"
#include "string"
using namespace std;

class TourGuide{
   string name;
   int YearOfExperience;
   string specialization;

public:
  TourGuide (string n, int y, string s) : name(n), YearOfExperience(y), specialization(s) {}

  void display()
  {
    cout<<"Tour Guide: "<<name;
    cout<<"  |  Year Of Experience: "<<YearOfExperience;
    cout<<"  |  Specialization: "<<specialization<<endl;
  }
};

class TravelAgency{
    string name;
    TourGuide *t[10];
    int count = 0;

public:
   TravelAgency(string n) : name(n) {}

   void Assign(TourGuide *tg)
   {
      t[count++] = tg;
   }

   void display()
   {
    cout<<"Travel Agency: "<<name<<endl;
    cout<<"Assigned Tour Guide: "<<endl;
    for(int i=0; i<count; i++)
    {  t[i]->display();
    }
   }
};

int main()
{
    TourGuide t1("Rahim",5,"Historical Tours"), t2("Sami", 5, "Adventure Tours"), t3("Adbul", 8, "Cultural Tours");

    TravelAgency t("Global Explorers");
    t.Assign(&t1);
    t.Assign(&t2);
    t.Assign(&t3);

    t.display();

}
