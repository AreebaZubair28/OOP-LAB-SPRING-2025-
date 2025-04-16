#ifndef BOOK
#define BOOK

#include"iostream"
using namespace std;

#define MAX_BOOK 5

class Book{
   string title, author, isbn;

public:
   Book(string t, string a, string isbn);
   Book() {}

   string getTitle() const;
   string getAuthor() const;
   string getISBN() const;
};

class Library{
   Book book[MAX_BOOK];
   int bookCount = 0;

public:
   Library() {}
   void AddBooks(Book b);
   void Remove(string isbn);
   void Search(string isbn, string title);
};

#endif


