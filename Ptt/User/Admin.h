#pragma once
#pragma once
#ifndef ADMIN_H
#define ADMIN_H

#include "User.h"

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

class Admin:public User
{
public:

	Admin(void)
	{
		Permission_level = 0;
	}

	
};


#endif // !ADMIN_H

	