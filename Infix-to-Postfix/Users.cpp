#include "Users.h"
#include <cstddef>

using namespace std;

User :: User()
{
};

User :: User(string user, string pass, string email, string name, char pref, char new_sex, int new_age)
{
	n++;
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
};