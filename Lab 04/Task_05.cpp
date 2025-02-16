#include "iostream"
using namespace std;

class Book{
    int Id;
    string title;
    float price;
    int stock ;
    static int bookCounter;
 
 public:
    Book(string t, float p, int s) : title(t) , price(p), stock(s) , Id(++bookCounter) {}
 
    void Display()
    {   cout<<"------Book "<<Id<<" Details------\n";
        cout<<"Id: "<<Id<<endl;
        cout<<"Name: "<<title<<endl;
        cout<<"Price: "<<price<<endl;
        cout<<"Stock: "<<stock<<endl;
    }

    static int getCounter()
    { return bookCounter;
    }
};

int Book :: bookCounter = 0;

int main()
{  Book b1("C++", 1000, 10);
   Book b2("C", 800, 7);
   Book b3("Java", 2000, 5);

   b1.Display();
   b2.Display();
   b3.Display();

   cout<<"Total Books Created: "<< Book::getCounter();

}
