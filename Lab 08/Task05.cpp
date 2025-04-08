#include "iostream"
using namespace std;

class Fraction{
    float numrator, denomanator, add, subt, multi, divide;

public:
    Fraction(string f) : add(0), subt(0), multi(0), divide(0) 
    {  getData(f);
    }

    Fraction() {}

    void getData(string f)
    {  cout<<"Enter Data for "<<f<<" Fraction....\n";
       cout<<"Enter numrator: ";  cin>>numrator;
       cout<<"Enter denomanator: ";  cin>>denomanator;

       if(denomanator==0)
       {  cout<<"denomanator can't e zero. Re-enter denomanator: ";  cin>>denomanator;
       }
    }

    Fraction operator+(Fraction f)
    {  Fraction temp;
       temp.add = (numrator/denomanator) + (f.numrator/f.denomanator);

       return temp;
    }

    Fraction operator-(Fraction f)
    {  Fraction temp;
       temp.subt = (numrator/denomanator) - (f.numrator/f.denomanator);
 
       return temp;
    }

    Fraction operator*(Fraction f)
    {  Fraction temp;
       temp.multi = (numrator/denomanator) * (f.numrator/f.denomanator);
  
        return temp;
    }

    Fraction operator/(Fraction f)
    {   Fraction temp;
        temp.divide = (numrator/denomanator) / (f.numrator/f.denomanator);
   
        return temp;
    }

    friend ostream& operator<<(ostream& os, Fraction f);
};

ostream& operator<<(ostream& os, Fraction f)
{   os<<"Addition: "<<f.add<<endl;
    os<<"Sutraction: "<<f.subt<<endl;
    os<<"Multiplication: "<<f.multi<<endl;
    os<<"Division: "<<f.divide<<endl;

    return os;
}

int main()
{  Fraction f1("first"), f2("second"), f3("third");

    f3 = f1 + f2;
    f3 = f1 - f2;
    f3 = f1 * f2;
    f3 = f1 / f2;

    cout<<f3;  
}
