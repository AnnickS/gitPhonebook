#include <iostream>
#include <limits>
#include <fstream>
#include "Contact.h"


using namespace std;

Contact addContact(string, string);
int searchContact(string, Contact*, int);
void resizeContacts(Contact*, int, int);

int main() {
	Contact* pList;
	pList = new Contact[200000];
	ifstream inFile;
	inFile.open("phonebook.txt");

	int count = 0;
	string name;
	string nameLast;
	string number;

	while(inFile >> name)
	{
		inFile >> nameLast;
		inFile >> number;
		name += ' ' +nameLast;
		pList[count] = addContact(name, number);
		count++;
	}

	cout<<"***MY PHONEB00K APPLICATION***"<<endl;
	cout<<"Please choose an operation:"<<endl;
	char input;

	while(input != ('Q' || 'q')){
			cout<<"A(Add) | S(Search) | D(Delete) | L(List) | Q(Quit):"<<endl;
			cin.clear();
			cin >> input;
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			if((input == 'A') || (input == 'a')){
				cin.clear();
				string name;
				string number;
				cout << "Enter name: ";
				cin.clear();
				getline(cin, name);
				cout << "Enter number: ";
				cin.clear();
				getline(cin, number);
				Contact adding = addContact(name, number);
				resizeContacts(pList, count+1, count+1);
				pList[count] = adding;
				count++;
			}
			else if((input == 'S') || (input == 's')){
				string name;
				int i;
				cout << "Enter name: ";
				cin.clear();
				getline(cin, name);
				i = searchContact(name, pList, count);
				if(i != -1){
					//cout << "Phone number: " << p[i]->getNumber();
				}
			}
			else if((input == 'D') || (input == 'd')){
				string name;
				int i;
				cout << "Enter name: ";
				cin.clear();
				getline(cin, name);
				i = searchContact(name, pList, count);
				pList[i] = Contact();
				//resizeContacts(Contacts, count, count-1);
				count--;
			}
			else if((input == 'L') || (input == 'l')){
				for(int n = 0; n < count; n++){
					cout << pList[n];
				}
			}
			else if((input == 'Q') || (input == 'q')){
				cin.clear();
				break;
			}
			else{
				cout<<"Not a valid form of input."<<endl;
			}

			cin.clear();
	}

	delete [] pList;

	inFile.close();

	return 0;
}

Contact addContact(string name, string number){
	Contact added;
	added.setName(name);
	added.setNumber(number);
	added.c = 1;

	return added;
}

int searchContact(string name, Contact * Contacts, int count){
	int p = 0;
	bool found;

	for(int i = 0;i < count; i++){
		if(Contacts[i].getName() == name){
			p=i;
			found = 1;
			break;
		}
	}

	if(!found){
		cout << "Could not find contact." << endl;
		return -1;
	}
	else
		return p;

}

void resizeContacts(Contact * Contacts, int current, int size){
	Contact* temp;
	temp = new Contact[size];
	int j = 0;

	for(int i = 0; i < current; i++){
		if(Contacts[i].c == 1){
			temp[j] = Contacts[i];
			j++;
		}
		else continue;
	}

	Contacts = temp;
	delete [] temp;
}
