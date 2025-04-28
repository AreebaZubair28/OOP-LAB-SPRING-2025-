#include "iostream"
#include "fstream"
using namespace std;

int main() {
    ifstream inFile;
    inFile.open("large_log.txt", ios::binary);
    if(!inFile) {
        cerr << "File can't be opened!\n";
        exit(1);
    }

    char buffer[100] = {0};
    inFile.seekg(ios :: beg);
    inFile.read(buffer, 10);
    streampos pos = inFile.tellg();
    cout << "\nPosition after first read is: " << pos << endl;

    inFile.read(buffer, 10);
    pos = inFile.tellg();
    cout << "\nPosition after second read is: " << pos << endl;

    inFile.read(buffer, 10);
    pos = inFile.tellg();
    cout << "\nPosition after third read is: " << pos << endl << endl;

    inFile.close();
}
