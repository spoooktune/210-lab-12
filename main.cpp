#include <iostream>
#include <fstream>
#include <string>
#include <array>

using namespace std;

// Have array of student names for a class roster
int main() {
    const int SIZE = 30;
    array <string, SIZE> roster;
    ifstream names;
    names.open("class_roster.txt");
    if (names.good()){
        for (int i = 0; i < SIZE; i++){
            names >> roster[i];
        }
        names.close();
    }
    else {
        cout << "file not found/unable to open" << endl;
    }
    return 0;
}