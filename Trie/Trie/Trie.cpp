#include "Trie.h"

int main()
{
	vector<string> DataSet = { "hello", "world", "he", "test", "npu" };

	TrieTree* pTree = new TrieTree();
	pTree->buildTree(DataSet);

	TrieNode* pNode = pTree->findNode(string("test"));
	cout << pNode->bIsWord << endl; //true

	return 0;
}