/*
 * WordDictionary.h
 *
 *  Created on: Sep 7, 2019
 *      Author: sidd
 */

#ifndef WORDDICTIONARY_H_
#define WORDDICTIONARY_H_

#include <list>
#include <string>
using namespace std;

#define MAX_WORD_LENGTH 50

class CharTrieNode;

class WordDictionary
{
public:
	WordDictionary(string filePath);
	~WordDictionary();
	void load();
	bool getIsSet();
	void printAllWords();
	bool findWordsOfSize(int N, list<string>& wordsFound);
protected:
	bool addWord(char* word);

private:
	string filePath_;
	bool isSet_;
	CharTrieNode* root_;
	int lengthOfBiggestWord_;
	int noOfWords_;
	int noOfWordsOfLength_[MAX_WORD_LENGTH];
};

#endif /* WORDDICTIONARY_H_ */
