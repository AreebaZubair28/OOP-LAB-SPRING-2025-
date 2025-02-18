#include "iostream"
#include "string"
#include <vector>
using namespace std;

class movie{
   string title;
   string director;
   string duration;

public:
    movie(string t, string d, string du) : title(t), director(d), duration(du) {}

    void display() const
    {
        cout<<"Title: "<<title<<endl;
        cout<<"Director: "<<director<<endl;
        cout<<"Duration: "<<duration<<endl;
        cout<<"---------------------"<<endl;
    }
};

class CinemaHall{
   string name;
   vector<movie> m; 

public:
   CinemaHall(string n) : name(n) {}

   void AddMovie(const movie &m1)
   {  m.push_back(m1);
   }

   void display() const
   {  cout<<"Cinema HAll: "<<name<<endl;
      cout<<"Movies being screened: "<<endl;
      cout<<"---------------------"<<endl;
      for (const auto &m1 : m) {
        m1.display();
     }
   }

};

int main()
{  CinemaHall h("Grand Cinema");
   
   movie m1("Inception", "Christopher Nolan", "2;30");
   movie m2("Titanic", "James Cameron", "2:00");
   movie m3("The Matrix", "Wachowskis", "2:43");

   h.AddMovie(m1);
   h.AddMovie(m2);
   h.AddMovie(m3);

   h.display();

}
