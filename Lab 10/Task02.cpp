#include "iostream"
#include "fstream"
#include "sstream"
using namespace std;

class Vehicle{
private:
    ifstream file;
    string type, id, name, year, extraData, certification;

public:
    Vehicle(string fileName) {
        file.open(fileName);
        if(!file){
            cerr<<"Error: file can't be opened!\n";
            exit(1);
        }
    }

    void displayData()
    {   cout<<"\nDisplaying Details:\n";
        cout<<"Name: "<<name<<endl;
        cout<<"Id: "<<id<<endl;
        cout<<"Type: "<<type<<endl;
        cout<<"Year: "<<year<<endl;
        cout<<"Extra Data: "<<extraData<<endl;
        cout<<"Certification: "<<certification<<endl;
    }

    void read()
    {   string line;
        if(file.is_open()) {
            while(getline(file,line)) {
                istringstream iss(line);
                getline(iss, type, ',');
                getline(iss, id, ',');
                getline(iss, name, ',');
                getline(iss, year, ',');
                getline(iss, extraData, ',');
                getline(iss, certification, ',');
                displayData();
                
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

int main() {
    Vehicle v("vehicles.txt");
    v.read();
}

