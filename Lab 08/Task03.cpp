#include "iostream"
using namespace std;

class Teacher;

class Student{
  string name;
  float grade[3];

public:
  Student(string n, float g[3]) : name(n)
  {  for(int i=0; i<3; i++)
    {   grade[i] = g[i];
    }
  }

  friend class Teacher;
  friend void calculateAverageGrade(Student);
};

void calculateAverageGrade(Student s)
{   float avg = 0;
    for(int i=0; i<3; i++)
    {   avg +=s.grade[i];
    }

    cout<<"Average Grades: "<<avg/3<<endl;
}

class Teacher{
public:
  void updateGrade(Student& s)
  {  for(int i=0; i<3; i++)
     {  cout<<"Enter the updated marks "<<i+1<<": ";   cin>>s.grade[i];
     }
  }

  void viewGrade(Student s)
  {  for(int i=0; i<3; i++)
     {  cout<<"Marks "<<i+1<<": "<<s.grade[i]<<endl;
     }
  }
};

int main()
{  float g[3] ={90,85.5,89};
   Student s("Areeba",g);

   Teacher t;
   cout<<"Before updating...........\n";
   t.viewGrade(s);
   calculateAverageGrade(s);

   t.updateGrade(s);
   cout<<"Grades after updating...........\n";
   t.viewGrade(s);
   calculateAverageGrade(s);
}
