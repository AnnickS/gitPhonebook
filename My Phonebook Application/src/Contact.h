#ifndef CONTACT_H_
#define CONTACT_H_

#include <iostream>

using namespace std;

struct Contact{
	string name;
	string number;
public:
	int c;
	void setName(string);
	void setNumber(string);
	string getName();
	string getNumber();
	friend ostream& operator<<(ostream&, const Contact&);
};


#endif
