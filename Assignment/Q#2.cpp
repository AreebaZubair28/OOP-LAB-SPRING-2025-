#include "iostream"
#include "string"
#include <cstdlib>
using namespace std;

class Robot{
    string name;
    int hits;

public:
   Robot(string n) : name(n), hits(0) {}

   void hitBall(int &ballX, int &ballY, const string &direction)
   {  if(direction == "up")  ballY++;
      else if(direction == "down")  ballY--;
      else if(direction == "left")  ballX--;
      else  ballX++;

      hits++;
      cout << name << " hit the ball towards " << direction << ".\nHits: " << hits << endl;
   }

   int getHits()     { return hits; }
   string getName()  { return name; }
};

class Ball{
    int x, y;

public:
    Ball(int i, int j) : x(i), y(j) {}

    int getx()   { return x; }
    int gety()   { return y; }

    void move(int dx, int dy)
    {   x += dx;
        y += dy;
    }

    pair<int,int> getPosition() { return {x,y}; }
};

class Goal{
   int x;
   int y;

public:
   Goal(int i, int j) : x(i), y(j) {}

   bool isGoalReached(int ballX, int ballY)
   {   if(ballX == x & ballY == y)   
       { return true;
       }else{
        return false;
       }
   }
};

class Team{
    string teamName;

public:
    Robot *robot;

    Team(string tn, string rn) : teamName(tn), robot(new Robot(rn)) {}

    ~Team()   {  delete robot;  }

    string getName()  { return teamName;}

};

class Game{
    Team *teamOne, *teamTwo;
    Ball ball;
    Goal goal;

public:
    Game(Team *t1, Team *t2) : teamOne(t1), teamTwo(t2), ball(0,0), goal(3,3) {} 

    void play(Team *team)
    {   Robot *robot = team->robot;
        cout<<team->getName()<<" starts playing!\n";

        while(!goal.isGoalReached(ball.getx(), ball.gety()))
        {   int i = ball.getx();   int j= ball.gety();
            int dx = (i < 3) ? 1 : 0;  // Move right if not at goalX
            int dy = (j < 3) ? 1 : 0;  // Move up if not at goalY

            if (dx == 1) robot->hitBall(i, j, "right");
            if (dy == 1) robot->hitBall(i, j, "up");

            ball.move(i - ball.getx(), j - ball.gety());

            cout << "Ball Position: (" << ball.getx() << ", " << ball.gety() << ")\n";
        }

        cout << "Goal reached by " << team->getName()<< " in " << robot->getHits() << " hits!\n\n";

    }

    void startGame() {
        play(teamOne);
        ball = Ball(0, 0); // Reset ball for the next team
        play(teamTwo);
        declareWinner();
    }

    void declareWinner() {
        int hitsOne = teamOne->robot->getHits();
        int hitsTwo = teamTwo->robot->getHits();

        cout << "Final Results:\n";
        cout << teamOne->getName()<< " took " << hitsOne << " hits.\n";
        cout << teamTwo->getName() << " took " << hitsTwo << " hits.\n";

        if (hitsOne < hitsTwo)
            cout << teamOne->getName() << " wins!\n";
        else if (hitsTwo < hitsOne)
            cout << teamTwo->getName() << " wins!\n";
        else
            cout << "It's a tie!\n";
    }
};

int main()
{
    Team t1("Team A", "Robot A");
    Team t2("Team B", "Robot B");

    Game footballGame(&t1, &t2);
    footballGame.startGame();

    return 0;
}
