#include "iostream"
#include "exception"
using namespace std;

class FileException : public exception {
public:
    virtual const char* what() const noexcept override {
       return "FileException";
    }
};

class FileNotFoundException : public FileException {
public:
    const char* what() const noexcept override {
        return "FileNotFoundException - File not Found!\n";
    }
};

class PermissionDeniedException : public FileException {
public:
    const char* what() const noexcept override {
        return "PermissionDeniedException - Access denied!\n";
    }
};

void read(const string& fileName) {
    if(fileName == "missing.txt") {
        throw FileNotFoundException();
    }
    else if(fileName == "secret.txt") {
        throw PermissionDeniedException();
    }
    else {
        cout << "Reading '" << fileName << "' successful.\n";
    }
}

int main() {
    string filesName[3] = {"data.txt", "secret.txt", "missing.txt"};

    for(int i=0; i<3; i++) {
        try {
            read(filesName[i]);
        }
        catch(FileNotFoundException& e) {
            cout << "Reading '" << filesName[i] << "': " << e.what();
        }
        catch(PermissionDeniedException& e) {
            cout << "Reading '" << filesName[i] << "': " << e.what();
        }
        catch(FileException& e) {
            cout << "Reading '" << filesName[i] << "': Unkown error - " << e.what();
        }
    } 
}
