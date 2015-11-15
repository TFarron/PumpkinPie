#ifndef _USERS
#define _USERS

#include<string>

using namespace std;

class User
{
private:
	string password,email_addr,real_name;
	char preference,sex;
	//'M' for male, 'F' for female, 'O' for other
	int age;
public:

	static int n; //counter for the amount of users in server 

	friend ostream& operator<< (ostream &out, const User &user);//redefining stream operator 

	string username;
	bool minor;
	//Used for tracking whether users are a minor or not

	User();
	User(string user, string pass, string email, string name, char pref, char new_sex, int new_age);

	~User() {n--;};

	void set_user(string user) {username=user;};
	void set_pass(string pass) {password=pass;};
	void set_email(string email) {email_addr=email;};
	void set_name(string name) {real_name = name;};
	void set_pref(char pref) {preference=pref;};
	void set_sex(char new_sex) {sex = new_sex;};
	void set_age(int new_age) {age = new_age;};

};
#endif