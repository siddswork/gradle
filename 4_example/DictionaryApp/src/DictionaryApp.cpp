//============================================================================
// Name        : DictionaryApp.cpp
// Author      : Siddhartha Baidya
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#ifndef WORDDICTIONARY_H_
	#include "WordDictionary.h"
#endif
#include <iostream>
using namespace std;

int main() {
	string filePath = "/Users/sidd/dev/cpp/workspace/Dictionary/Resources/words.txt";
	WordDictionary myDictionary(filePath);
	myDictionary.load();

	cout << "Dictionary is ready for use? " << (myDictionary.getIsSet()?"TRUE":"FALSE") << endl;

	return 0;
}
