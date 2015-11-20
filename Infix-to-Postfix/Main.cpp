#include "LinkedList.h"
#include "LinkedList.cpp"
#include "HashEntry.h"
#include "HashMap.h"
#include "Node.h"
#include "Node.cpp"
#include "Users.h"
#include <iostream>
#include <string>
#include<fstream>
#include <vector>

//User(string user, string pass, string email, string name, char pref, char new_sex, int new_age)

void readFromFile(string fileName, LinkedList<User>* list, HashMap* myTable);
//void writeToFile(LinkedList<User>* list, HashMap* myTable);
void promptAdminOption(HashMap* myTable);
void writeToFileFromHash(HashMap* myTable);
int main()
{
	HashMap *myTable = new HashMap();
	LinkedList<User>* list = new LinkedList<User>();
	readFromFile("test.csv", list, myTable);

	cout << "Welcome to Command Line Generated Social Networking Site\n";
	promptAdminOption(myTable);
	system("Pause");
	return 0;
}

void promptAdminOption(HashMap* myTable)
{
	
	
	bool leave_flag=false; // for leaving main menu
	int choice;

	do{

	cout << endl << "(1) Add new data" << endl;
	cout << "(2) Delete data" << endl;
	cout << "(3) Find and display one data record using the primary key" << endl;
	cout << "(4) List data in hash table sequence" << endl;
	cout << "(5) List data in key sequence (sorted)" << endl;
	cout << "(6) Print indented tree" << endl;
	cout << "(7) Efficiency" << endl;
	cout << "(8) TBD" << endl;
	cout << "(9) Quit" << endl;
	cout << "(0) Credits" << endl;
	cout << endl << "Enter in desired option below.\n";

	cin >> choice;
	if (choice==1)
	{
		//add new data; data needs to be added in both the BST and in the Hash	

		//Data to be added to hash should be done with new pointers as follows:

		//User *James;
	    //James = new User("jkimmel","imsoawesomewow","jkimmel@att.com","Jimmy Kimmel",'M','M',40);

		//User(string user, string pass, string email, string name, char pref, char new_sex, int new_age)
		string userName, password, email, name;
		char pref, sex;
		int age;
		cout << "User Information: \n";
		cout << "User Name: ";
		cin >> userName;
		cout << "Password: ";
		cin >> password;
		cout << "Email: ";
		cin >> email;
		cout << "Sexual Preference: ";
		cin >> pref;
		cout << "Gender: ";
		cin >> sex;
		cout << "Age: ";
		cin >> age;

		User *newUser;
		newUser = new User(userName,password,email,name,pref,sex,age);

		//cout << *newUser;
		myTable->add(*newUser);
		system("pause");
		system("CLS");

	}
	else if (choice==2) //delete data; data needs to be deleted in both the BST and in the hash
	{
		string username;
		cout << "Enter in username you would like to remove beow.\n";
		cin >> username;

		//Hash

		int success = myTable->find(username);
		if (success == 0)
		{
			myTable->remove(username);
			cout << "Data removal from hash complete.\n";
		}
		else
		{
			cout << "Data record not found in hash.\n";
		}

		//Tree
		system("pause");
		system("CLS");
	}			
	else if (choice==3)
	{
		string username;
		cout << "Enter in username below.\n";
		cin >> username;
		cout << endl;
		try
		{
			User myUser = myTable->retrieve(username);
			cout << myUser << endl;
		}

		catch(const logic_error& e)
		{
			cerr << e.what();
		}
		cout << endl;
		system("pause");
		system("CLS");
	}
	else if (choice==4)		
	{				
		//list data directly from hash
		system("CLS");
		system("pause");
	}			
	else if (choice==5)
	{
		//pull data, sort, and print; more efficient if done by BST 
		system("CLS");
		system("pause");
	}
	else if (choice==6)
	{
		system("CLS");
		system("pause");
	}
	else if (choice==7)
	{
		system("CLS");
		system("pause");
	}
	else if (choice==8)
	{
		system("CLS");
		system("pause");
	}
	else if (choice==9)
	{
		leave_flag = true;
		writeToFileFromHash(myTable);
		system("CLS");
		//make sure to delete any objects that were dynamically created here
	}
	else if (choice==0)
	{
	}

	}while(leave_flag==false);


}

