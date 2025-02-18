#include "iostream"
#include "string"
using namespace std;

class Professor{
public:
  string name;
  string department;

  Professor (string n, string d) : name(n) , department(d) {}

  void display()
  {
    cout<<"Professor Name: "<<name<<endl;
    cout<<"Department: "<<department<<endl;
  }
};

class University{
public:
  string name;
  Professor *p[10];
  int count = 0;

  University (string n) : name(n) {}

  void AddProfessor(Professor *p1)
  {   p[count++] = p1;
  }

  void Display()
  { cout<<"Uni Name: "<<name<<endl;
    for(int i=0; i<count; i++)
    {  p[i]->display();
    }
  }
};

int main()
{ Professor p1("Areeba","CS"), p2("Aqsa","S.E"), p3("Zubair", "DS");

  University u("Fast");

  u.AddProfessor(&p1);
  u.AddProfessor(&p2);
  u.AddProfessor(&p3);

  u.Display();
}
