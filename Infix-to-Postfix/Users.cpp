#include "Users.h"
#include <cstddef>
#include <iomanip>

using namespace std;

int User::n=0;//set counter to 0

User :: User()
{
};

User :: User(string user, string pass, string email, string name, char pref, char new_sex, int new_age)
{
	username = user;
	password = pass;
	email_addr = email;
	real_name = name;
	preference = pref;
	sex = new_sex;
	age = new_age;
	if (age<18)
		minor = true;
	else
		minor = false;
	User::n++;
};




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
}

