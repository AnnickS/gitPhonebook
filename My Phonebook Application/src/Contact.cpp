#include "Contact.h"
#include <iostream>

using namespace std;

void Contact::setName(string _name){
	name = _name;
}

void Contact::setNumber(string _number){
	number = _number;
}

string Contact::getName(){
	return name;
}

string Contact::getNumber(){
	return number;
}

ostream& operator<<(ostream& os, const Contact& con)
{
	os << con.name << " " << con.number << endl;
	return os;
}
