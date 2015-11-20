#include "Users.h"
#include <cstddef>
#include <iostream>

using namespace std;

User :: User()
{
};

User :: User(string user, string pass, string email, string name, char pref, char new_sex, int new_age)
{
	//this->test.content  = user;
	n++;
	username = user;
	password = pass;
	email_addr = email;
	real_name = name;
	preference = pref;
	sex = new_sex;
	age = new_age;
	minor = (age < 18 ? true:false);
};
/*
ostream& operator<< (ostream &out, const User &user)
{
	string tab = "\t";
	cout << user.username << "\t" << user.password << "\t" << user.real_name << "\t" << user.preference << "\t" << user.sex << "\t" << user.age << "\t" << user.minor << "****"<< endl;
	//cout << user.username << "**" << user.password << "**" << user.real_name << "**" << user.preference << "**" << user.sex << "**" << user.age << "**" << user.minor << "****"<< endl;

	return out;
};
*/
ostream& operator<< (ostream &out, const User &user)
{

/*private:
	string password,email_addr,real_name;
	char preference,sex;
	//'M' for male, 'F' for female, 'O' for other
	int age;
	bool minor;
	//Used for tracking whether users are a minor or not
public:

	static int n; //counter for the amount of users in server 

	friend ostream& operator<< (ostream &out, const User &user);//redefining stream operator 

	string username;

*/
	out << "Username: " << user.username << endl;
	out << "Password: " << user.password << endl;
	out << "Email Address: " << user.email_addr << endl;
	out << "Full Name: " << user.real_name << endl;
	out << "Preference: " << user.preference << endl;
	out << "Sex: " << user.sex << endl;
	out << "Age: " << user.age << endl;

	//out << "| " << setw(12) << user.password << " | " << setw(11) << user.email_addr << " | " << setw(13) << user.age << " | " << setw(12) << user.real_name << " |";
    return out;
};