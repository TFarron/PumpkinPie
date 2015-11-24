#include "LinkedList.h"
#include "LinkedList.cpp"
#include "HashEntry.h"
#include "HashMap.h"
#include "Node.h"
#include "Node.cpp"
#include "Users.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>

//User(string user, string pass, string email, string name, char pref, char new_sex, int new_age)

bool readFromFile(string fileName, LinkedList<User>* list, HashMap* myTable);
bool promptAdminOption(HashMap* myTable);
void promptUserOption(HashMap* myTable, User& end_user);
void writeToFileFromHash(HashMap* myTable, string savepath);

int main()
{
	string filepath,pword,login;
	char option;
	bool cont;
	HashMap *myTable = new HashMap();
	LinkedList<User>* list = new LinkedList<User>();

	cout << "Welcome to P-kin.io, the up and coming dating service \nfor programming developers,";
	cout << "where we help you meet that \nspecial someone, before it's too late!\n\n";
	cout << "	      __.....__\n";
	cout << "            .'         ':,\n";
	cout << "           /  __  _  __  \\\n";
	cout << "           | |_) || |_)) ||\n";
	cout << "           | | \\ || |    ||\n";
	cout << "           |             ||   _,\n";
	cout << "           |             ||.-(_{}\n";
	cout << "           |             |/    `\n";
	cout << "           |        ,_ (\;|/)\n";
	cout << "         \\|       {}_)-,||`\n";
	cout << "         \\;/,,;;;;;;;,\\|//,\n";
	cout << "        .;;;;;;;;;;;;;;;;,\n";
	cout << "       \,;;;;;;;;;;;;;;;;,//\n";
	cout << "      \\;;;;;;;;;;;;;;;;,//\n";
	cout << endl;
	system("pause"); system("cls");
	cout << "To start, please enter in the filepath of the database to read from.\n";
	cout << "By default, the file is stored in the same directory as this program,\n";
	cout << "and should be titled 'Input'.csv. If you're using a different csv file,\n";
	cout << "specify the name and or filepath. A listing of your current working\n";
	cout << "directory has been provided for your convenience.\n\n";
	system("pause");
	system("cls");
	cout << endl;
	system("dir /w /on");

	cout << "\nFilepath: ";
	cin >> filepath;

	bool success = readFromFile(filepath, list, myTable);

	if(success==false)
	{
		system("cls");
		cout << "Error: File not found.\nExiting...\n\n";
		system("pause");
		goto END;
	}

MENU:

	system("cls");
	cout << "Welcome to P-kin.io\n\n";
	cout << "Login: ";
	cin >> login;
	cout << "\nPassword: ";
	cin >> pword;

	try
	{
		User Admin = myTable->retrieve("admin");
		User end_user = myTable->retrieve(login);

		if(Admin.get_pass()==pword&&Admin.get_user()==login)
		{
			cont = promptAdminOption(myTable);
			system("pause");
			if(cont==true)
				goto MENU;
			else
			{
				delete myTable;
				delete list;
			}
		}

		else if(end_user.get_pass()==pword&&end_user.get_user()==login)
		{
			promptUserOption(myTable, end_user);
			system("pause");
			goto MENU;
		}

		else
		{
			cout << "\nPassword incorrect. Try again?\n('Y' for yes; any other key to exit).\n";
			cin >> option;
			if (option=='Y'||option=='y')
				goto MENU;
			else
				system("pause");
		}
	}

	catch(const logic_error& e)
	{
		cout << "\nError: No account by that name exists in the database.\n";
		cout << "Verify that user exists, first. This error could also occur\n";
		cout << "if there are no 'admin' accounts loaded into the database.\n";
		cout << "Further verify that there is at least one 'admin' account \n";
		cout << "loaded into the database. Now exiting...\n\n";
		system("pause");
	}
END:
	return 0;
}

