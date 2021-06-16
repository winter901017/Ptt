#pragma once
#ifndef MEMBER_H
#define MEMBER_H

#include "User.h"

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

class Member:public User
{
public:
   
	Member(void)
	{
		Permission_level = 1;
	}

};


#endif // !MEMBER_H

