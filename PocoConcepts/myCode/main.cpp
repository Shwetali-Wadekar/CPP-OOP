// Standard (system) header files
#include <iostream>
#include <cstdlib>
// Add more standard header files as required
// #include <string>
#include<Poco/JSON/Object.h>
#include<Poco/JSON/Array.h>
#include<Poco/JSON/Stringifier.h>

#include<Poco/JSON/Parser.h>
#include<Poco/Dynamic/Var.h>

#include<sstream>
#include<fstream>
#include<vector>
#include<map>
#include<list>
#include<algorithm>
using namespace std;

// Add your project's header files here
// #include "CFraction.h"

// Main program
void jsonWrite(ostream &out) {



}


int main ()
{
	// TODO: Add your program code here
	cout << "PocoConcepts started." << endl << endl;
	//
	//		Poco::JSON::Object::Ptr bhavinPtr=new Poco::JSON::Object;
	//		bhavinPtr->set("name","bhavin");
	//		bhavinPtr->set("age",26);
	//		bhavinPtr->set("height",182);
	//
	//		ofstream fb2("dataSimple.json");
	//		Poco::JSON::Stringifier::stringify(bhavinPtr,fb2,2);
	//
	//		Poco::JSON::Object::Ptr rutvikptr=new Poco::JSON::Object;
	//		rutvikptr->set("name","rutvik");
	//		rutvikptr->set("age",24);
	//		rutvikptr->set("height",170);
	//
	//		Poco::JSON::Object::Ptr mainptr=new Poco::JSON::Object;
	//
	//		Poco::JSON::Array::Ptr array=new Poco::JSON::Array;
	//		array->add(bhavinPtr);
	//		array->add(rutvikptr);
	//
	//		mainptr->set("students",array);
	//
	//		ofstream fb("data.json");
	//		Poco::JSON::Stringifier::stringify(mainptr,fb,2);
	//
	//
	//		ifstream readbuffer("dataSimple.json");
	//		ostringstream oss;
	//		oss<<readbuffer.rdbuf();
	//		readbuffer.close();
	//
	//		Poco::JSON::Parser parser;
	//		Poco::Dynamic::Var result=parser.parse(oss.str());
	//		Poco::JSON::Object::Ptr readptr=result.extract<Poco::JSON::Object::Ptr>();
	//
	//		if(readptr->has("name")) {
	//			cout<<readptr->getValue<string>("name");
	//		}
	//
	//
	//
	//	ifstream readbuffer("data.json");
	//	ostringstream oss;
	//	oss<<readbuffer.rdbuf();
	//	readbuffer.close();
	//
	//	Poco::JSON::Parser parser;
	//	Poco::Dynamic::Var result=parser.parse(oss.str());
	//	Poco::JSON::Object::Ptr readptr=result.extract<Poco::JSON::Object::Ptr>();
	//
	//	if(readptr->has("students")) {
	//		auto arrays=readptr->getArray("students");
	//		for(size_t i=0;i<arrays->size() ; i++) {
	//
	//			cout<<arrays->getObject(i)->getValue<string>("name")<<endl;
	//		}
	//	}
	//
	//	if(readptr->has("name")) {
	//		cout<<readptr->getValue<string>("name");
	//	}

	//map<int,string> maps{{1,"bhavin"},{2,"rutvik"}};
	list<int> lists={1,2,3,4,5,10,8,5};

	lists.sort();


	list<int> lists2={10,20,40,50,80,5,30,4};

	lists2.sort();

	lists.merge(lists2);
	lists.unique();
	for(auto i: lists) {
		cout<<i<<" ";
	}

	vector<int> vec={1,2,1,5,5,5,1,4,10,12,13,15,15,16,17,3,4,5,10,8,5,1};
	sort(vec.begin(),vec.end());
	unique(vec.begin(),(vec.end()));
	cout<<endl;
//	for(auto i: vec) {
//
//		cout<<i<<" ";
//	}
	for(auto i=vec.begin() ; i != next(max_element(vec.begin(),vec.end())) ; ++i) {
		cout<<*i<<" ";

	}

	//cout<<*max_element(vec.begin(),vec.end());
	return 0;
}
