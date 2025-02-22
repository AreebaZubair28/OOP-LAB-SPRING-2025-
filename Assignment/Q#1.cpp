#include "iostream"
#include "string"
using namespace std;

class Skill{
    int skillID;
    string skillName;
    string description;

public:
    Skill(int id, string n, string des)
    {  skillID = id;
       skillName = n;
       description = des;
    }

    void showSkillDetails()
    {   cout<<"Skill Details\n";
        cout<<"Name: "<<skillName<<endl;
        cout<<"Id: "<<skillID<<endl;
        cout<<"Description: "<<description<<endl;
    }
    
    void updateSkillDescription(string newDescription)
    {   description = newDescription;
    }

};

class Sport{
   int sportID;
   string name;
   string description;
   string requiredSkills[50];

public:
   Sport(int id, string n)
   {  sportID = id;
      name = n;
   }

   string getName() { return name; }
    
   void addSkill(Skill s)
   {  for(int i=0; ; i++)
      {  if(requiredSkills[i].empty())
         {  cout<<"Enter Skill: ";  cin>>requiredSkills[i];
            cout<<"Skill added successfully!\n"<<endl;
            break;
         }
      }
   }
    
   void removeSkill(Skill s)
   {  string reqSkill, arr[50];
      int found = 0, count=0;
      cout<<"Enter Skill: ";   cin>>reqSkill;

      for(int i=0; !requiredSkills[i].empty(); i++)
      {  if(reqSkill == requiredSkills[i])
         { found = 1;
         }else{
            arr[count++] = requiredSkills[i];
         }  
      }

      if(found)
      {  for(int i=0; i<count; i++)
         { requiredSkills[i] = arr[i];
         }
         cout<<reqSkill<<" Skill is removed successfully!\n"<<endl;
      }else{
         cout<<reqSkill<<" is not found\n"<<endl;
      }
   }
};

class Mentor;

class Student{
   int studentID;
   string name;
   int age;
   string sportsInterests[50];
   string mentorAssigned;

public:
   Student(string n, int id)
   {  studentID = id;
      name = n;
   }

   string getmentorAssigned()     { return mentorAssigned; }
   string getName()               { return name;           }
   
   void registerForMentorship(Mentor *m);
   void viewMentorDetails(Mentor m);
       
   void updateSportsInterest(Sport s)
   {  int found = 0;
      for(int i=0 ; !sportsInterests[i].empty(); i++)
      {  if(s.getName() == sportsInterests[i])
         { found = 1;
         }
      }
   
      if(found)
      {  cout<<"This Sport already exist in your sportInterested list\n";
      }else{
         for(int i=0; i<50; i++)
         {  if(sportsInterests[i] == "")
            {   sportsInterests[i] = s.getName();
            }
         }
            cout<<s.getName()<<" is updated successfully!\n"<<endl;
      }
   }
};

class Mentor{
   int mentorID;
   string name;
   int maxLearners;

public:
   string sportsExpertise[5];
   string assignedLearners[3];

   Mentor(int id, string n)
   {  mentorID = id;
      name = n;
      string temp[5] = {"tennis", "badminton", "football", "throwball", "basketball"};
      for(int i = 0; i < 5; i++)
      { sportsExpertise[i] = temp[i];
	   }
      maxLearners = 3;
      for (int i = 0; i < 3; i++) 
	   { assignedLearners[i] = ""; 
      }
   }

   string getName()              { return name;     }
   int getId()                   { return mentorID; }

   void assignLearner(Student *s)
   {  int count = 0;
      for(int i=0; i<3; i++)
      {  if(assignedLearners[i] != "")
         {  count++;
         }
      }

      if(count<3)
      {  for(int i=0; i<3; i++)
         {  if(assignedLearners[i].empty())
            {  assignedLearners[i] = s->getName() ;
               s->getmentorAssigned() = name;
               cout<<name<<" assign "<<s->getName()<<endl;
               break;
            }
         }
      }else{
         cout<<"Slots are unavailable. So for now "<<s->getName()<<" can't get under this mentor.\n";
      }
   }

   void removeLearner(Student *s)
   {  int found = 0;
      for(int i=0; i<3; i++)
      {  if(s->getName() == assignedLearners[i])
         { found = 1;
           assignedLearners[i] = "";
           s->getmentorAssigned() = "";
         }
      }

         if(found)
         {  cout<<name<<" removed "<<s->getName()<<" from the learner list\n";
         }else{
           cout<<s->getName()<<" is not found in the mentor's assigned list, so cant be removed\n";
         }
   }

   void viewLearners()
   {  cout<<"Learner's List\n";
      for(int i=0; i<3; i++)
      {  if(assignedLearners[i] == "")
         {  continue;
         }else{
            cout<<assignedLearners[i]<<endl;
         }
      }
   }

   void provideGuidance()
   {  cout << name << " is providing guidance to learners." << endl;
   }
};

void Student::registerForMentorship(Mentor *m)
{  m->assignLearner(this);
}

void Student::viewMentorDetails(Mentor m)
{  cout<<"Mentor Details\n";
   cout<<"Name: "<<m.getName()<<endl;
   cout<<"Id: "<<m.getId()<<endl;
   cout<<"Sports Expertise:\n";
   for(int i=0; i<5; i++)
   {   cout<<i+1<<"- "<<m.sportsExpertise[i]<<endl;
   }
   int count = 0;
   for(int i=0; i<3; i++)
   {  if(!m.assignedLearners[i].empty())
      { count++; 
      }
   }
   cout<<"Assigned Learners: "<<count<<"/"<<"3"<<endl;
}

int main()
{   Student student1 = {"Saad", 1596};
    Student student2 = {"Hamza", 1596};
    Student student3 = {"Rehman", 1596};
    Student student4 = {"Uzair", 1596};

    Mentor m(1020,"Ali");
    
    Sport sport= {2010, "tennis"};
    Skill skill1 = {3040,"Serve Accuracy","Improves precision when serving in Tennis"};
    Skill skill2(202, "Dribbling", "The ability to control and move the basketball while bouncing it.");

    student1.registerForMentorship(&m);
    student2.registerForMentorship(&m);
    m.assignLearner(&student3);
    student4.registerForMentorship(&m);
    m.viewLearners();
    cout<<endl;

    m.removeLearner(&student2);
    m.viewLearners();
    cout<<endl;
    m.assignLearner(&student4);
    m.viewLearners();
    cout<<endl;
    m.assignLearner(&student3);
    m.removeLearner(&student2);
    cout<<endl;

    student1.viewMentorDetails(m);
    cout<<endl;
    m.provideGuidance();
    cout<<endl;
    student2.updateSportsInterest(sport);
    cout<<endl;

    skill1.showSkillDetails();
    skill1.updateSkillDescription("Enhances the accuracy of serves in tennis matches.");
    cout<<"---- Updated Skils ----\n";
    skill1.showSkillDetails();
    cout<<endl;

    sport.addSkill(skill1);
    sport.removeSkill(skill1);
    cout<<endl;
}
