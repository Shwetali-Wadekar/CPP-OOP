// Standard (system) header files
#include <iostream>
#include <cstdlib>
// Add more standard header files as required
 #include <string>
#include"Resistor.h"
#include "ResistorPart.h"
#include"ResistorConnection.h"
#include"SerialResistorConnection.h"
#include "ParallelResistorConnection.h"
#include "ResistorReader.h"

#include<memory>
#include<fstream>
using namespace std;

// Add your project's header files here
// #include "CFraction.h"

// Main program
int main ()
{
    // TODO: Add your program code here
	cout << "Exam-2022SoSe started." << endl << endl;
//	ResistorPart r1("R1",42,0.05);
//
//	cout<<r1<<endl;
//	std::shared_ptr<Resistor> r3(new ResistorPart("R3",1000,0.1));
//	std::shared_ptr<Resistor> r4(new ResistorPart("R4",4700,0.1));
//	SerialResistorConnection r2("R2");
//	r2+=r3;
//	r2+=r4;
//	cout<<r2<<endl;
//
//	ParallelResistorConnection r5("R5");
//	std::shared_ptr<Resistor> r6(new ResistorPart("R6",1000,0.1));
//	std::shared_ptr<Resistor> r7(new ResistorPart("R7",4700,0.1));
//	r5+=r6;
//	r5+=r7;
//	cout<<r5;
//
//	ofstream fb("data.txt");
//	r1.write(fb);
//	r2.write(fb);
//	r5.write(fb);

	ResistorReader reader;
	std::map<std::string, Resistor::ResistorPtr> found;
	ifstream readfb("data.txt");

	reader.read(readfb,found);

	ofstream fb("data2.txt");


	for(auto i:found) {
		cout<<i.first<<endl;
		i.second->write(fb);
	}





	return 0;
}
