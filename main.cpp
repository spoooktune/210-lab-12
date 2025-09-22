// COMSC-210 | Lab 12 | Amrutha Sriprasana
// Made w/ VSCode

#include <iostream>
#include <algorithm>
#include <fstream>
#include <string>
#include <array>

using namespace std;

// roster size
const int SIZE = 30;

/*
made function to demonstrate find member func, since it is used multiple times,
checks for student postion based on target given + outputs,
says student not found if it is out of bounds
*/
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

// Have array of student names for a class roster, manipulated in main
int main() {
    array <string, SIZE> roster;

    // inputting names from class_roster.txt into array roster
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

    // finds specific students based on position in array
    cout << "Student at position 5: " << roster.at(5) << endl;
    cout << "Student at position 18: " << roster.at(18) << endl;

    return 0;
}