#include "iostream"
using namespace std;

class Book{
   string *title = new string;
   float *price = new float;
   int *stock = new int;

public:
   Book(string t, float p)
   {   *title = t;
       *price = p;
       *stock = 30;
   }

   Book(Book& other)
   {  *title = *(other.title);
      *price = *(other.price);
      *stock = *(other.stock);
   }

   void updateBookDetails()
   {   cout<<"Name: ";     cin>>*title;
       cout<<"Price: ";    cin>>*price;
       cout<<"Stock: ";    cin>>*stock;
       if(*stock < 5)
       {  cout<<"Warning! Low Stock\n";
       }
   }

   void Display()
   {   cout<<"------Book Details------\n";
       cout<<"Name: "<<*title<<endl;
       cout<<"Price: "<<*price<<endl;
       cout<<"Stock: "<<*stock<<endl;
   }

   ~Book()
   {  cout<<"Object has destroyed\n"<<endl;
   }
};

int main()
{  Book b1("Rock Paper Scissor", 120);
   cout<<"Bookk 1\n";
   b1.Display();
   cout<<endl;

   Book b2(b1);
   cout<<"Bookk 2\n";
   b2.Display();
   cout<<endl;
   
   cout<<"Updating Book 1----------------\n";
   b1.updateBookDetails();
   cout<<endl;

   cout<<"Bookk 2\n";
   b2.Display();
   cout<<endl;
}
