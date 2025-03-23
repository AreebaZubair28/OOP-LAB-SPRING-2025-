# include"iostream"
using namespace std;

class Course;

class Person{
protected:
   int id;
   string name;
   string address;
   string phoneNumber;
   string email;

public:
   Person(int id, string n, string a, string num, string e) :
   id(id), name(n), address(a), phoneNumber(num), email(e) {}

   void UpdateInfo(string a, string num, string e)
   { address = a;
     phoneNumber = num;
     email = e;
   }

   virtual void DisplayInfo()
   {  cout<<"Name: "<<name<<endl;
      cout<<"Id: "<<id<<endl;
      cout<<"Address: "<<address<<endl;
      cout<<"Phone No.: "<<phoneNumber<<endl;
      cout<<"Email: "<<email<<endl;
   }
};

class Professor : public Person{
   string department, coursesTaught[5];
   float salary;
   int courseCount;

public:
   Professor(int id, string n, string a, string num, string e, string depart, float s) 
   : Person(id,n,a,num,e), department(depart), salary(s), courseCount(0) {}

   void Addcourses(string c)
   { if(courseCount<5)
    { coursesTaught[courseCount++] = c;
    }else{
      cout<<"Courses ecxeeded\n";
    }
   }

   void DisplayInfo()
   {  cout<<"---------Professor Info-------------\n";
      cout<<"Name: "<<name<<endl;
      cout<<"Id: "<<id<<endl;
      cout<<"Department: "<<department<<endl;
      cout<<"Taught Courses: "<<endl;
      for(int i=0; i<courseCount; i++)
      { cout<<coursesTaught[i]<<endl;
      }
      cout<<"Salary: "<<salary<<endl<<endl;
   }
};

class Staff : public Person{
   string department, position;
   float salary;

public:
   Staff(int id, string n, string a, string num, string e, string depart, string p, float s) 
   : Person(id,n,a,num,e), department(depart), position(p), salary(s) {}
    
   void DisplayInfo()
   {  cout<<"---------Staff Info-------------\n";
      cout<<"Name: "<<name<<endl;
      cout<<"Id: "<<id<<endl;
      cout<<"Department: "<<department<<endl;
      cout<<"Position: "<<position<<endl;
      cout<<"Salary: "<<salary<<endl<<endl;
   }
};

class Student : public Person{
    float GPA;
    int enrollmentYear;
    Course* coursesEnrolled[5];
    int courseCount;

public:
  Student(int id, string n, string a, string num, string e,float gpa, int year) 
  : Person(id,n,a,num,e), GPA(gpa), enrollmentYear(year), courseCount(0) {}

  float getGPA()     { return GPA; }
  string getName()   { return name; }

  void Addcourses(Course* c);
  void DisplayInfo();
};

class Course{
    string name, id, instructor,schdule;
    int credits, studentCount = 0;
    Student* student[5];
    float marks[5];
  
public:
    Course(string id, string n, int cre, string ins, string sch) 
    : id(id), name(n), credits(cre), instructor(ins), schdule(sch) {}
  
    string getName()  { return name;}
  
    void RegisterStudent(Student* s)
    { if(studentCount<5)
      {   student[studentCount] = s; 
          float mark =  s->getGPA();
          marks[studentCount++] = mark;
      }else{
          cout<<"Course is full\n";
      }
    }
  
    string calculateGrades(float marks)
    { for(int i=0; i<studentCount; i++)
      {   if      (marks > 4.00)                  return "A+";
          else if (marks <= 4.00 && marks >3.6)   return "A";
          else if (marks <=3.6  && marks >3.2)    return "B";
          else if (marks <=3.2  && marks >2.8)    return "C";
          else if (marks <=2.8  && marks >=2.4)   return "D";
          else                                    return "F";
      }
    }
  
    void display()
    { cout<<"---------Course Info-------------\n";
      cout<<"Name: "<<name<<endl;
      cout<<"Id: "<<id<<endl;
      cout<<"Credits: "<<credits<<endl;
      cout<<"Instructor: "<<instructor<<endl;
      cout<<"Schedule: "<<schdule<<endl;
      cout<<"Student Enrolled: "<<endl;
      for(int i=0; i<studentCount; i++)
      { cout<<student[i]->getName()<<endl;
        cout<<"Grades: "<<calculateGrades(marks[i])<<endl;
      }
      cout<<endl;
    }
};

void Student :: Addcourses(Course* c)
{ if(courseCount<5)
  { coursesEnrolled[courseCount] = c;
    coursesEnrolled[courseCount++]->RegisterStudent(this);
  }else{
    cout<<"Courses ecxeeded\n";
  }
}

void Student :: DisplayInfo()
{   cout<<"---------Student Info-------------\n";
    cout<<"Name: "<<name<<endl;
    cout<<"Id: "<<id<<endl;
    cout<<"Enrolled Courses: "<<endl;
    for(int i=0; i<courseCount; i++)
    { cout<<coursesEnrolled[i]->getName()<<endl; }
    cout<<"GPA: "<<GPA<<endl;
    cout<<"Enrollment Year: "<<enrollmentYear<<endl<<endl;
}

int main()
{   
    Course c1("NS1002","Applied Physics",16,"Sir Rahim","Tues, Thurs, Fri"), c2("CS2003","OOP",16,"Misss Atiya","Tues, Thurs, Fri"), c3("MS3020","MVC",16,"Miss Uzma","Mon, Thurs, Fri");

    Student s1(596,"Areeba","Jamshed Road", "0314-2554112", "Areeba@gmail.com",3.21,2024);
    Student s2(599,"Aaqs","Jamshed Road", "0314-2554112", "Aqsa@gmail.com",2.54,2024);
    Student s3(594,"Fatima","Jamshed Road", "0314-2554112", "Fatima@gmail.com",3.51,2022);
    s1.Addcourses(&c1); s1.Addcourses(&c2); s1.Addcourses(&c3);
    s2.Addcourses(&c1); s2.Addcourses(&c2); s2.Addcourses(&c3);
    s3.Addcourses(&c1); s3.Addcourses(&c2); s3.Addcourses(&c3);
    Person* person = &s1;
    person->DisplayInfo();

    Professor p(5005,"Sir Rahim","XYZ","0321-1234567","Rahim@gmail.com","Science",50000);
    p.Addcourses("Applied Physics"); p.Addcourses("DLD"); p.Addcourses("Assembly");
    person = &p;
    person->DisplayInfo();

    Staff s(1002,"Shakil","XYZ","0321-1234567","Shakil.com","humanities","Sweeper",10000);
    person = &s;
    person->DisplayInfo();

    c1.display();

    delete person;
}