bool promptAdminOption(HashMap* myTable)
{
	
	
	bool leave_flag=false; // for leaving main menu
	int choice;

	do{
	system("cls");
	cout << "*********** Logged in as user: admin ************* " << endl << endl;
	cout << "(1) Add new data" << endl;
	cout << "(2) Delete data" << endl;
	cout << "(3) Find and display one data record using the primary key" << endl;
	cout << "(4) List data in hash table sequence" << endl;
	cout << "(5) List data in key sequence (sorted)" << endl;
	cout << "(6) Print indented tree" << endl;
	cout << "(7) Efficiency" << endl;
	cout << "(8) Logout" << endl;
	cout << "(9) Quit, and save data to file" << endl;
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
		system("cls");
		cout << "Enter in user information below. \n\n";
		cout << "User Name: ";
		cin >> userName;
		cout << "Real Name: ";
		cin.ignore();
		getline(cin,name);
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
		delete newUser;
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
		myTable->list();
		system("CLS");
		system("pause");
	}			
	else if (choice==5)
	{
		//pull data, sort, and print
		system("CLS");
		myTable->sorted_list();
		system("CLS");
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
		leave_flag = true;
		return true;
	}
	else if (choice==9)
	{
		string savepath;
		leave_flag = true;
		system("cls");
		cout << "Enter below the filepath of the csv that you would like to save changes\n";
		cout << "to the database to. A listing of your current working directory has been\n";
		cout << "provided for your convenience.\n\n";
		system("pause");
		system("cls");
		cout << endl;
		system("dir /w /on");

		cout << "\nFilepath: ";
		cin >> savepath;
		writeToFileFromHash(myTable,savepath);

		system("CLS");
		return false;
		//make sure to delete any objects that were dynamically created here
	}
	else if (choice==0)
	{
		system("cls");
		cout << "P-kin.io, copyright 2015 by PumpkinPie.\n\n";
		cout << "PumpkinPie is: Zachary Prince, Chris Yu,\nCindy Lin, and Dima Konev.\n\n";
		cout << "Main: Zachary Prince & Cindy Lin\n";
		cout << "File I/O: Cindy Lin\n";
		cout << "Hash: Zachary Prince\n";
		cout << "BST: Chris Yu & Dima Konev\n";
		cout << "Presentation: Chris Yu & Zachary Prince\n";
		cout << endl;
		system("pause");
		system("cls");
	}

	}while(leave_flag==false);


}

void promptUserOption(HashMap* myTable, User& end_user)
{
	bool leave_flag=false; // for leaving main menu
	int choice;
	do{
	system("cls");
	cout << "*********** Logged in as user: " << end_user.get_user() << " ************* " << endl << endl;
	cout << "(1) Inbox (Not available yet; still in BETA testing)" << endl;
	cout << "(2) View Profile" << endl;
	cout << "(3) Edit Profile" << endl;
	cout << "(4) Logout" << endl;
	cin >> choice;
	if (choice==1)
	{
		system("cls");
	}
	else if(choice==2)
	{
		system("cls");
		cout << end_user << endl << endl;
		system("pause");
	}
	else if(choice==3)
	{
		string userName, password, email, name;
		char pref, sex;
		int age;
		system("cls");
		cout << "Enter in user information below. \n\n";
		cout << "User Name: ";
		cin >> userName;
		cout << "Real Name: ";
		cin.ignore();
		getline(cin,name);
		cout << "Password: ";
		cin >> password;
		cout << "Email: ";
		cin >> email;
		cout << "Sexual Preference (One character, M, F, O): ";
		cin >> pref;
		cout << "Gender (One character, M, F, O): ";
		cin >> sex;
		cout << "Age: ";
		cin >> age;

		end_user.set_age(age);
		end_user.set_email(email);
		end_user.set_name(name);
		end_user.set_pass(password);
		end_user.set_pref(pref);
		end_user.set_sex(sex);
		end_user.set_user(userName);
	
		User *updatedUser;
		updatedUser = new User(userName,password,email,name,pref,sex,age);
		myTable->add(*updatedUser);
		delete updatedUser;

		system("pause");
	}
	else if(choice==4)
	{
		myTable->remove(end_user.get_user());
		char choice;
		string savepath;
		leave_flag = true;
		system("cls");
		cout << "Would you like to save your changes to file?\n('Y' for yes; any other key to logout)\n";
		cin >> choice;
		if (choice=='Y' || choice=='y')
		{
			cout << "Enter below the filepath of the csv that you would like to save changes\n";
			cout << "to the database to. A listing of your current working directory has been\n";
			cout << "provided for your convenience.\n\n";
			system("pause");
			system("cls");
			cout << endl;
			system("dir /w /on");

			cout << "\nFilepath: ";
			cin >> savepath;
			writeToFileFromHash(myTable,savepath);
		}
	}
	else
	{
		cout << "Invalid option.\n";
		cout << "Returning to main menu...\n";
	}
	}while(leave_flag==false);

}

bool readFromFile(string fileName, LinkedList<User>* list, HashMap* myTable)
{
	std::vector<int> dataRange;
	//main for pkin.io, a dating site for web developers 
	ifstream myReadFile;
	myReadFile.open(fileName);
	if(!myReadFile)
		return false;
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
	return true;
}


void writeToFileFromHash(HashMap* myTable, string savepath)
{
	ofstream MyExcelFile;
	MyExcelFile.open(savepath);
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
				//cout << currUser;
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