#include "iostream"
#include "fstream"
using namespace std;

int main() {
    ofstream file("config.txt");
    if(!file) {
        cerr << "File error!\n";
        exit(1);
    }

    file.write("AAAAA", 5);
    file.write("BBBBB", 5);
    file.write("CCCCC", 5);
    file.close();

    file.open("config.txt" ,ios :: out | ios :: in);
    
    file.seekp(5, ios :: beg);
    file.write("XXXXX", 5);
    file.close();

    ifstream infile("config.txt");
    if(!infile) {
        cerr << "File error!\n";
        exit(1);
    }
    char buffer[20] = {0};
    infile.read(buffer,20);
    cout << "Entire string After changing: " << buffer << endl;
}
