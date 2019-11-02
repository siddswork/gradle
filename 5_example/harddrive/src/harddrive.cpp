//============================================================================
// Name        : harddrive.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#ifndef HARDDRIVE_H_
	#include "harddrive.h"
#endif
#include <iostream>

using namespace std;

const string harddrive::dataInFile("From file");

const char* harddrive::Read(long lba, int size)
{
	return dataInFile.c_str();
}
