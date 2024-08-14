// Standard (system) header files
#include <iostream>
#include <cstdlib>
#include <map>
#include <set>
#include <vector>
#include <list>
// Add more standard header files as required
// #include <string>

using namespace std;

// Add your project's header files here
// #include "CFraction.h"

int main () {
    // TODO: Insert your Name and student ID number here
    cout << "Student Name: BHAVINKUMAR PRAJAPATI, Matrikel-Nb: 1119282" << endl << endl;
    
    extern void allTests();
    allTests();

    cout<<endl;

    set<int> bhavin={1,2,3,4,5};

    bhavin.erase(bhavin.begin());
    //;

    return 0;
}
