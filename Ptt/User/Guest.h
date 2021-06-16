#pragma once
#pragma once
#ifndef GUEST_H
#define GUEST_H

#include "User.h"

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

class Guest:public User
{
public:

	Guest(void)
	{
		Permission_level = 2;
	}

};


#endif // !GUEST_H