void readFromFile(string fileName, LinkedList<User>* list, HashMap* myTable)
{
	std::vector<int> dataRange;
	//main for pkin.io, a dating site for web developers 
	ifstream myReadFile;
	myReadFile.open(fileName);
	string line;
	int index = 0;
	if (myReadFile.is_open()) 
	{
		while (!myReadFile.eof()) 
		{
			while(getline(myReadFile, line))
			{
				while(index != -1)
				{
					dataRange.push_back(index);
					index = line.find_first_of(",", index+1);
				}

				index = 0;
				/*
				for (auto i = dataRange.begin(); i != dataRange.end(); ++i)
					std::cout << *i << ' ';
				cout << endl;
				cout << line;
				*/
				
				int ageStartIndex = dataRange[6] + 1;
				
				int age = atoi(line.substr(ageStartIndex, line.size() - (dataRange[6] + 1)).c_str());//line[dataRange[6]+1] - '0'
				User myUser(line.substr(dataRange[0], dataRange[1]), line.substr(dataRange[1] + 1, dataRange[2] - (dataRange[1] + 1)), line.substr(dataRange[2] + 1, dataRange[3] - (dataRange[2] + 1)), line.substr(dataRange[3] + 1, dataRange[4] - (dataRange[3] + 1)), line[dataRange[4] + 1], line[dataRange[5] + 1], age);
				dataRange.clear();
				list->add(myUser);
				myTable->add(myUser);
			}
		}
	}
	myReadFile.close();
}


void writeToFileFromHash(HashMap* myTable)
{
	ofstream MyExcelFile;
	MyExcelFile.open("hashedData.csv");
	LinkedHashEntry **table = myTable->getTable();
	string dataStr = "";
	for (int i=0; i<TABLE_SIZE; i++)
	{
		if (table[i] != NULL)
		{
			LinkedHashEntry *entry = table[i];
			while(entry != NULL)
			{
				User currUser = entry->getValue();
				cout << currUser;
				dataStr += currUser.get_user() + ",";
				dataStr += currUser.get_pass() + ",";
				dataStr += currUser.get_email() + ",";
				dataStr += currUser.get_name() + ",";
				dataStr.push_back(currUser.get_pref());
				dataStr+= ",";
				dataStr.push_back(currUser.get_sex());
				dataStr+= ",";
				dataStr+= std::to_string(currUser.get_age()) + "\n";
				MyExcelFile << dataStr;
				dataStr = "";
				entry = entry->getNext();
			}
		}
	}
}












































































/*
void writeToFile(LinkedList<User>* list, HashMap* myTable)
{
	ofstream MyExcelFile;
	MyExcelFile.open("outfile4.csv");
	string dataStr = "";
	for (int i = 0; i < list->getCurrentSize(); i++)
	{

		dataStr += list->posToNode(i)->getItem().get_user() + ",";
		dataStr+= list->posToNode(i)->getItem().get_pass() + ",";
		dataStr+= list->posToNode(i)->getItem().get_email() + ",";
		dataStr+= list->posToNode(i)->getItem().get_name() + ",";
		dataStr.push_back(list->posToNode(i)->getItem().get_pref());
		dataStr+= ",";
		dataStr.push_back(list->posToNode(i)->getItem().get_sex());
		dataStr+= ",";
		dataStr+= std::to_string(list->posToNode(i)->getItem().get_age()) + "\n";
		MyExcelFile << dataStr;
		cout << dataStr;
		dataStr = "";

	}
	MyExcelFile.close();
}

*/