#pragma once
#include <iostream>
#include <vector>
#include <string>
using namespace std;

#define MaxNum 26

//==============================================================================
//TrieNode
typedef struct TrieNode
{
	bool bIsWord;//��ʾ��ǰ�ַ����Ƿ񹹳�һ������.
	int prefixCount;//�Ե�ǰ�ַ���Ϊǰ׺�Ĵ��ĸ���.
	TrieNode* mChild[MaxNum];//��ǰ�ڵ�������ӽڵ�.

	//constructor & destructor.
	TrieNode(bool bWord) : bIsWord(bWord), prefixCount(0)
	{
		for (size_t i = 0; i < MaxNum; i++)
			mChild[i] = nullptr;
	}

	~TrieNode()
	{
		for (size_t i=0; i < MaxNum; i++)
		{
			if (mChild[i] != nullptr)
			{
				delete mChild[i];
				mChild[i] = nullptr;
			}
		}
	}
}TrieNode;

//==============================================================================
//TrieTree
class TrieTree
{
public:
	TrieTree();
	~TrieTree();
	void buildTree(const vector<string>& DataSet);
	void insertNode(string& word);
	TrieNode* findNode(string& word);
private:
	int childIndex(char child) { return child - 'a'; }
	TrieNode* pRoot;
};

//==============================================================================
//Implement.
TrieTree::TrieTree()
{
	pRoot = new TrieNode(false);
	if (pRoot == NULL)
	{
		cout << "alloc root failed!" << endl;
		exit(-1);
	}
}

TrieTree::~TrieTree()
{
	if (pRoot != nullptr) //free the root node.
	{
		delete pRoot;
		pRoot = nullptr;
	}
}

void TrieTree::insertNode(string& word)
{
	TrieNode* pCur = pRoot;
	for (size_t i = 0; i < word.length(); i++)
	{
		int id = childIndex(word[i]);
		if (pCur->mChild[id] == nullptr) //create new TrieNode
			pCur->mChild[id] = new TrieNode(false);

		pCur = pCur->mChild[id];
		pCur->prefixCount++;
	}

	if (pCur != pRoot)
		pCur->bIsWord = true;
}

TrieNode* TrieTree::findNode(string& word)
{
	TrieNode* pCur = pRoot;
	for (size_t i = 0; i < word.length(); i++)
	{
		int id = childIndex(word[i]);
		if (pCur->mChild[id] == nullptr)
			return NULL;
		pCur = pCur->mChild[id];
	}
	return pCur;
}


//�ڲ������������ڵ㲻���ڻᴴ���ýڵ�.
void TrieTree::buildTree(const vector<string>& DataSet)
{
	for (auto element : DataSet)
		insertNode(element);
}