#include "iostream"
using namespace std;

class Person{
    string name;
    int age;

public:
    Person(string n, int a) : name(n), age(a){}

    void display()
    { cout<<"Name: "<<name<<endl<<"Age: "<<age<<endl;
    }
};

class Teacher : public Person{
    string subject;

public:
    Teacher(string n, int a, string s) : Person(n,a) , subject(s) {}

    void display()
    {  Person :: display();
       cout<<"Subject: "<<subject<<endl;
    }
};

class Researcher : public Teacher{
    string researchArea;

public:
    Researcher(string n, int a, string s, string r) : Teacher(n,a,s), researchArea(r) {}

    void display()
    {   Teacher :: display();
        cout<<"Research Area: "<<researchArea<<endl;
    }
};

class Professor : public Researcher{
    int publications;

public:
    Professor(string n, int a, string s, string r, int p) :  Researcher(n,a,s,r), publications(p) {}

    void display()
    {   Researcher :: display();
        cout<<"Publications: "<<publications<<endl;
    }
};

int main()
{   Professor p("Ahmed",25,"Maths","Algebra",3);
    p.display();
}
