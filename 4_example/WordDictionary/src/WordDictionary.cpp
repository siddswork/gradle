//============================================================================
// Name        : WordDictionary.cpp
// Author      : Siddhartha Baidya
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#ifndef CHARTRIENODE_H_
	#include "CharTrieNode.h"
#endif
#ifndef WORDDICTIONARY_H_
	#include "WordDictionary.h"
#endif

#include <iostream>
#include <fstream>
#include <string>

WordDictionary::WordDictionary(string filePath) : filePath_(filePath), isSet_(false), root_(NULL), lengthOfBiggestWord_(0), noOfWords_(0)
{
	for (int i = 0; i< MAX_WORD_LENGTH; i++)
		noOfWordsOfLength_[i] = 0;
}

WordDictionary::~WordDictionary()
{
	if (root_)
		delete root_;
}

bool WordDictionary::getIsSet()
{
	return isSet_;
}

bool WordDictionary::addWord(char* word)
{
	if(root_)
	{
		return root_->addString(word);
	}
	else
	{
		root_ = new CharTrieNode();
		return root_->addString(word);
	}
}

void WordDictionary::load()
{
	ifstream inputFile;
	inputFile.open(filePath_);
	char buffer[1024];

	cout << "Reading from the file" << endl;
	lengthOfBiggestWord_ = 0;
	while(inputFile.good())
	{
		inputFile.getline(buffer, 1024);
		int currentWordLength = strlen(buffer);
		if(currentWordLength==0)
			continue;
		addWord(buffer);

		if(lengthOfBiggestWord_ < currentWordLength)
			lengthOfBiggestWord_ = currentWordLength;

		noOfWordsOfLength_[currentWordLength]++;
		++noOfWords_;
	}
	cout << "Last read words: " << buffer << endl;
	cout << "Number of words read: " << noOfWords_ << endl;
	cout << "Largest word size: " << lengthOfBiggestWord_ << endl;
	for(int i=0; i <= lengthOfBiggestWord_; i++)
		cout << i << ": " << noOfWordsOfLength_[i] << endl;
	inputFile.close();
	isSet_ = true;
}

bool WordDictionary::findWordsOfSize(int N, list<string>& result)
{
	if(!isSet_) return false;
	int initialSize = result.size();

	root_->getWordsOfSize(N, result);

	if(result.size() > initialSize)
	{
		return true;
	}
	return false;
}

void WordDictionary::printAllWords()
{
	root_->printAllBranchs(0);
}
