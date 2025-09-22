#include <iostream>
#include <algorithm>
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

    cout << "Roster Data\nClass Size: " << roster.size() << endl;
    cout << "Full Roster: ";
    for (string student : roster){
        cout << student << " ";
    }
    cout << endl;

    sort(roster.begin(), roster.end());
    cout << "Alphabetically Sorted Roster: ";
    for (string student : roster){
        cout << student << " ";
    }
    cout << endl;
    return 0;
}