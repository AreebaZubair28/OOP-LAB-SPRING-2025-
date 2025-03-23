#include "iostream"
using namespace std;

struct Position{
    float x, y;
};

class Shape{
    Position p;
    string color;

public:
    Shape(Position position, string c) : p(position), color(c) {}

    string getColor()          { return color; }
    Position getPostion()      { return p;     }

    virtual void draw() 
    { cout<<"Drawing Shape...................\n";
    }

    virtual void calculateArea() 
    { cout<<"Calculating Area................\n";
    }

    virtual void calculatePerimeter() 
    { cout<<"Calculating Perimeter................\n";
    }
};

class Circle : public Shape{
    float radius;
    Position centre;

public:
    Circle(Position position, string c, float r, Position cen) : Shape(position,c), radius(r), centre(cen) {}

    void draw() 
    { cout<<"Drawing Circle...................\n";
      cout<<"Cololr: "<<getColor()<<endl;
      cout<<"Radius: "<<radius<<endl;
      cout<<"Centre Position (x,y) = ("<<centre.x<<","<<centre.y<<")"<<endl;
    }

    void calculateArea() 
    { cout<<"Calculating Area of Circle................\n";
      cout<<"Area: "<<radius*radius<<"pi unit sqr\n";
    }

    void calculatePerimeter() 
    { cout<<"Calculating Perimeter of Circle................\n";
      cout<<"Perimeter: "<<2*radius<<"pi"<<endl;
    }
};

class Rectangle : public Shape{
    float width, height;
    Position top_left_corner;

public:
    Rectangle(Position position, string c, float w, float h,Position top) 
    : Shape(position,c), width(w), height(h), top_left_corner(top) {}

    void draw() 
    { cout<<"Drawing Rectangle..................\n";
      cout<<"Cololr: "<<getColor()<<endl;
      cout<<"Width: "<<width<<endl;
      cout<<"Height: "<<height<<endl;
      cout<<"Top left Centre Position (x,y) = ("<<top_left_corner.x<<","<<top_left_corner.y<<")"<<endl;
    }

    void calculateArea() 
    { cout<<"Calculating Area of Rectangle................\n";
      cout<<"Area: "<<width*height<<" unit sqr\n";
    }

    void calculatePerimeter() 
    { cout<<"Calculating Perimeter of Rectangle................\n";
      cout<<"Perimeter: "<<width+height<<" unit"<<endl;
    }
};

class Triangle : public Shape{
    float base,height, a, b, c;
    Position top;

public:
    Triangle(Position position, string c, float b, float h,float A, float B, float C,Position t) 
    : Shape(position,c), base(b), height(h),a(A), b(B), c(C), top(t) {}

    void draw() 
    { cout<<"Drawing Triangle..................\n";
      cout<<"Cololr: "<<getColor()<<endl;
      cout<<"Base: "<<base<<endl;
      cout<<"Height: "<<height<<endl;
      cout<<"Top Position (x,y) = ("<<top.x<<","<<top.y<<")"<<endl;
    }

    void calculateArea() 
    { cout<<"Calculating Area of Triangle................\n";
      cout<<"Area: "<<(base*height)/2<<" unit sqr\n";
    }

    void calculatePerimeter() 
    { cout<<"Calculating Perimeter of Triangle................\n";
      cout<<"Perimeter: "<<a+b+c<<" unit"<<endl;
    }
};

class Polygon_Square : public Shape{
    float length;

public:
    Polygon_Square(Position position, string c, float l) : Shape(position,c), length(l) {}

    void draw() 
    { cout<<"Drawing Polygon_Square..................\n";
      cout<<"Cololr: "<<getColor()<<endl;
      cout<<"Length: "<<length<<endl;
    }

    void calculateArea() 
    { cout<<"Calculating Area of Polygon_Square................\n";
      cout<<"Area: "<<length*length<<" unit sqr"<<endl;
    }

    void calculatePerimeter() 
    { cout<<"Calculating Perimeter of Polygon_Square................\n";
      cout<<"Perimeter: "<<4*length<<" unit"<<endl;
    }
};

int main()
{  Position p = {2,3};

   Circle c(p,"Red",5.3,{3,4});
   Rectangle r(p,"Blue",2.4,4.0,{1,2});
   Triangle t(p,"Green",2.0,4.5,1,2,3,{2.5});
   Polygon_Square s(p,"Purple",5.00);
   
   Shape* shape = &c;
   cout<<"------------------------------------\n";
   shape->calculateArea();
   shape->calculatePerimeter();
   shape->draw();
   cout<<"------------------------------------\n";

   cout<<"------------------------------------\n";
   shape = &r;
   shape->calculateArea();
   shape->calculatePerimeter();
   shape->draw();
   cout<<"------------------------------------\n";

   cout<<"------------------------------------\n";
   shape = &t;
   shape->calculateArea();
   shape->calculatePerimeter();
   shape->draw();
   cout<<"------------------------------------\n";

   cout<<"------------------------------------\n";
   shape = &s;
   shape->calculateArea();
   shape->calculatePerimeter();
   shape->draw();
   cout<<"------------------------------------\n";
}

