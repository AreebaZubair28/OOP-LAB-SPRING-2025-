#include "iostream"
using namespace std;

class Librarian;
class Book{
    string title;
    double price;

public:
   
   Book(string t, double p) : title(t), price(p) {}

   friend class Librarian;
};

class Librarian{

public:
   void display(Book b)   // or  void display(Book& b)
   {
      cout<<"Title: "<<b.title<<endl;
      cout<<"Price: "<<b.price<<endl;
   }

   void discount(Book b, double amount)  // or void discount(Book& b, double amount)
   {  b.price -=amount;
      cout<<"Discounted Price: "<<b.price<<endl;
   }
};

int main()
{  Book b("Rock Paper",1200);
   Librarian l;

   l.display(b);
   l.discount(b,200);
}
