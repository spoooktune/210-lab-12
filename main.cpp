#include <iostream>
#include <algorithm>
#include <fstream>
#include <string>
#include <array>

using namespace std;

const int SIZE = 30;

// made function to demonstrate find member func, since it is used multiple times
void find_student(array<string, SIZE> ro, string target){
    array<string, SIZE>::iterator it;
    it = find(ro.begin(), ro.end(), target);
    if (it != ro.end()){
        cout << target << " found in position " << it - ro.begin() << endl;
    }
    else{
        cout << target << " not found in roster" << endl;
    }
}

// Have array of student names for a class roster
int main() {
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

    // outputs class size, should be 30
    cout << "Roster Data\n---------------\nClass Size: " << roster.size() << endl;

    // outputs unsorted array of names
    cout << "Full Roster: ";
    for (string student : roster){
        cout << student << " ";
    }
    cout << endl;

    // outputs roster in alphabetical order
    sort(roster.begin(), roster.end());
    cout << "Alphabetically Sorted Roster: ";
    for (string student : roster){
        cout << student << " ";
    }
    cout << endl;

    // finds specific students given by name
    find_student(roster, "Ray");
    find_student(roster, "Chase");

    return 0;
}