//============================================================================
// Name        : CharTrieNode.cpp
// Author      : Siddhartha Baidya
// Version     :
// Copyright   : Your copyright notice
// Description : CharTrieNode in C++, Ansi-style
//============================================================================

#ifndef CHARTRIENODE_H_
	#include "CharTrieNode.h"
#endif

#include <iostream>

vector<char> internalWord_;

CharTrieNode::~CharTrieNode()
{
	for(int i = 0; i < nodes.size(); i++)
	{
		delete nodes.at(i);
	}
}

bool CharTrieNode::addString(char *word)
{
	if(word[0] == '\0')
	{
		CharTrieNode* newNode = new CharTrieNode();
		//newNode->setValue('*');
		newNode->setParent(this);
		nodes.push_back(newNode);
		//cout << "At address [" << newNode << "] storing char [" << newNode->getValue() << "]" << endl;
		return true;
	}
	else
	{
		CharTrieNode* newNode = new CharTrieNode();
		newNode->setValue(word[0]);
		newNode->setParent(this);
		nodes.push_back(newNode);
		//cout << "At address [" << newNode << "] storing char [" << word[0] << "]" << endl;
		return newNode->addString(++word);
	}
}

void CharTrieNode::printAllBranchs(int count)
{
	static vector<char> internalWord_;
	vector<CharTrieNode*>::const_iterator it;
	++count;
	for(it = nodes.begin(); it != nodes.end(); ++it)
	{
		if(((CharTrieNode*)(*it))->getValue() != '*')
		{
			internalWord_.push_back(((CharTrieNode*)(*it))->getValue());
			((CharTrieNode*)(*it))->printAllBranchs(count);
			internalWord_.pop_back();
		}
		else
		{
			for (int i = 0; i < internalWord_.size(); i++)
			{
				cout << internalWord_.at(i);
			}
			cout << endl;
		}
	}
}

void CharTrieNode::getWordsOfSize(int N, list<string>& result)
{
	static vector<char> internalWord_;
	for(vector<CharTrieNode*>::const_iterator it = nodes.begin(); it != nodes.end(); ++it)
	{
		if(N == 0 && ((CharTrieNode*)(*it))->getValue() == '*' && internalWord_.size() > 0)
		{
			string wordFound("");
			for (int i = 0; i < internalWord_.size(); i++)
			{
				wordFound.push_back(internalWord_.at(i));
			}
			result.push_back(wordFound);
		}
		else
		{
			if(!ispunct(((CharTrieNode*)(*it))->getValue()))
			{
				internalWord_.push_back(((CharTrieNode*)(*it))->getValue());
				((CharTrieNode*)(*it))->getWordsOfSize(N-1, result);
				internalWord_.pop_back();
			}
		}
	}
}

