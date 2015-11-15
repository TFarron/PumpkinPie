#include "Users.h"
#include "HashEntry.h"
#include "HashMap.h"
#include <iostream>
#include <string>

//main for pkin.io, a dating site for web developers 

int main()
{
	bool leave_flag=false; // for leaving main menu
	int choice;
	HashMap myTable;
	User *James;
	James = new User("jkimmel","imsoawesomewow","jkimmel@att.com","Jimmy Kimmel",'M','M',40);

	myTable.add(*James);

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
	}
	else if (choice==2) //delete data; data needs to be deleted in both the BST and in the hash
	{
		string username;
		cout << "Enter in username you would like to remove beow.\n";
		cin >> username;

		//Hash

		int success = myTable.find(username);
		if (success == 0)
		{
			myTable.remove(username);
			cout << "Data removal from hash complete.\n";
		}
		else
		{
			cout << "Data record not found in hash.\n";
		}

		//Tree

	}			
	else if (choice==3)
	{
		string username;
		cout << "Enter in username below.\n";
		cin >> username;
		cout << endl;
		try
		{
			User myUser = myTable.retrieve(username);
			cout << myUser << endl;
		}

		catch(const logic_error& e)
		{
			cerr << e.what();
		}
		cout << endl;
		system("pause");
	}
	else if (choice==4)		
	{				
		//list data directly from hash 
	}			
	else if (choice==5)
	{
		//pull data, sort, and print; more efficient if done by BST 
	}
	else if (choice==6)
	{
	}
	else if (choice==7)
	{
	}
	else if (choice==8)
	{
	}
	else if (choice==9)
	{
		leave_flag = true;
		//make sure to delete any objects that were dynamically created here
	}
	else if (choice==0)
	{
	}

	}while(leave_flag==false);

	system("Pause");
	return 0;
}