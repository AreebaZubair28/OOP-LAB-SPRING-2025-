#include "iostream"
#include "fstream"
using namespace std;

class Vehicle{
    ifstream file;

public:
    Vehicle(string fileName) {
        file.open(fileName);
        if(!file){
            cerr<<"Error: file can't be opened!\n";
            exit(1);
        }
    }

    void read()
    {   string line;
        if(file.is_open()) {
            while(getline(file,line)) {
                cout<< line <<endl;
            }
            file.close();
        }else {
            cout <<"File is not opened!\n";
        }
    }
 
    ~Vehicle(){
        if(file.is_open()) {
            file.close();
            cout<<"\nFile has closed!\n";
        }else {
            cout <<"\nFile is already closed!\n";
        } 
    }
};

int main()
{
    Vehicle v("vehicles.txt");
    v.read();
}
