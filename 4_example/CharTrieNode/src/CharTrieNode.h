/*
 * CharTrieNode.h
 *
 *  Created on: Sep 7, 2019
 *      Author: sidd
 */

#ifndef CHARTRIENODE_H_
#define CHARTRIENODE_H_

#include <vector>
#include <list>

using namespace std;

class CharTrieNode
{
public:
	CharTrieNode(): value('*'), parent(NULL) {}
	~CharTrieNode();
	bool addString(char *word);
	void setValue(char ch) { value = ch; }
	char& getValue() { return value; }
	void setParent(CharTrieNode* pParent) { parent = pParent; }
	void printAllBranchs(int count);
	void getWordsOfSize(int N, list<string>& result);
private:
	char value;
	vector<CharTrieNode*> nodes;
	CharTrieNode* parent;
};

#endif /* CHARTRIENODE_H_ */
