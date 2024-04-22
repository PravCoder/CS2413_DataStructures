#include <iostream>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <unordered_map>
#include <iomanip> // for setw
using namespace std;

void readNamesFile(vector<string>& namesArr, string namesFile) {
    ifstream inFile(namesFile); 
    if (!inFile.is_open()) {
        cerr << "Error: Unable to open names file." << endl;
        return;
    }

    string name;  // read in file and add name to end of names list
    while (getline(inFile, name)) {
        cout << name;
        namesArr.push_back(name);
    }

    inFile.close();
}

void readAssignmentFile(unordered_map<string, int>& aMap, string assignmentFile) {
    ifstream inFile(assignmentFile);
    if (!inFile.is_open()) {
        cerr << "Error: Unable to open assignment file." << endl;
        return;
    }

    string line;  // read in assignment file and get name of assignemtn and add it to hashmap and update its count because we came across that students assignment. 
    while (getline(inFile, line)) {
        // Extract student name and assignment number from each line
        size_t pos = line.find('_');
        if (pos != string::npos) {
            string studentName = line.substr(0, pos);
            // Increment the assignment tally for the student
            aMap[studentName]++;
        }
    }

    // Close the file
    inFile.close();
}

void findMissingAssignments(const vector<string>& namesArr, const unordered_map<string, int>& aMap) {
    cout << left << setw(20) <<"STUDENT" <<"MISSING ASSINGMENTS\n";
    // iterate through pair of hashmap
    for (const auto& pair : aMap) {
        const string& studentName = pair.first;  // Access the key (student name)
        int assignmentCount = pair.second;        // Access the value (assignment count)
        int missing = 0;
        // there is less than 9 assimgents for cvur student then they have missing assingments. 
        if (assignmentCount < 9) {
            missing = 9 - assignmentCount;
        }

        auto it = aMap.find(studentName);
        // if cur student is in map, they have at least 1 assigment submitted
        if (it != aMap.end()) {
            cout << left << setw(20) << studentName << missing << endl;
        // if cur student is in not in map they dont have one assingmennt, so they have all 9 assingments missing. 
        } else {
            cout << left << setw(20) << studentName << 9 << endl;
        }

    }
}


int main() {
    vector<string> namesArr;
    unordered_map<string, int> aMap;
    string namesFile = "Names.txt";
    string assignmentFile = "Assignments.txt";

    // cout << "Enter names file: ";
    // cin >> namesFile;
    readNamesFile(namesArr, namesFile);

    // cout << "Enter assignment file: ";
    // cin >> assignmentFile;
    readAssignmentFile(aMap, assignmentFile);

    findMissingAssignments(namesArr, aMap);


    return 0;
}
