# include"iostream"
using namespace std;

class Media{
protected:
  string title, publisher;
  int id, stockCoun, returnCount,publicationDate;
  const int totalStock;

public:
  Media(int id, string t, int date, string p) 
  : id(id), title(t), publicationDate(date), publisher(p), totalStock(5), stockCoun(0), returnCount(0) {}

  virtual void DisplatInfo()
  { cout<<"Title: "<<title<<endl;
    cout<<"Id: "<<id<<endl;
    cout<<"Publication Date: "<<publicationDate<<endl;
    cout<<"Publisher: "<<publisher<<endl;
  }

  virtual void SearchMedia(string t)
  { if(title == t)
    { cout<<title<<" is Found\n";
    }else{
      cout<<title<<" is not Found\n";
    }
  }

  virtual void SearchMedia(int i)
  { if(id == i)
    { cout<<"Media with id: "<<id<<" is Found\n";
    }else{
      cout<<"Media with id: "<<id<<" is not Found\n";
    }
  }

  void CheckOut()
  { if(stockCoun<5)
    { cout<<"Checking Out..................\n";
      returnCount++;
    }else{
        cout<<"Media Anavailable\n";
    }
  }

  void ReturnItem()
  { if(returnCount>0)
    { cout<<"Returning Item..................\n";
        returnCount--;
    }else{
        cout<<"Refunding of Item is Impossible\n";
    }
  }
};

class Book : public Media{
    string author;
    int ISBN, numOfPages;

public:
    Book(int id, string t, int date, string p, string a, int isbn, int pages) 
    : Media(id,t,date,p), author(a), ISBN(isbn), numOfPages(pages) {}

    void SearchMedia(string a)
    { if(author == a)
      { cout<<title<<" is Found whose author is "<<a<<endl;
      }else{
        cout<<title<<" is not Found\n";
      }
    }

    virtual void SearchMedia(int isbn)
    { if(ISBN == isbn)
      { cout<<"Book with id: "<<id<<" and ISBN: "<<ISBN<<" is Found\n";
      }else{
        cout<<"Book with id: "<<id<<" and ISBN: "<<isbn<<" is not Found\n";
      }
    }
    void DisplatInfo()
    { cout<<"---------Book Info-------------\n";
      cout<<"Id: "<<id<<endl;
      cout<<"Title: "<<title<<endl;
      cout<<"Author: "<<author<<endl;
      cout<<"ISBN: "<<ISBN<<endl;
      cout<<"Number Of Pages: "<<numOfPages<<endl;
      cout<<"Publication Date: "<<publicationDate<<endl;
      cout<<"Publisher: "<<publisher<<endl;
      cout<<"---------------------------------\n"<<endl;
    }
};

class DVD : public Media{
   string director;
   float ratings;
   int  duration;

public:
   DVD(int id, string t, int date, string p, string direc, int dur, float rate) 
   : Media(id,t,date,p), director(direc), duration(dur), ratings(rate) {}

   void SearchMedia(string direc)
   { if(director == direc)
     { cout<<title<<" with director: "<<director<<" is Found\n";
     }else{
        cout<<title<<" with director: "<<direc<<" is not Found\n";
     }
   }

   void SearchMedia(int dur)
   { if(duration = dur)
     { cout<<title<<" with duration: "<<duration<<" is Found\n";
     }else{
       cout<<title<<" with duration: "<<dur<<" is not Found\n";
     }
   }

   void DisplatInfo()
    { cout<<"---------DVD Info-------------\n";
      cout<<"Id: "<<id<<endl;
      cout<<"Title: "<<title<<endl;
      cout<<"Director: "<<director<<endl;
      cout<<"Duration: "<<duration<<endl;
      cout<<"Ratings: "<<ratings<<endl;
      cout<<"Relasing Date: "<<publicationDate<<endl;
      cout<<"Production: "<<publisher<<endl;
      cout<<"---------------------------------\n"<<endl;
    }
};

class CD : public Media{
    string artist, genre;
    int numOfTracks;

public:
    CD(int id, string t, int date, string p, string a, string g, int tracks) 
    : Media(id,t,date,p), artist(a), genre(g), numOfTracks(tracks) {}

    void SearchMedia(string a)
   { if(artist == a)
     { cout<<title<<" whose artist is "<<artist<<" is Found\n";
     }else{
       cout<<title<<" whose artist is "<<a<<" is not Found\n";
     }
   }

   void SearchMedia(int date)
   { if(publicationDate == date)
     { cout<<title<<" released in year: "<<publicationDate<<" is Found\n";
     }else{
       cout<<title<<" released in year: "<<date<<" is not Found\n";
     }
   }

    void DisplatInfo()
    { cout<<"---------Book Info-------------\n";
      cout<<"Id: "<<id<<endl;
      cout<<"Title: "<<title<<endl;
      cout<<"Artist: "<<artist<<endl;
      cout<<"Genre: "<<genre<<endl;
      cout<<"Number Of Tracks: "<<numOfTracks<<endl;
      cout<<"Releasing Date: "<<publicationDate<<endl;
      cout<<"Production: "<<publisher<<endl;
      cout<<"---------------------------------\n"<<endl;
    }
};

int main()
{  Book b(1001,"Rock Paper",2010,"Read Publishers","Anthony",12345654,700);
   DVD dvd(1002,"Movie",2010,"Entertainment","Halk",2,3.5);
   CD cd(1003,"soap",2015,"CD Artist","Tino","Comedy",3);
 
   Media* media = &b;
   media->SearchMedia("Anthony");
   media->SearchMedia(123456);
   media->DisplatInfo();

   media = &dvd;
   media->SearchMedia("Halk");
   media->SearchMedia(2);
   media->DisplatInfo();

   media = &cd;
   media->SearchMedia("Halk");
   media->SearchMedia(2015);
   media->DisplatInfo();

   delete media;
}
